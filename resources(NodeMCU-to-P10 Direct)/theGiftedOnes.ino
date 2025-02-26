#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <DMDESP.h>
#include <fonts/Mono5x7.h>
#include "PageIndex.h" // Web UI Page

// WiFi Config
const char* ssid = "NODE_MCU_GROUP_10";
const char* password = "thegiftedones";
ESP8266WebServer server(80);

// P10 Display Config
#define DISPLAYS_WIDE 1
#define DISPLAYS_HIGH 1
DMDESP Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);

// Product List Variables
String productList = "";
unsigned long lastUpdate = 0;
static uint32_t scrollX = 0;
static int productIndex = 0;

// Web Page Handling
void handleRoot() {
    server.send_P(200, "text/html", MAIN_page);
}

// Receiving Product List
void handle_Incoming_Data() {
    productList = server.arg("ProductList");
    server.send(200, "text/plain", "Updated Display!");

    write_String_to_EEPROM(0, productList);
    productIndex = 0; // Reset to first product
    scrollX = 0; // Reset scrolling
}

// Scrolling Text Function (Center Text)
void Scrolling_Text(uint8_t scrolling_speed) {
    static uint32_t pM;

    if (productList.length() == 0) return; // No products to display

    // Get the current product from the list
    int nextComma = productList.indexOf(',', productIndex);
    String product = (nextComma != -1) ? productList.substring(productIndex, nextComma) : productList.substring(productIndex);

    int screenWidth = Disp.width();
    int textWidth = Disp.textWidth(product.c_str());
    int y = (Disp.height() - 7) / 2; // Center vertically

    if ((millis() - pM) > scrolling_speed) { 
        pM = millis();
        if (scrollX < textWidth + screenWidth) {
            Disp.clear();
            Disp.drawText(screenWidth - scrollX, y, product.c_str());
            scrollX++;
        } else {
            scrollX = 0; // Reset scrolling
            productIndex = (nextComma != -1) ? nextComma + 1 : 0; // Move to next product
        }
    }
}

// EEPROM Write
void write_String_to_EEPROM(int addr, String data) {
    int _size = data.length();
    for (int i = 0; i < _size; i++) {
        EEPROM.write(addr + i, data[i]);
    }
    EEPROM.write(addr + _size, '\0');
    EEPROM.commit();
}

// EEPROM Read
String read_String_from_EEPROM(int addr) {
    char data[300];
    int len = 0;
    unsigned char k = EEPROM.read(addr);
    while (k != '\0' && len < 300) {    
        k = EEPROM.read(addr + len);
        data[len] = k;
        len++;
    }
    data[len] = '\0';
    return String(data);
}

void setup() {
    Serial.begin(74880);
    Serial.println("ESP8266 Booting...");

    EEPROM.begin(512);
    Disp.start();
    Disp.setBrightness(50);
    Disp.setFont(Mono5x7);

    WiFi.softAP(ssid, password);
    Serial.println("ESP8266 AP started! IP: " + WiFi.softAPIP().toString());

    server.on("/", handleRoot);
    server.on("/updateList", handle_Incoming_Data);
    server.begin();
    Serial.println("HTTP server started");

    productList = read_String_from_EEPROM(0);
}

void loop() {
    server.handleClient();
    Scrolling_Text(50); // Adjust scrolling speed
    Disp.loop();
}

# P10 LED Matrix Display

## Overview
This project is developed as part of the **IN4300 Embedded Systems** module. The goal is to build an IoT-based system that can display prices on three **P10 LED matrix displays**. The prices are fetched from a web application, which provides a facility for manual input of values.

### Project Description
Supermarkets frequently update prices due to promotions, supply chain changes, and demand fluctuations. Traditional price updates require manual labor, making the process time-consuming and error-prone. This project aims to develop a **real-time, dynamic price display system** using P10 LED panels, reducing manual effort and improving efficiency. Prices are entered via a web application and displayed wirelessly on LED matrices through an embedded system.

## Features
✅ **Real-time Price Display** – Fetches and updates prices dynamically.  
✅ **Three P10 LED Matrix Panels** – Displays values across multiple screens.  
✅ **Web Application Integration** – Allows manual input of prices.  
✅ **Embedded System Implementation** – Utilizes microcontrollers for control and communication.  

## Components Used
### Hardware Components
| Component                | Quantity | Description                                      |
|-------------------------|----------|-------------------------------------------------|
| **P10 LED Display Panels** | 3        | Displays item prices dynamically               |
| **Arduino Mega 2560**   | 1        | Microcontroller for processing and control     |
| **ESP8266 Wi-Fi Module**| 1        | Handles wireless communication                 |
| **Power Supply (5V)**   | 1        | Provides power to P10 panels                   |
| **Breadboard & Jump Wires** | -  | Used for circuit connections                   |
| **Laptop/PC**           | 1        | Hosts the local web server for managing prices |

### Software Components
| Component              | Description                                         |
|------------------------|-----------------------------------------------------|
| **Web Application**    | Allows staff to enter and manage prices           |
| **Database (MySQL/Firebase)** | Stores product information and prices      |
| **Arduino IDE**        | Used for programming the Arduino Mega             |
| **ESP8266 Firmware**   | Enables Wi-Fi connectivity and real-time data     |
| **WebSocket/MQTT**     | Ensures efficient real-time communication         |

## System Architecture
1. **Web Application**:
   - Interface for entering and updating prices.
   - Sends data to the microcontroller via API.
2. **Embedded System**:
   - Fetches price data from the web app.
   - Controls P10 LED Matrix modules.
3. **Display Mechanism**:
   - Updates values dynamically on LED matrices.

### System Workflow
📌 **Web App:** Staff inputs prices into the system.  
📌 **Database:** Prices are stored in MySQL/Firebase.  
📌 **ESP8266:** Retrieves updated prices via Wi-Fi.  
📌 **Arduino Mega:** Processes and sends data to LED panels.  
📌 **P10 LED Panels:** Dynamically display prices in real time.  

## Circuit Diagram
![Circuit Diagram](path/to/your/circuit-diagram.png)  
(*Please upload the circuit diagram image and update the path accordingly*)

## Installation & Setup
```sh
# Clone the repository
git clone https://github.com/your-repo/p10-led-matrix.git

# Set up the microcontroller environment
# Configure Wi-Fi and network settings
# Deploy the web application and connect it to the microcontroller
```

## Contributors
| Name | Student ID |
|--------------------------|------------|
| **Dasanayaka D.M.D.G.**  | 204030C  |
| **Perera A.P.D.**        | 204154J  |
| **Piyumal J.K.P.**       | 204162G  |
| **Samararathna B.S.**    | 204184B  |

## License
📜 This project is licensed under the **MIT License**.



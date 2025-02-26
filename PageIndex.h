#ifndef PAGE_INDEX_H
#define PAGE_INDEX_H

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        html { font-family: Arial; text-align: center; margin: 0 auto; }
        h1 { font-size: 2rem; color: #2980b9; }
        table { width: 90%; margin: auto; border-collapse: collapse; }
        th, td { padding: 10px; border: 1px solid #ddd; text-align: center; }
        .inputBox { width: 90%; max-width: 400px; padding: 10px; font-size: 1.2rem; }
        .button { padding: 10px 15px; font-size: 16px; cursor: pointer; border: none; }
        .addButton { background: #4CAF50; color: white; }
        .deleteButton { background: #e74c3c; color: white; }
    </style>
</head>

<body>
    <h1>P10 LED Display Controller</h1>
    <h2>Manage Products</h2>
    
    <input type="text" id="productName" class="inputBox" placeholder="Enter Product Name">
    <input type="text" id="price" class="inputBox" placeholder="Enter Price">
    <button class="button addButton" onclick="addProduct()">Add Product</button>
    
    <h3>Product List</h3>
    <table>
        <thead>
            <tr><th>Product</th><th>Price</th><th>Action</th></tr>
        </thead>
        <tbody id="productTable"></tbody>
    </table>

    <button class="button" onclick="sendData()">Update Display</button>

    <script>
        let products = [];

        function addProduct() {
            let name = document.getElementById("productName").value;
            let price = document.getElementById("price").value;
            if (!name || !price) return alert("Enter both product name and price!");

            products.push(name + " - $" + price);
            updateTable();
        }

        function deleteProduct(index) {
            products.splice(index, 1);
            updateTable();
        }

        function updateTable() {
            let table = document.getElementById("productTable");
            table.innerHTML = "";
            products.forEach((p, i) => {
                table.innerHTML += `<tr><td>${p.split(" - ")[0]}</td><td>${p.split(" - ")[1]}</td>
                                    <td><button class="button deleteButton" onclick="deleteProduct(${i})">Delete</button></td></tr>`;
            });
        }

        function sendData() {
            let productList = products.join(",");
            let xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4) alert("Updated Successfully!");
            };
            xhttp.open("GET", "/updateList?ProductList=" + encodeURIComponent(productList), true);
            xhttp.send();
        }
    </script>
</body>
</html>
)=====";

#endif // PAGE_INDEX_H

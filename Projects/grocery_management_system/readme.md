# 🛒 Grocery Management System (OOP Assignment)

## 🎯 Learning Objective
The purpose of this question is to strengthen your understanding of **Object-Oriented Programming (OOP) in C++**, including:

- Classes and Objects  
- Encapsulation and Data Hiding  
- Constructors and Destructors  
- Operator Overloading  
- Friend Functions  
- Dynamic Memory Management  
- Menu-driven Applications  

---

## 📌 Problem Statement
You are required to implement a **Grocery Management System** using **only OOP principles** in C++.  
The system should consist of the following classes:

---

### 🔹 Class Item
**Attributes (Private):**
- `string name`
- `string barcode` (unique identifier)
- `double price`
- `int quantity`

**Behaviors (Public):**
- Constructor(s) and Destructor
- `void changeItemName(string newName)`
- `void changeItemPrice(double newPrice)`
- `void addQuantity(int qty)`
- `void printItemDetails() const`
- **Operator Overloading:**
  - `operator==` → Compare items by barcode
  - `operator+` → Increase quantity of the same item

---

### 🔹 Class Inventory
**Attributes (Private):**
- A dynamic collection of `Item` objects

**Behaviors (Public):**
- Constructor(s) and Destructor
- `void addItem(const Item& item)`
- `void removeItem(string barcode)`
- `void printInventory() const`
- **Operator Overloading:**
  - `operator[]` → Access an item by index
  - `friend ostream& operator<<(ostream&, const Inventory&)` → Print inventory

**Note:** If an item already exists, only update its quantity instead of creating a duplicate.

---

### 🔹 Class Order
**Attributes (Private):**
- A collection of `Item` objects (specific to the order)
- Corresponding quantities
- `double preTaxPrice`
- `double tax`
- `double totalPrice`
- `string paymentMethod`
- `string status` (Pending / Completed)

**Behaviors (Public):**
- Constructor(s) and Destructor
- `void addItemInOrder(const Item& item, int qty)`
- `void removeItemFromOrder(string barcode, int qty)`
- `void printOrderDetails() const`
- `void calculateBill()`
- **Operator Overloading:**
  - `operator+=` → Add item to the order
  - `operator-=` → Remove item from the order

**Notes:**
- Tax = **15%** for cash, **5%** for card  
- User can modify items until the order is completed

---

### 🔹 Class Store
**Attributes (Private):**
- `Inventory inventory`
- A collection of `Order` objects (pending orders)
- A collection of completed orders (order history)
- `double totalRevenue`

**Behaviors (Public):**
- Constructor(s) and Destructor
- `void createOrder()`
- `void removeOrder(int orderIndex)`
- `void printSortedOrders()` (sorted by total price)
- `void calculateRevenue()`
- `void run()` → Menu-driven interface (loops until user exits)

---

## 📋 Main Menu Requirements
The program must present a menu with the following options:

1. Add/Remove items in inventory  
2. Create new order  
3. Modify pending order  
4. Complete an order  
5. View inventory  
6. View pending orders (sorted)  
7. View completed orders  
8. Calculate total revenue  
9. Exit program  

After any action, the menu should reappear until the user chooses to exit.

---

## ⚠️ Additional Notes
1. Use **constructors and destructors** to manage dynamic memory.  
2. Use **operator overloading and friend functions** where appropriate.  
3. Ensure proper **input validation**.  
4. You may add more attributes/functions if necessary.  
5. The code must be **modular, readable, and follow OOP principles strictly** (no structs, no raw linked lists).  

---

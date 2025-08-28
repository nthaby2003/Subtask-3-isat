#include <iostream>
#include <string>
#include <iomanip> // for formatting output

const int MAX_ORDERS = 50;
const float PRICE_PER_MAGWINYA = 5.25f;

// Arrays to store order data
std::string orderIds[MAX_ORDERS];
std::string customerNames[MAX_ORDERS];
int numMagwinyas[MAX_ORDERS];
float totalCosts[MAX_ORDERS];

// Keep track of how many orders there are
int orderCount = 10;

// Step 1: Initialize first 10 sample orders
void initializeData() {
    std::string ids[] = {"101","102","103","104","105","106","107","108","109","110"};
    std::string names[] = {"Thabo","Lerato","Nompula","Sipho","Bongani","Lindwe","Jabulani","Ayanda","Kgosi","Refilwe"};
    int mags[] = {3,5,2,4,6,1,3,7,2,4};

    for (int i = 0; i < 10; i++) {
        orderIds[i] = ids[i];
        customerNames[i] = names[i];
        numMagwinyas[i] = mags[i];
        totalCosts[i] = mags[i] * PRICE_PER_MAGWINYA; // Calculate total cost
    }
}

// Step 2: Display menu
void displayMenu() {
    std::cout << "\n--- Magwinya Order Menu ---\n";
    std::cout << "1. Add a new order\n";
    std::cout << "2. View all orders\n";
    std::cout << "3. Find order by ID\n";
    std::cout << "4. Show total revenue\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

// Step 3: Add a new order
void addOrder() {
    if (orderCount >= MAX_ORDERS) {
        std::cout << "Order limit reached.\n";
        return;
    }

    std::cin.ignore(); // clear input buffer
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerNames[orderCount]);

    std::cout << "Enter number of Magwinyas: ";
    std::cin >> numMagwinyas[orderCount];

    totalCosts[orderCount] = numMagwinyas[orderCount] * PRICE_PER_MAGWINYA;
    orderIds[orderCount] = std::to_string(101 + orderCount);

    std::cout << "Order added! Order ID: " << orderIds[orderCount] << "\n";

    orderCount++;
}

// Step 4: Display all orders
void displayAllOrders() {
    if (orderCount == 0) {
        std::cout << "No orders found.\n";
        return;
    }

    std::cout << "\n--- All Orders ---\n";
    std::cout << std::setw(10) << "Order ID"
              << std::setw(15) << "Customer"
              << std::setw(18) << "Magwinyas"
              << std::setw(15) << "Total Cost\n";

    for (int i = 0; i < orderCount; ++i) {
        std::cout << std::setw(10) << orderIds[i]
                  << std::setw(15) << customerNames[i]
                  << std::setw(18) << numMagwinyas[i]
                  << std::setw(15) << std::fixed << std::setprecision(2) << totalCosts[i] << "\n";
    }
}

// Step 5: Find an order by ID
void findOrder() {
    std::string id;
    std::cout << "Enter Order ID to search: ";
    std::cin >> id;

    for (int i = 0; i < orderCount; ++i) {
        if (orderIds[i] == id) {
            std::cout << "\nOrder Found!\n";
            std::cout << "Customer: " << customerNames[i] << "\n";
            std::cout << "Magwinyas: " << numMagwinyas[i] << "\n";
            std::cout << "Total Cost: R" << std::fixed << std::setprecision(2) << totalCosts[i] << "\n";
            return;
        }
    }
    std::cout << "Order not found.\n";
}

// Step 6: Calculate and show total revenue
void showTotalRevenue() {
    float total = 0;
    for (int i = 0; i < orderCount; ++i) {
        total += totalCosts[i];
    }
    std::cout << "Total revenue: R" << std::fixed << std::setprecision(2) << total << "\n";
}

// Step 7: Main function to run the program
int main() {
    initializeData(); // Load sample data

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: addOrder(); break;
            case 2: displayAllOrders(); break;
            case 3: findOrder(); break;
            case 4: showTotalRevenue(); break;
            case 5: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
}

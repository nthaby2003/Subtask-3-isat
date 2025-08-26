#include <iostream>
#include <string>
#include <iomanip> // For formatting output with decimals

// Constants for our program
const int MAX_ORDERS = 50;
const float PRICE_PER_MAGWINYA = 5.25f;

// We use parallel arrays to store the order data.
// This means that data for a single order is stored at the same index in each array.
// For example, orderIds[0], customerNames[0], numMagwinyas[0], and totalCosts[0] all belong to the first order.
std::string orderIds[MAX_ORDERS];
std::string customerNames[MAX_ORDERS];
int numMagwinyas[MAX_ORDERS];
float totalCosts[MAX_ORDERS];

// A variable to keep track of the number of orders currently in the system.
// We start at 10 because the problem states we need to initialize the first 10 elements.
int orderCount = 10;

// Function to initialize the first 10 orders with sample data from the provided document.
void initializeData() {
    orderIds[0] = "101"; customerNames[0] = "Thabo"; numMagwinyas[0] = 3; totalCosts[0] = 15.75f;
    orderIds[1] = "102"; customerNames[1] = "Lerato"; numMagwinyas[1] = 5; totalCosts[1] = 30.50f;
    orderIds[2] = "103"; customerNames[2] = "Nompula"; numMagwinyas[2] = 2; totalCosts[2] = 10.00f;
    orderIds[3] = "104"; customerNames[3] = "Sipho"; numMagwinyas[3] = 4; totalCosts[3] = 22.00f;
    orderIds[4] = "105"; customerNames[4] = "Bongani"; numMagwinyas[4] = 6; totalCosts[4] = 40.25f;
    orderIds[5] = "106"; customerNames[5] = "Lindwe"; numMagwinyas[5] = 1; totalCosts[5] = 5.50f;
    orderIds[6] = "107"; customerNames[6] = "Jabulani"; numMagwinyas[6] = 3; totalCosts[6] = 18.00f;
    orderIds[7] = "108"; customerNames[7] = "Ayanda"; numMagwinyas[7] = 7; totalCosts[7] = 12.75f; // This value seems low, but we will use the provided data.
    orderIds[8] = "109"; customerNames[8] = "Kgosi"; numMagwinyas[8] = 2; totalCosts[8] = 28.00f;
    orderIds[9] = "110"; customerNames[9] = "Refilwe"; numMagwinyas[9] = 4; totalCosts[9] = 24.50f;

    // The rest of the array elements are not initialized in the problem.
    // For simplicity and clarity for a Level 3 student, we will not explicitly initialize the remaining 40 to 0.
    // The `orderCount` variable handles this by ensuring we only ever access the initialized part of the arrays.
}

// Function to display the main menu to the user.
void displayMenu() {
    std::cout << "\n--- Magwinya Magic Order System Menu ---\n";
    std::cout << "1. Add a new order\n";
    std::cout << "2. Display all orders\n";
    std::cout << "3. Find an order by Order ID\n";
    std::cout << "4. Calculate and display total revenue\n";
    std::cout << "5. Exit the program\n";
    std::cout << "--------------------------------------\n";
    std::cout << "Enter your choice: ";
}

// Function to add a new order to the system.
void addOrder() {
    if (orderCount >= MAX_ORDERS) {
        std::cout << "Sorry, the system is full. Cannot add more orders.\n";
        return;
    }

    // Get order details from the user.
    std::cout << "Enter customer name: ";
    std::cin.ignore(); // Clear the input buffer before reading a line
    std::getline(std::cin, customerNames[orderCount]);

    std::cout << "Enter number of Magwinyas ordered: ";
    std::cin >> numMagwinyas[orderCount];

    // Calculate the total cost based on the number of magwinyas.
    totalCosts[orderCount] = numMagwinyas[orderCount] * PRICE_PER_MAGWINYA;
    
    // Generate a new Order ID.
    orderIds[orderCount] = std::to_string(101 + orderCount);

    std::cout << "Order added successfully! New Order ID is: " << orderIds[orderCount] << "\n";

    // Increment the order count.
    orderCount++;
}

// Function to display all current orders in a formatted table.
void displayAllOrders() {
    if (orderCount == 0) {
        std::cout << "No orders to display.\n";
        return;
    }

    std::cout << "\n--- All Orders ---\n";
    std::cout << std::setw(12) << "Order ID" << std::setw(15) << "Customer" 
              << std::setw(20) << "Magwinyas Ordered" << std::setw(15) << "Total Cost\n";
    
    // Loop through the arrays and print the details for each order.
    for (int i = 0; i < orderCount; ++i) {
        std::cout << std::setw(12) << orderIds[i] << std::setw(15) << customerNames[i] 
                  << std::setw(20) << numMagwinyas[i] << std::setw(15) << std::fixed << std::setprecision(2) << totalCosts[i] << "\n";
    }
}

// Function to find and display a specific order by its ID.
void findOrder() {
    std::string searchId;
    std::cout << "Enter the Order ID to find: ";
    std::cin >> searchId;

    bool found = false;
    for (int i = 0; i < orderCount; ++i) {
        if (orderIds[i] == searchId) {
            std::cout << "\nOrder Found!\n";
            std::cout << "Order ID: " << orderIds[i] << "\n";
            std::cout << "Customer: " << customerNames[i] << "\n";
            std::cout << "Magwinyas Ordered: " << numMagwinyas[i] << "\n";
            std::cout << "Total Cost: R" << std::fixed << std::setprecision(2) << totalCosts[i] << "\n";
            found = true;
            break; // Stop searching once the order is found.
        }
    }

    if (!found) {
        std::cout << "Error: Order with ID " << searchId << " not found.\n";
    }
}

// Function to calculate and display the total revenue.
void calculateTotalRevenue(89){
    float totalRevenue = 0.0f;
    for (int i = 0; i < orderCount; ++i) {
        totalRevenue += totalCosts[i];
    }

    std::cout << "\n--- Total Revenue ---\n";
    std::cout << "The total revenue from all orders is: R" << std::fixed << std::setprecision(2) << totalRevenue << "\n";
}

int main() {
    // First, we initialize the data for the first 10 orders.
    initializeData();
    
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                displayAllOrders();
                break;
            case 3:
                findOrder();
                break;
            case 4:
                calculateTotalRevenue();
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

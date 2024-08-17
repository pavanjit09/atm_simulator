#include <iostream>
#include <fstream>

void displayMenu() {
    std::cout << "ATM Simulator\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
}

double readBalance() {
    std::ifstream file("balance.txt");
    double balance;
    if (file >> balance) {
        file.close();
        return balance;
    }
    else {
        return 0.0;
    }
}

void writeBalance(double balance) {
    std::ofstream file("balance.txt");
    file << balance;
    file.close();
}

int main() {
    int choice;
    double amount, balance;

    balance = readBalance();

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Current balance: $" << balance << '\n';
            break;
        case 2:
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;
            balance += amount;
            writeBalance(balance);
            std::cout << "Deposit successful. New balance: $" << balance << '\n';
            break;
        case 3:
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;
            if (amount <= balance) {
                balance -= amount;
                writeBalance(balance);
                std::cout << "Withdrawal successful. New balance: $" << balance << '\n';
            }
            else {
                std::cout << "Insufficient funds.\n";
            }
            break;
        case 4:
            std::cout << "Thank you for using the ATM.\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}


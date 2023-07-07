/******************************************************************************

*******************************************************************************/
#include <iostream>

const double INITIAL_BALANCE = 2149.36;
const double FEE = 26.50;
const double MIN_BALANCE = -349.56;
const int MAX_TRANSACTIONS = 6;

int main() {
    double balance = INITIAL_BALANCE;
    int transactionCount = 0;

    while (transactionCount < MAX_TRANSACTIONS) {
        double transactionAmount;
        std::cout << "Enter transaction amount: ";
        std::cin >> transactionAmount;

        // Check if transaction will take the balance to a negative amount
        if (balance + transactionAmount < 0) {
            // Apply fee before deducting transaction amount
            balance -= FEE;
            if (balance < MIN_BALANCE) {
                std::cout << "Insufficient funds. Your current balance is: $" << balance << std::endl;
                break;
            }
        }

        balance += transactionAmount;
        if (balance < MIN_BALANCE) {
            std::cout << "Insufficient funds. Your current balance is: $" << balance << std::endl;
            break;
        }

        transactionCount++;
    }

    std::cout << "Final balance: $" << balance << std::endl;

    return 0;
}

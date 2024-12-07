// calculator 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Calculator {
private:
    std::vector<std::string> history; // Store calculation history

public:
    void addHistory(const std::string& entry) {
        history.push_back(entry);
    }

    void saveHistoryToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error: Could not open file for writing.\n";
            return;
        }
        for (const auto& entry : history) {
            outFile << entry << "\n";
        }
        std::cout << "History saved to " << filename << "\n";
    }

    void loadHistoryFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error: Could not open file for reading.\n";
            return;
        }
        history.clear();
        std::string line;
        while (std::getline(inFile, line)) {
            history.push_back(line);
        }
        std::cout << "History loaded from " << filename << "\n";
    }

    void displayHistory() {
        std::cout << "\nCalculation History:\n";
        for (const auto& entry : history) {
            std::cout << entry << "\n";
        }
    }

    void calculate() {
        char operation;
        double num1, num2;

        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> operation;

        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter second number: ";
        std::cin >> num2;

        double result;
        std::string record;

        switch (operation) {
        case '+':
            result = num1 + num2;
            record = std::to_string(num1) + " + " + std::to_string(num2) + " = " + std::to_string(result);
            break;
        case '-':
            result = num1 - num2;
            record = std::to_string(num1) + " - " + std::to_string(num2) + " = " + std::to_string(result);
            break;
        case '*':
            result = num1 * num2;
            record = std::to_string(num1) + " * " + std::to_string(num2) + " = " + std::to_string(result);
            break;
        case '/':
            if (num2 == 0) {
                std::cerr << "Error: Division by zero is undefined.\n";
                return;
            }
            result = num1 / num2;
            record = std::to_string(num1) + " / " + std::to_string(num2) + " = " + std::to_string(result);
            break;
        default:
            std::cerr << "Invalid operation!\n";
            return;
        }

        std::cout << "Result: " << result << "\n";
        addHistory(record);
    }
};

int main() {
    Calculator calc;
    int choice;
    std::string filename = "calc_history.txt";

    do {
        std::cout << "\n=== Command-Line Calculator ===\n";
        std::cout << "1. Perform Calculation\n";
        std::cout << "2. View Calculation History\n";
        std::cout << "3. Save History to File\n";
        std::cout << "4. Load History from File\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            calc.calculate();
            break;
        case 2:
            calc.displayHistory();
            break;
        case 3:
            calc.saveHistoryToFile(filename);
            break;
        case 4:
            calc.loadHistoryFromFile(filename);
            break;
        case 5:
            std::cout << "Exiting... Goodbye!\n";
            break;
        default:
            std::cerr << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}





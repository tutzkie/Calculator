#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    char op;
    double num1;
    double num2;
    double result;

    std::cout << "*****************CALCULATOR*****************\n";

    // Get and validate the operator
    do {
        std::cout << "Enter either (+ - * /): ";
        std::cin >> op;

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            std::cout << "Invalid operation. Please enter one of (+ - * /).\n";
        }

    } while (op != '+' && op != '-' && op != '*' && op != '/');

    // Function to get a valid number
    auto getNumber = [](const std::string& prompt) -> double {
        double num;
        while (true) {
            std::cout << prompt;
            std::cin >> num;

            // Check if the input is a valid number
            if (!std::cin.fail()) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                return num;
            }

            // Clear error flag and ignore bad input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a numerical value.\n";
        }
    };

    num1 = getNumber("Enter number 1: ");
    num2 = getNumber("Enter number 2: ");

    // Perform the calculation
    switch (op) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << result << '\n';
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
            } else {
                result = num1 / num2;
                std::cout << "Result: " << result << '\n';
            }
            break;
    }

    std::cout << "*****************************************\n";

    return 0;
}

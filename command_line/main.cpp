#include <iostream>

int main(int argument_amount, char* argument[]){
    // Displays each argument given on its own line.
    if (argument_amount > 1) {
        for (int i = 1; i < argument_amount; i++) {
            std::cout << argument[i] << std::endl;
        }
    } else {
        std::cout << "No arguments given!" << std::endl;
    }
    return 0;
}
#include <iostream>
#include <sstream>

using namespace std::string_literals;

void command_input(){
    auto letter = "*"s;
    auto first_number = -1;
    auto second_number = -1;
    std::string user_input;

    std::cout << "Enter a command: " << std::endl;
    getline(std::cin,user_input);

    std::stringstream ss;
    ss << user_input;

    // Extract fist string
    ss >> letter;

    if (letter.length()>1) {
        // it must be text
        std::cout << "You entered some text." << std::endl;
    } else {
        // possible 'I', 'L', 'E', 'D', or 'Q' commands
        std::cout << "I think you are a command" << std::endl;

        // extract number
        ss >> first_number;
        if (!ss.fail()) {
            std::cout << "You have a starting number!" << std::endl;

            // extract second number
            ss >> second_number;
            if (!ss.fail()) {
                // must be a command
                std::cout << "You have an ending number!" << std::endl;
                std::cout << "I'll auusme you are a valid command." << std::endl;
            } else {
                std::cout << "You didn't have an ending number." << std::endl;
                std::cout << "I'll still assume you are a valid command." << std::endl;
            }
        } else {
            // didn't get a number, but could be a command
            // if the entire input was only one character
            if (user_input.length() == 1) {
                std::cout << "I'll assume you are a command!" << std::endl;
            } else {
                std::cout << "You must be text instead." << std::endl;
            }
        }
    }

    ss >> letter >> first_number >> second_number;

    std::cout << "Command: " << letter << std::endl;
    std::cout << "First: " << first_number << std::endl;
    std::cout << "Second: " << second_number << std:: endl;
}

int main(){
    command_input();
    return 0;
}
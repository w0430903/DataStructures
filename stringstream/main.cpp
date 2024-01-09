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
    } else {
        // possible 'I', 'L', 'E', 'D', or 'Q' commands
        // extract number
        ss >> first_number;
        if (!ss.fail()) {
            // extract second number
            ss >> second_number;
            if (!ss.fail()) {
                // must be a command
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
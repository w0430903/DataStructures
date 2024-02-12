#include <iostream>

#include "text_editor.h"

int main(int argc, char* argv[]) {
    TextEditor editor(std::cin,std::cout);
    // Check to see if there are a valid number of arguments.
    if (argc == 2){
        editor.main_app(argv[1]);
    } else {
        std::cout << "Invalid number of arguments." << std::endl;

        if (argc < 2){
            std::cout << "Enter the name of the file you want to edit." << std::endl;
        } else if (argc > 2) {
            std::cout << "Too many arguments!" << std::endl;
        }
    }
    return 0;
}

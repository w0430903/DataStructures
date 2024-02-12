#ifndef ASSIGNMENT1_TEXT_EDITOR_H
#define ASSIGNMENT1_TEXT_EDITOR_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "linked_list.h"

using namespace std::string_literals;
struct COMMAND_LENGTH {
    int ONE = 1;
    int TWO = 2;
    int THREE = 3;
};

class TextEditor {
private:
    static const std::string END_VALUE;
    std::istream& _cin;
    std::ostream& _cout;
    std::string _input;
    std::string _letter = "*"s;
    std::string _valid_chars = "ILEDQH";
    std::string _file_name;
    LinkedList _list;
    int _first_number = -1;
    int _second_number = -1;
    int _current_line = 0;
    int _command_length;
    bool _is_valid;
public:
    explicit TextEditor(std::istream& in, std::ostream& out);
    int main_app(std::string file_name);
    bool verify_input(std::string input);
    void valid_char(char letter);
    void file_load(std::string file_name);
    void editor();
    void execute_command();
    void l_commands();
    void e_commands();
    void d_commands();
    void i_commands();
    void h_commands();
};


#endif //ASSIGNMENT1_TEXT_EDITOR_H

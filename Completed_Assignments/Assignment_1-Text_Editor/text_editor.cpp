
#include "text_editor.h"
#include "linked_list.h"


const std::string TextEditor::END_VALUE = "Q";

using std::endl;

TextEditor::TextEditor(std::istream &in, std::ostream &out): _cin(in), _cout(out) {}

int TextEditor::main_app(std::string file_name) {
    _list = LinkedList();
    file_load(file_name);

    _current_line = _list.list_length();
    _cout << "--- Text Editor --- \n-------------------" << endl;
    _cout << "Enter 'H' to display help for commands.\n" << endl;
    _list.display();

    editor();

    return 0;
}

void TextEditor::file_load(std::string file_name) {
    std::string line;
    std::ifstream text_file{file_name};

    // If file doesn't exist, make a new file. Give error if new file could not be made.
    if (!text_file) {
        _cout << file_name << " file does not exist. Making new file." << endl;
        std::ofstream out_file{file_name};
        out_file.close();
        std::ifstream text_file{file_name};
        if (!text_file) {
            std::cerr << "File could not be created or read. Ending Program." << endl;
            return;
        }
    }
    // Fill linked list.
    while (std::getline(text_file,line)){
        _list.insert(line+"\n");
    }

    _file_name = file_name;
    text_file.close();
}

void TextEditor::editor() {
    // This is where the user enters their command.
    // Program will execute methods if the appropriate commands are entered.
    while (_input != END_VALUE){
        if (_current_line > _list.list_length()) { _current_line = _list.list_length(); }

        _cout << std::to_string(_current_line + 1) << ">>";
        std::getline(_cin,_input);

        if(verify_input(_input)){
            _first_number--;
            _second_number--;
            execute_command();
        } else {
            _input += "\n";
            _list.insert(_input,_current_line);
            _current_line++;
        }
        _first_number = -1;
        _second_number = -1;
    }

    _cout << "Exiting Editor" << endl;
}


bool TextEditor::verify_input(const std::string input) {
    std::stringstream ss;
    ss << input;
    ss >> _letter;

    // After checking if _letter is valid, checks if the first number and/or second number has been input.
    // Command length is used for Delete command and Insert command.
    valid_char(input[0]);
    if (_letter.length()>1 || !_is_valid){
        return false;
    } else {
        ss >> _first_number;
        if (!ss.fail()){
            ss >> _second_number;
            if (!ss.fail()){ _command_length = 3;
            } else { _command_length = 2; }
        } else {
            if (input.length() == 1){ _command_length = 1; }
        }
    }
    return true;
}

void TextEditor::valid_char(char letter) {
    // Check to see if _letter is a valid command letter
    for (char validChar : _valid_chars) {
        if (letter == validChar) {
            _is_valid = true;
            break;
        } else {
            _is_valid = false;
        }
    }
}

void TextEditor::execute_command() {
    if (_letter == "I") {
        i_commands();
    } else if (_letter == "L") {
        l_commands();
    } else if (_letter == "E") {
        e_commands();
    } else if (_letter == "D") {
        d_commands();
    } else if (_letter == "H") {
        h_commands();
    }
}

void TextEditor::l_commands() {
    _list.display(_first_number, _second_number);
}

void TextEditor::e_commands()   {
    _list.save_file(_file_name);
    _input = "Q";
}

void TextEditor::d_commands() {
    if (_command_length < 2) {
        _list.delete_line((_current_line));
    } else {
        _list.delete_line(_first_number,_second_number);
    }
}

void TextEditor::i_commands() {
    if (_list.list_length() < _first_number) {
        _cout << "Invalid position. File has a length of: " << std::to_string(_list.list_length()) << endl;
        return;
    }

    if (_command_length == 1 && _current_line > 0) {
            _current_line--;
    } else if (_command_length > 1) {
        _current_line = _first_number;
    }
}

void TextEditor::h_commands() {
    _cout << "L - Display all text lines. Include one number to show one line, or two to show multiple lines." << endl;
    _cout << "D - Delete currently selected line. Include one number to delete one line, or two to delete multiple lines." << endl;
    _cout << "I - Changes currently selected line. Include a number to select a specific line." << endl;
    _cout << "E - Saves your changes to file and exits the program." << endl;
    _cout << "Q - Exits the program.\n" << endl;
}





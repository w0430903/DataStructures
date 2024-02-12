#include "linked_list.h"
#include <fstream>

LinkedList::LinkedList() : _start(nullptr), _length(0) {}

void LinkedList::insert(const std::string& str, int position) {
    auto* new_node = new Node(str);
    auto* temp = _start;

    if (position > _length) {
        std::cout << "Invalid position." << std::endl;
        return;
    }
    // Defaults to inserting at the end of the list.
    // Otherwise, will insert at given position.
    if (_start == nullptr || position == 0) {
        new_node->_next = _start;
        _start = new_node;
    } else if (position <= -1) {
        while (temp->_next != nullptr) {
            temp = temp->_next;
        }
        temp->_next = new_node;
    } else {
        for (int i = 0; i < position-1; i++){
            temp = temp->_next;
        }

        new_node->_next = temp->_next;
        temp->_next = new_node;
    }
    ++_length;
}

void LinkedList::delete_line(int first_line, int second_line) {
    // These first three if statements check to make sure delete command is given valid number(s)
    if (_start == nullptr) { std::cout << "Nothing to delete!" << std::endl; }
    if (first_line > _length || second_line > _length) {
        std::cout << "Invalid position. File only goes up to: " << std::to_string(_length) << std::endl;
        return;
    }
    if (first_line < 0) { std::cout << "Please enter what line you wish to delete." << std::endl; }

    // If/else statements to determine what nodes to delete.
    if (first_line > second_line and first_line == 0) {
        delete_starting_line();
    } else if (second_line > first_line){
        delete_selected_lines(first_line,second_line);
    } else {
        delete_one_line(first_line);
    }
}

void LinkedList::delete_starting_line() {
    auto temp = _start;

    if (_length == 1) {
        _start = nullptr;
    } else {
        _start = _start->_next;
        delete temp;
    }
    _length--;
}

void LinkedList::delete_selected_lines(int first_line, int second_line) {
    auto iterate = 1;
    auto temp = _start;
    while (iterate < first_line) { temp = temp->_next; iterate++;}
    while (iterate < second_line + 1 && temp->_next != nullptr){
        if (first_line == 0) {
            Node *node_delete = _start;
            _start = _start->_next;
            delete node_delete;
        } else {
            Node *node_delete = temp->_next;
            temp->_next = node_delete->_next;
            delete node_delete;
        }
        iterate++;
        _length--;
    }
}

void LinkedList::delete_one_line(int first_line) {
    auto temp = _start;
    auto iterate = 0;

    for (int i = 0; i < first_line - 1 && temp->_next != nullptr; ++i) {
        temp = temp->_next;
        iterate++;
    }
    Node *node_delete = temp->_next;
    temp->_next = node_delete->_next;
    delete node_delete;
    _length--;
}

void LinkedList::display(int num_one, int num_two) {
    // By default, will display all lines.
    // If one number is given, it will display the line at that position (if valid).
    // If a second number is given, it will continue to display lines up to that position.
    if (num_one <= -1){
        display_all();
    } else if (num_one <= _length && num_two <= num_one){
        display_one_line(num_one);
    } else if(num_two > num_one && num_two <= _length) {
        display_multiple(num_one,num_two);
    } else {
        std::cout << "Line does not exist" << std::endl;
        return;
    }
    std::cout << std::endl;
}

void LinkedList::display_all() {
    auto* temp = _start;
    auto iterate = 0;

    while (temp != nullptr) {
        _display_line = std::to_string(iterate+1) + ">> " + temp->_data;
        std::cout << _display_line;
        temp = temp->_next;
        iterate++;
    }
}

void LinkedList::display_one_line(int num_one) {
    auto* temp = _start;
    auto iterate = 0;

    while (iterate < num_one+1){
        if (iterate == num_one) {
            _display_line = std::to_string(iterate+1) + ">> " + temp->_data;
            std::cout << _display_line;
        }
        temp = temp->_next;
        iterate++;
    }
}

void LinkedList::display_multiple(int num_one, int num_two) {
    auto* temp = _start;
    auto iterate = 0;
    while (iterate < num_one) {temp = temp->_next; iterate++;}
    while (iterate < num_two+1) {
        if (iterate >= _length){
            return;
        } else {
            if (iterate <= num_two) {
                _display_line = std::to_string(iterate + 1) + ">> " + temp->_data;
                std::cout << _display_line;
            }
        }
        temp = temp->_next;
        iterate++;
    }
}

void LinkedList::save_file(const std::string file_name) {
    std::ofstream file(file_name);
    Node* temp = _start;

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << file_name << std::endl;
        return;
    }
    while (temp != nullptr) {
        file << temp->_data;
        temp = temp->_next;
    }

    file.close();
}

int LinkedList::list_length() const {
    return _length;
}

LinkedList::~LinkedList() = default;
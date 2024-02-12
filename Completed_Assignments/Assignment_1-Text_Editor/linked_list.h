#ifndef ASSIGNMENT1_LINKED_LIST_H
#define ASSIGNMENT1_LINKED_LIST_H

#include <iostream>

struct Node {
    std::string _data;
    Node* _next;

    Node(const std::string& line) : _data(line), _next(nullptr) {}
};

class LinkedList {
private:
    Node* _start;
    int _length;
    std::string _display_line;

public:
    LinkedList();
    ~LinkedList();

    void insert(const std::string& str, int position = -1);
    void delete_line(int first_line = -1, int second_line = -1);
    void delete_starting_line();
    void delete_selected_lines(int first_line, int second_line);
    void delete_one_line(int first_line);
    void display(int num_one = -1, int num_two = -1);
    void display_all();
    void display_one_line(int num_one);
    void display_multiple(int num_one,int num_two);
    void save_file(std::string file_name);
    [[nodiscard]] int list_length() const;
};


#endif //ASSIGNMENT1_LINKED_LIST_H

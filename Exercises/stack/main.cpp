#include <iostream>
#include <memory>
#include <optional>

using std::cout,std::endl;

struct Data {
    int _id {0};
    float _val {0.0};
};
std::ostream& operator<<(std::ostream& output, const Data& data) {
    output << "ID: " << data._id << ", ";
    output << "Value: " << data._val;
    return output;
}

struct Node {
    Data _data {-1,3.14};
    std::unique_ptr<Node> _next {nullptr};
};

class Stack {
    std::unique_ptr<Node> _top {nullptr};
public:
    void push(Data data){
        auto node = std::make_unique<Node>(data);
        node->_next = std::move(_top);
        _top = std::move(node);
    }

    std::optional<Data> peek() {
        if (_top == nullptr) return std::nullopt;
        return std::make_optional<Data>(_top->_data);
    }

    void pop() {
        if (_top != nullptr) {
            _top = std::move(_top->_next);
        }
    }

    friend std::ostream& operator<<(std::ostream& output, const Stack &stack);
};

std::ostream& operator<<(std::ostream& output,const Stack &stack) {
    auto node = stack._top.get();

    while(node != nullptr) {
        output << node->_data << endl;
        node = node->_next.get();
    }

    return output;
}

int main () {

    Stack stack;

    // Test 1 - add a node to the stack
    cout << "Test 1 - Add a node to the stack" << endl;
    cout << "--------------------------------" << endl;

    stack.push({1,1.1});

    cout << stack << endl;

    // Test 2 - add some more nodes to the stack
    cout << "Test 2 - Push nodes to the stack" << endl;
    cout << "--------------------------------" << endl;

    stack.push({2,2.2});
    stack.push({3,3.3});
    stack.push({4,4.4});
    stack.push({5,5.5});

    cout << stack << endl;

    // Test 3 - get data from the top of the stack
    cout << "Test 3 -  get data from the top of the stack" << endl;
    cout << "--------------------------------------------" << endl;

    cout << stack.peek().value_or(Data{-1,-1.1}) << endl;

    // Test 4 - remove node from the stack
    cout << "Test 4 - Remove a node from the stack" << endl;
    cout << "-------------------------------------" << endl;
    stack.pop();

    cout << stack << endl;

    // Test 5 - remove all from stack
    cout << "Test 5 - Remove all from the stack" << endl;
    cout << "-------------------------------------" << endl;

    while (stack.peek() != std::nullopt) {
        cout << stack << endl;
        stack.pop();
    }

    return 0;
}
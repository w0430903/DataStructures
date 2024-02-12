#include <iostream>

struct Data {
    int _age {0};
    std::string _name;
    std::string _id;
};
std::ostream& operator<<(std::ostream& output, const Data& data) {
    output << "Name: " << data._name << ", ";
    output << "ID: " << data._id << ", ";
    output << "Age: " << data._age;
    return output;
}

struct Node {
    Data _data;
    Node* _next {nullptr};
};

class Queue final {
    Node* _front {nullptr};
    Node* _back {nullptr};
    size_t _size {0};
public:
    void push_back(Data data) {
        auto node = new Node({data});

        // are we adding to an empty queue?
        if (_front == nullptr) {
            // yes, the queue is empty
            _front = node;
        } else {
            // no, there are existing nodes
            _back->_next = node;
        }
        _back = node;
        _size++;
    }

    [[nodiscard]] Data peek() const {
        return _front != nullptr ? _front->_data : Data({-1,"Invalid Name","Invalid Id"});
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }


    void pop_front() {
        if (_size == 0) return;

        auto node = _front;
        _front = _front->_next;

        if (_front == nullptr) _back = nullptr;


        delete node;
        _size--;
    }

    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
};

std::ostream& operator<<(std::ostream& output, const Queue& queue){
    auto node = queue._front;

    while (node != nullptr){
        output << node->_data << std::endl;
        node = node->_next;
    }

    return output;
}

int main() {

    Queue queue;

    // test 1 : add nodes to the queue
    std::cout << "Test 1: Pushing Nodes" << std::endl;
    std::cout << "---------------------" << std::endl;

    queue.push_back({20,"John","W111111"});
    queue.push_back({22,"Johnna","W111112"});
    queue.push_back({25,"Johnray","W111113"});
    queue.push_back({21,"Joseph","W111114"});
    queue.push_back({31,"Johnnathan","W111115"});

    std::cout << queue << std::endl;
    std::cout << std::endl;

    // test 2 : Look at the front of the queue
    std::cout << "Test 2: Peek at a node" << std::endl;
    std::cout << "----------------------" << std::endl;

    std::cout << queue.peek() << std::endl;
    std::cout << std::endl;

    // Test 3 : remove a node from the queue
    std::cout << "Test 3: Pop off the first node" << std::endl;
    std::cout << "------------------------------" << std::endl;

    queue.pop_front();
    std::cout << queue << std::endl;
    std::cout << std::endl;

    // Test 3 : remove the rest of the nodes from the queue
    std::cout << "Test 3: Pop off all nodes" << std::endl;
    std::cout << "-------------------------" << std::endl;

    while (queue.size() > 0) {
        queue.pop_front();
        std::cout << queue << std::endl;
    }

    return 0;
}
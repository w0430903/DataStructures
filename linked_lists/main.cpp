#include <iostream>

using std::cout, std::endl;

class LinkedList {
    struct LinkedListNode {
        int _data {-1};
        LinkedListNode* _next {nullptr};
    };

    LinkedListNode* _start {nullptr};
    size_t _size {0};

public:
    virtual ~LinkedList() {
        auto node = _start;

        while (node != nullptr) {
            auto temp = node;
            node = node->_next;
            delete temp;
        }
    }

    [[nodiscard]] size_t size() const { return _size; }

    void add(int data) {
        // Create a new node for the chain
        auto new_node = new LinkedListNode();
        new_node->_data = data;

        // Is this the first node in the chain?
        if (_start == nullptr) {
            // It is the first! Link it to the start pointer.
            _start = new_node;
        } else {
            // Not the first.
            // Look for the end of the chain.
            auto node = _start;
            auto prev = (LinkedListNode*) nullptr;

            while (node != nullptr) {
                prev = node;
                node = node->_next;
            }

            // Attach the new node to the end of the chain.
            if (prev != nullptr) {
                prev->_next = new_node;
            }
        }
        // Increase the number of total nodes.
        _size++;
    }

    /// Inserts a node in an existing chain.
    void insert(int data, int index) {

        if (index > _size) throw std::invalid_argument("invalid index");

        // if inserting at the end of the chain, send to the 'add' function
        if (index == _size) return add(data);

        // Create the new node.
        auto node = new LinkedListNode();
        node->_data = data;

        // Find the position to insert the node.
        auto curr = _start;
        auto prev = (LinkedListNode*) nullptr;

        for (int i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->_next;
        }

        // Insert the node.
        if (prev == nullptr) {
            // inserting at the start of the chain.
            node->_next = _start;
            _start = node;
        } else {
            // Inserting somewhere else in the chain.
            node->_next = prev->_next;
            prev->_next = node;
        }
        // Increase the total number of nodes.
        _size++;
    }

    /// delete a node in the chain
    void remove(int data) {
        auto node = _start;
        auto prev = (LinkedListNode*) nullptr;

        // Find the node to delete
        while (node != nullptr && node->_data != data) {
            prev = node;
            node = node->_next;
        }

        // Did I find the node to delete?
        if (node != nullptr) {

            // Is it the first node?
            if (prev == nullptr) {
                _start = node->_next;
            } else {
                prev->_next = node->_next;
            }

            delete node;
            _size--;
        }
    }

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
};

std::ostream& operator<<(std::ostream& output, LinkedList& list) {
    auto node = list._start;

    while (node != nullptr) {
        cout << node->_data << " ";
        node = node->_next;
    }

    return output;
}

int main() {
    auto list = LinkedList();

    // Test 1 - Add some numbers to the linked list.
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Test 1 - Adding nodes." << endl;
    cout << "----------------------" << endl;
    cout << list << endl;

    // Test 2 - Insert node at the start of the chain.
    list.insert(0, 0);

    cout << "\nTest 2 - insert nodes at the start." << endl;
    cout << "-----------------------------------" << endl;
    cout << list << endl;

    // Test 3 - Insert node in the middle.
    list.insert(6, 1);

    cout << "\nTest 3 - insert node in the middle." << endl;
    cout << "-----------------------------------" << endl;
    cout << list << endl;

    // Test 4 - Insert node at the end of the chain.
    list.insert(7, 7);

    cout << "\nTest 4 - insert nodes to the end." << endl;
    cout << "---------------------------------" << endl;
    cout << list << endl;

    // Test 5 - Deleting node at the start of the chain.
    list.remove(0); // Remove the first zero in the chain.

    cout << "\nTest 5 - Deleting node at the start of the chain." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << list << endl;

    // Test 6 - Deleting node in the middle.
    list.remove(3); // Remove the first zero in the chain.

    cout << "\nTest 6 - Deleting node in the middle." << endl;
    cout << "-------------------------------------" << endl;
    cout << list << endl;

    // Test 7 - Delete a node at the end of the chain.
    list.remove(7); // Remove the first zero in the chain.

    cout << "\nTest 7 - Deleting node at the end." << endl;
    cout << "----------------------------------" << endl;
    cout << list << endl;

    return 0;
}
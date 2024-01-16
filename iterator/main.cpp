#include <iostream>
#include <vector>

using std::cout, std::endl;

int main() {
    auto v = std::vector {1,2,3,4,5};

    // Short Form Iterator
    for (auto n:v) {
        cout << n << ' ';
    }
    cout << endl;

    // Long Form Iterator
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Index Operator
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;


    return 0;
}
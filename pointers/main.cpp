#include <iostream>

using std::cout, std::endl;

int main() {

    int num = 0x1234;
    char* ptr = (char*)&num;

    cout << "num = 0x" << std::hex << num << endl;

    *ptr = 'X';
    cout << "num = 0x" << std::hex << num << endl;
    ptr++;
    *ptr = 'X';
    cout << "num = 0x" << std::hex << num << endl;

    cout << "ptr = " <<  (long long)ptr << endl;


    return 0;
}
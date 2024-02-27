#include <iostream>

bool is_palindrome(std::string word){
    int length = word.length() - 1;

    for (int i = 0; i < length/2; i++) {
        if (word[i] != word[length - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string word;
    std::cout<< "Enter a word: " << std::endl;
    std::cin >> word;

    if (is_palindrome(word)) {
        std::cout << "Is a palindrome!." << std::endl;
    } else {
        std::cout << "Is not a palindrome!." << std::endl;
    }

    return 0;
}
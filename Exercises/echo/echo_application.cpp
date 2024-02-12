#include <iostream>
#include "echo_application.h"


const std::string EchoApplications::END_VALUE = "end";

EchoApplications::EchoApplications(std::istream& in, std::ostream& out): _cin(in), _cout(out){}
void EchoApplications:: input() {
    _cout << "Type something: ";
    std::getline(_cin,_input);
}
void EchoApplications::output() {
    _cout << _input << std::endl;
}
void EchoApplications::run(){
    // Example 1
    // Echo the input received from the user
    do {
        input();
        output();
    } while (_input != END_VALUE);
}
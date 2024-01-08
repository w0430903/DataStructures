#include <iostream>
#include "echo_application.h"


int main(){
    EchoApplications app(std::cin,std::cout);
    app.run();

    return 0;
}


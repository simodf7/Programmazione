#include <iostream>
#include "AStack.h"
#include <string>

int main(){
    
    ArrayStack<std::string> myStack;
    myStack.push("one");
    myStack.push("two");
    myStack.push("three");
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    return 0;
    
}
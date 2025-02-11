#include <iostream>
#include <thread>

void print_hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(print_hello); // Create a new thread that runs print_hello
    t.join(); // Wait for the thread to finish
    std::cout << "Hello from main thread!" << std::endl;
    return 0;
}

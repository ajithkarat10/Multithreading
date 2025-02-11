#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for critical section
int counter = 0;

void increment_counter() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
    ++counter; // Critical section
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}

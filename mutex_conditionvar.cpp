#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_message(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; }); // Wait for the condition variable to be notified
    std::cout << "Thread " << id << " is running!" << std::endl;
}

int main() {
    std::thread t1(print_message, 1);
    std::thread t2(print_message, 2);

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all(); // Notify all waiting threads

    t1.join();
    t2.join();

    return 0;
}

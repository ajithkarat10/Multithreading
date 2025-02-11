#include <iostream>
#include <thread>
#include <future>

void calculate_square(std::promise<int>&& p, int x) {
    p.set_value(x * x);
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread t(calculate_square, std::move(p), 5);

    int result = f.get();
    std::cout << "Square is: " << result << std::endl;

    t.join();

    return 0;
}

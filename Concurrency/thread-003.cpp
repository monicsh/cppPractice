#include <iostream>
#include <vector>
#include <thread>
using namespace std;

int accum = 0;
mutex accum_mutex;

void square(int x) {
    int temp = x * x;
    accum_mutex.lock();
    accum += temp;
    accum_mutex.unlock();
}

int main() {
    vector<thread> ths;
    for (int i = 1; i <= 20; i++) {
        ths.push_back(thread(&square, i));
    }

    for (auto& th : ths) {
        th.join();
    }
    cout << "accum = " << accum << endl;
    return 0;
}

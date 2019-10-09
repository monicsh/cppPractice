#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
 
std::mutex g_display_mutex;
int i = 0; 
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();

    //std::this_thread::sleep_for(std::chrono::seconds(1));
int c = i;
i++; 
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping[i:" << c << "]...\n";
    g_display_mutex.unlock();
 
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    std::thread t4(foo);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

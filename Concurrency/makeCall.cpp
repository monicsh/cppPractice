#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex m;
int i = 0; 
void makeACallFromPhoneBooth() 
{
    std::thread::id this_id = std::this_thread::get_id();

    std::this_thread::sleep_for(std::chrono::seconds(1));

	//m.lock();
      std::cout << "i: " << i << "[" << this_id << "]" << std::endl;
      i++;
      //m.unlock();//man unlocks the phone booth door 
}

int main() 
{
    std::thread man1(makeACallFromPhoneBooth);
    std::thread man3(makeACallFromPhoneBooth);
    std::thread man4(makeACallFromPhoneBooth);
    std::thread man2(makeACallFromPhoneBooth);
    
    man1.join();
    man2.join();
    man3.join();
    man4.join();	
    return 0;
}

// threadWithoutJoin.cpp

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;


void helloFunction(int a){
    mtx.lock();
    std::cout<<"thread::"<<a<<" "<<std::this_thread::get_id()<< std::endl;
    mtx.unlock();
}

class HelloFunctionObject{
  public:
    void operator()() const {
      std::cout << "Hello from a function object." << std::endl;
    }
};
int main(){

  std::thread t1(helloFunction, 1);
  std::thread t2(helloFunction, 2);
  std::thread t3(helloFunction, 3);
  std::thread t4(helloFunction, 4);
  std::thread t5(helloFunction, 5);
  //std::thread t([]{std::cout << std::this_thread::get_id() << std::endl;});

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
}

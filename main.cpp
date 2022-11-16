#include <iostream>
#include <bits/stdc++.h>
#include <future>

void test(){
    auto threadId = std::this_thread::get_id();
    std::cout<<"Test on thread: "<<threadId<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto threadId = std::this_thread::get_id();
    std::cout<<"Main thread: "<<threadId<<std::endl;

    for(int i=0;i<10;i++){
        auto future = std::async(std::launch::async, test);
    }
    return 0;
}

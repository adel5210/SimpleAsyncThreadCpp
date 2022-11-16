#include <bits/stdc++.h>
#include <vector>
#include <future>
#include <iostream>
#include <chrono>
#include <mutex>



int main() {
    auto threadId = std::this_thread::get_id();
    std::cout<<"Main thread: "<<threadId<<std::endl;

    using handle = std::future<void>;

    std::vector<handle> handles;
    for(int i=0;i<10;i++){
        handles.push_back(std::async(std::launch::async, [](){
            auto threadId = std::this_thread::get_id();
            std::cout<<"Test on thread: "<<threadId<<std::endl;
//            std::this_thread::sleep_for(std::chrono::seconds(5));
        }));
    }
    std::cout<<"Main thread: "<<threadId<<std::endl;


    return 0;
}

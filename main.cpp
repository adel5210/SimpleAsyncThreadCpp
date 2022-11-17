#include <bits/stdc++.h>

std::mutex c_lock;
int main() {
    std::chrono::system_clock::now();
    auto threadId = std::this_thread::get_id();
    std::cout<<"Main thread: "<<threadId<<std::endl;

    using handle = std::future<void>;

    std::vector<handle> handles;
    std::vector<std::string> threadsList;
    for(int i=0;i<10;i++){
        handles.push_back(std::async(std::launch::async, [&threadsList](){
            auto threadId = std::this_thread::get_id();
//            std::cout<<"Test on thread: "<<threadId<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            std::lock_guard<std::mutex> lock(c_lock);
            //binds to one
            std::stringstream ss;
            ss<<threadId;
            std::string t=ss.str();

            threadsList.emplace_back("threadId: "+t);
            std::cout<<"Test on thread: "<<t<<std::endl;
        }));
    }
    std::cout<<"Main thread: "<<threadId<<std::endl;


    return 0;
}

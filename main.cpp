<<<<<<< HEAD
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <queue>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>

int main(int argc, char *argv[]) {
    std::vector<int> fv;
    for(int i = 0; i<100;i++){
        fv.push_back(i);
    }
    for(auto i : fv){
        printf("str %d",i);
    }
=======
#include <iostream>



int main(int argc, char *argv[]) {

    std::cout<< "Something" << std::endl;
>>>>>>> cd85386 (Add a c++ simple program)
    return 0;
};

#pragma once
#include <vector>

class Heap_Max{
public:
//    auto const top();
//    auto add(int x);
//    auto reduce();


private:
    std::vector<int> array;
    int size = 0;
    void goUp(int x);
    void goDown(int x);

};




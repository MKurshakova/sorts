#include "Heap_Max.h"

auto const Heap_Max::top() {
    return array[0];
}

auto Heap_Max::add(int x) {
    array.push_back(x);
    goUp(size);
    size++;
}
auto Heap_Max::reduce() {
    size--;
    std::swap(array[size], array[0]);
    goDown(0);
}

void Heap_Max::goUp(int x) {
    if( x > size || x == 1)return;
    auto parent = (x - 1) / 2;
    if (array[parent] < array[x]){
        std::swap(array[parent], array[x]);
    }
    goUp(parent);
}

void Heap_Max::goDown(int x) {
    while (2 * x + 1 < size) {
        auto left = 2 * x + 1;
        auto right = 2 * x + 2;
        auto largest = x;
        if(array[left] <= size && array[x] < array[left]){
            largest = left;
        }
        if(array[right] <= size && array[x] < array[right]){
            largest = right;
        }
        if(largest != x){
            std::swap(array[x], array[largest]);
            goDown(largest);
        }
    }
}


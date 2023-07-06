#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <bits/stdc++.h>
#include <cmath>
int partition(std::vector<int>& vec, int p, int r){
    auto pivot = vec[r];
    auto smaller = p;
    for(auto i = p; i <= r-1; i++) {
        if (vec[i] <= pivot) {
            std::swap(vec[smaller], vec[i]);
            smaller++;
        }
    }
    std::swap(vec[smaller], vec[r]);
    return smaller;
}
int randomPivotPartition(std::vector<int>& vec, int p, int r){
    srand(time(nullptr));
    auto random = p + rand() % (r - p);
    std::swap(vec[r], vec[random]);
    return partition(vec, p, r);
}

void randomQuickSort(std::vector<int>& vec, int p, int r){
    if(p < r){
        auto q = randomPivotPartition(vec, p, r);
        randomQuickSort(vec, p, q - 1);
        randomQuickSort(vec, q + 1, r);
    }
}

void quickSort(std::vector<int>& vec, int p, int r){
    if(p < r){
        auto q = partition(vec, p, r);
        quickSort(vec, p, q - 1);
        quickSort(vec, q + 1, r);
    }

}

void heapify(std::vector<int>& heap, int size, int root){
    int largest = root;
    int left = root * 2 +1;
    int right = left++;
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != root) {
        std::swap(heap[root], heap[largest]);
        heapify(heap, size, largest);
    }
}
void heapSort(std::vector<int>& vec, int size){
    for(auto i = size / 2 - 1; i >= 0; i--){
        heapify(vec, size, i);
    }
    for(auto i = size - 1; i > 0; i--){
        std::swap(vec[0], vec[i]);
        heapify(vec,i, 0);
    }
}

int main() {
    double pi = M_PI;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,10000);

    std::vector<int> vec{};
    auto size = 100000;
    for(auto i = 0; i < size; i++){
        vec.push_back(dist(rng));
    }
    std::vector<int> vec_quick(vec);
    std::vector<int> vec_random(vec);



    std::cout<< "heapsort\n";

    auto start_time = std::chrono::high_resolution_clock::now();
    heapSort(vec, size);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    std::cout << "Time taken by program is : ";
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;

    reverse(vec.begin(), vec.end());

    start_time = std::chrono::high_resolution_clock::now();
    heapSort(vec, size);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;

    std::cout << "Time taken by program is : ";
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    heapSort(vec, size);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;

    std::cout << "Time taken by program is : ";
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;



    std::cout << "quicksort with random\n";

    start_time = std::chrono::high_resolution_clock::now();
    randomQuickSort(vec_random, 0, vec_random.size()-1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;
    std::cout << "Time taken by program is : " << std::fixed ;
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;

    reverse(vec_random.begin(), vec_random.end());

    start_time = std::chrono::high_resolution_clock::now();
    randomQuickSort(vec, 0, vec.size()-1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;
    std::cout << "Time taken by program is : " << std::fixed ;
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;


    start_time = std::chrono::high_resolution_clock::now();
    randomQuickSort(vec, 0, vec.size()-1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;
    std::cout << "Time taken by program is : " << std::fixed ;
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;


    std::cout << "quicksort\n";

    start_time = std::chrono::high_resolution_clock::now();
    quickSort(vec_quick, 0, vec_quick.size()-1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;
    std::cout << "Time taken by program is : " << std::fixed ;
    std::cout << time/std::chrono::milliseconds(1) << " ms" << std::endl;

    reverse(vec_quick.begin(), vec_quick.end());

    start_time = std::chrono::high_resolution_clock::now();
    quickSort(vec_quick, 0, vec_quick.size() - 1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;

    std::cout << "Time taken by program is : " << std::fixed;
    std::cout << time / std::chrono::milliseconds(1) << " ms" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    quickSort(vec_quick, 0, vec_quick.size() - 1);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;

    std::cout << "Time taken by program is : " << std::fixed;
    std::cout << time / std::chrono::milliseconds(1) << " ms" << std::endl;

}




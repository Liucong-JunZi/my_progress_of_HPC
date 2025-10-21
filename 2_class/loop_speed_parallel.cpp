#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>

int main(){
    int n=200000;
    std::vector<int> data(n);
    for(int i= 0;i<n;i++){
        data[i]=i;

    }
    long long sum   = 0;
    auto start_time =std::chrono::high_resolution_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for (int i =0 ;i<n;i++){
        sum += (long long)data[i]*data[i];
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed =end_time - start_time;
    std::cout<<"out put is:"<<sum<<std::endl;
    std::cout<<"time cost is "<<elapsed.count()<<" s"<<std::endl;
    return 0;
}
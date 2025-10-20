#include <iostream>
#include <omp.h>

int main(){
    std::cout<<"main thread"<<std::endl;
    #pragma omp parallel
    {
        int thread_ID =omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        #pragma omp critical
        {
        std::cout<<"i am"<<thread_ID<<"thread ,all of us have "<<num_threads<<"numbers"<<std::endl;
        }
    }
    return 0;


}
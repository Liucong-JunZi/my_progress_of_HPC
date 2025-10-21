#include <iostream>
#include <omp.h>

void who_am_i(){
    int thread_ID =omp_get_thread_num();
    int num_threads =omp_get_num_threads();
    std::cout<<"i am "<<thread_ID<<" thread ,all of us have "<<num_threads<<" numbers"<<std::endl;
}
int main(){
    who_am_i();
    #pragma omp parallel
    {
        #pragma omp critical
        {
            who_am_i();
        }
    }
    return 0;
}
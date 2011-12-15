#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
    int rank,size;
#pragma omp parallel private(rank)
    {
        rank=omp_get_thread_num();
        size=omp_get_num_threads();
        cout<<"Helloworld I am "<<rank<<" of "<<size<<endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
#pragma omp parallel
    cout<<"HELLOWORLD"<<endl;
}

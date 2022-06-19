#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {

    #pragma omp parallel
    {
        #pragma omp single
        {    
            #pragma omp task
            {
                cout<<"\nHello Thread No. %d: "<< omp_get_thread_num();
            }

            #pragma omp task
            {
                cout<<"\nWorld No. %d: "<< omp_get_thread_num();
            }
        }//sigle
    }//fork

    return 0;
}

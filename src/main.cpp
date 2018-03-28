/*
 * main.cpp
 * */

#include <iostream>
#include <omp.h>
#include <unistd.h>

void test() {
    #ifdef _OPENMP
    #pragma omp parallel for
    #endif
    for(int i = 0; i < 10; i++) {
        int thread_id = omp_get_thread_num();
        printf("%04d: %d\n", thread_id, i);
        usleep(5000);
    }
}

void test2() {
    #pragma omp parallel
    #pragma omp sections
    {
        #pragma omp section
        {
            //並列させたい処理1
            int thread_id = omp_get_thread_num();
            for(int i = 0; i < 10; i++) {
                printf("%04d: %d\n", thread_id, i);
                usleep(5000);
            }
        }
        #pragma omp section
        {
            //並列させたい処理2
            int thread_id = omp_get_thread_num();
            for(int i = 0; i < 10; i++) {
                printf("%04d: %d\n", thread_id, i);
                usleep(5000);
            }
        }
        #pragma omp section
        {
            //並列させたい処理3
            int thread_id = omp_get_thread_num();
            for(int i = 0; i < 10; i++) {
                printf("%04d: %d\n", thread_id, i);
                usleep(5000);
            }
        }
    }
}

int main(const int, const char* const []) {
    #ifdef _OPENMP
    std::cout << "OpenMP : Enabled (Max # of threads = " << omp_get_max_threads() << ")" << std::endl;
    #endif

    test();
    test2();

    return 0;
}

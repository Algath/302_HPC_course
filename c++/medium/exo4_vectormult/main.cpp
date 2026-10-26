#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

int main(){
    int x[4] = {1000,10000,50000,100000};
    int size = sizeof(x) / sizeof(x[0]);

    srand(time(0));

    for (int i = 0; i< size; i++) {
    
        vector<int> a(x[i]), b(x[i]);
        for (int j = 0; j < x[i]; j++) {
            a[j] = rand() % 1000;
            b[j] = rand() % 1000;
        }

        auto start = high_resolution_clock::now();
        long long sum = 0;
        
        for (int k = 0; k < x[i]; k++) {
            sum += (long long)a[k] * b[k];
        }

        cout << "Scalar product: " << sum << endl;  

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end-start);

        cout << "Execution Time: " << duration.count() << " microsends" << endl;
    }

    return 0;
}
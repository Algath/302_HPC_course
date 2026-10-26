#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;



void initilizeMatrix(int *m,int size) {
    for (int i = 0; i < size * size; i++)
        m[i] = rand() % 10;
}

int *allocateMatrix(int size) {
    return new int[size*size]{0};
}

void multiplyMatrix(const int *a, const int *b, int *c, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += a[i * n + k] * b[k * n + j];
            c[i * n + j] = sum;
        }
}

int main(int argc, char* argv[]) {
    int size = stoi(argv[1]);
    srand(time(nullptr));

    int *a = allocateMatrix(size);
    int *b = allocateMatrix(size);
    int *c = allocateMatrix(size);

    initilizeMatrix(a, size);
    initilizeMatrix(b, size);

    auto start  = high_resolution_clock::now();
    multiplyMatrix(a, b, c, size);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end-start);

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
#include <iostream>
#include <chrono>

using namespace std;

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    auto start = high_resolution_clock::now();

    cout << "Hello, World!";

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "\nDuration: " << duration << " ms" << endl;
    return 0;
}

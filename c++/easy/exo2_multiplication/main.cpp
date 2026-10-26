#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main() {
    int x;
    int sum;

    auto start = high_resolution_clock::now();

    // ofstream mul_n("multiplication_n.txt");
    ofstream mul_endl("multiplication_endl.txt");

    cout << "Type a number: ";
    cin >> x;

    for (int i = 0; i <= 100000; i++) {
        // mul_n << i*x << "\n";
        mul_endl << i*x << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    //mul_n << "Execution Time: " << duration.count() << " microseconds" << "\n";
    mul_endl << "Execution Time: " << duration.count() << " microseconds" << endl;

    //mul_n.close();
    mul_endl.close();

    return 0;
}
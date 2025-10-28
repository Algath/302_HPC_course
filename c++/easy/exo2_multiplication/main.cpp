#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int main() {
    ofstream multiplendl("multiplication_endl.txt");
    ofstream multipln("multiplication_ln.txt");

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    auto startendl = high_resolution_clock::now();
    auto startln = high_resolution_clock::now();
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    for(int i = 1; i <= 100000; i++) {
        multiplendl << a << " * " << i << " = " << a * i << endl;
        multipln << a << " * " << i << " = " << a * i << "\n";
    }

    multiplendl.close();
    auto endendl = high_resolution_clock::now();
    auto durationendl = duration_cast<milliseconds>(endendl - startendl).count();
    multipln.close();
    auto endln = high_resolution_clock::now();
    auto durationln = duration_cast<milliseconds>(endln - startln).count();

    cout << "Duration with endl: " << durationendl << " ms" << endl;
    cout << "Duration with \\n: " << durationln << " ms" << endl;
    return 0;
}

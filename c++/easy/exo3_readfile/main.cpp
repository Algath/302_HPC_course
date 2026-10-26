#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main() {
    string file;
    string myText;

    auto start = high_resolution_clock::now();

    int count = 0;

    cout << "File path: ";
    cin >> file;

    ifstream MyReadFile(file);

    if (MyReadFile.is_open()) {
        while (count < 15 && getline (MyReadFile, myText)){
            cout << myText << endl;
            count++;
        }
    }
    else {
        cerr << "File not found" << endl;
        exit(EXIT_FAILURE);
    }

    MyReadFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);

    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
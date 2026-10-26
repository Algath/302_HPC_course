#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    string myText;

    auto start = high_resolution_clock::now();

    int count = 0;

    cout << "File path: " << argv[1];

    ifstream MyReadFile(argv[1]);

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
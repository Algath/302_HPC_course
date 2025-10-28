#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int compteur = 0;
    while (getline(file, line) && compteur < 15) {
        cout << line << endl;
        compteur++;
    }

    file.close();
}

int main() {
    string filename;
    cout << "Enter the filename to read: ";
    cin >> filename;

    readFile(filename);
    return 0;
}

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void vectorFiler(int x, vector<int>& vec){
	for (int i = 0; i < x; i++){
		vec.push_back(rand());
	}
}

int produitScalaire(const vector<int>& v1, const vector<int>& v2){
	if (v1.size() != v2.size()){
		cerr << "Erreur : les vecteurs doivent avoir la même taille !" << endl;
		exit(EXIT_FAILURE);
	}
	
	int produit = 0;
	for (size_t i = 0; i < v1.size(); i++){
		produit += v1[i] * v2[i];
	}

	return produit;
}

void printDuration(ofstream& file, long long duration, long long result) {
	long long minutes = duration/60000;
        long long secondes = (duration % 60000)/1000;
        long long millisecondes = duration % 1000;

	file << "Produit scalaire: " << result << endl;
	file << "Duration of the dot product: " << minutes << " min: " << secondes << " s: " << millisecondes << " ms: " << endl;

        cout << "Produit scalaire: " << result << endl;
        cout << "Duration of the dot product: " << minutes << " min: " << secondes << " s: " << millisecondes << " ms: " << endl;
}

int main(){
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::milliseconds;

	auto start = high_resolution_clock::now();
	vector<int> vec1;
	vector<int> vec2;
	int a;

	cout << "Enter vector size: ";
	cin >> a;

	string filename = "Dot_product_with_vectors_size_" + to_string(a) + ".txt";

	ofstream file(filename);
	if (!file.is_open()){
		cerr << "Erreur lors de la création du fichier !" << endl;
		exit(EXIT_FAILURE);
	}

	vectorFiler(a, vec1);
	vectorFiler(a, vec2);

	int result = produitScalaire(vec1,vec2);

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start).count();

	printDuration(file, duration, result);
	file.close();

	return 0;
}

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	const int N = 100;
	const int elements_par_proc = N/size;
	vector<int> tableau;
	vector<int> sous_tableau(elements_par_proc);

	if (rank == 0) {
		tableau.resize(N);
		cout << "Maître : Création du tableau de " << N << " éléments" << endl;

		for (int i = 0; i < N; i++){
			tableau[i] = rand();
		}
		cout << "Maître : Distribution aux " << size << " processus" << endl;
	}

	MPI_Scatter(tableau.data(), elements_par_proc, MPI_INT, sous_tableau.data(), elements_par_proc, MPI_INT, 0, MPI_COMM_WORLD);

	cout << "Processus " << rank << " : Traitement de " << elements_par_proc << " éléments" << endl;

	int sum = 0;
	for (int& val: sous_tableau) {
		sum += val;
	}

	cout << "Processus " << rank << " : Somme locale = " << sum << endl;

	int global_sum = 0;
	MPI_Reduce(&sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);

	if (rank == 0){
		cout << "\nMaître : Somme globale = " << global_sum << endl;
	}

	MPI_Finalize();
	return 0;
}

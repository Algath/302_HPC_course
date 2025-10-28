#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {

	MPI_Init(&argc, &argv);

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	std::cout << "Processor " << world_rank << " - Hello World" << std::endl;

	MPI_Finalize();

	return 0;
}

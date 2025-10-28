#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    // Initialiser l'environnement MPI
    MPI_Init(&argc, &argv);

    // Obtenir le nombre total de processus
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtenir le rang (ID) du processus actuel
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Le processus 0 affiche le nombre total de processeurs
    if (world_rank == 0) {
        std::cout << "Number of processors: " << world_size << std::endl;
    }

    // Synchronisation pour affichage ordonné
    int token = 0;

    if (world_rank == 0) {
        // Le processus 0 affiche en premier
        std::cout << "Processor " << world_rank << " - Hello World" << std::endl;
        
        // Puis envoie le token au processus suivant (s'il existe)
        if (world_size > 1) {
            MPI_Send(&token, 1, MPI_INT, world_rank + 1, 0, MPI_COMM_WORLD);
        }
    } else {
        // Les autres processus attendent de recevoir le token
        MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        // Affichent leur message
        std::cout << "Processor " << world_rank << " - Hello World" << std::endl;
        
        // Et passent le token au suivant (s'il existe)
        if (world_rank < world_size - 1) {
            MPI_Send(&token, 1, MPI_INT, world_rank + 1, 0, MPI_COMM_WORLD);
        }
    }

    // Finaliser l'environnement MPI
    MPI_Finalize();

    return 0;
}

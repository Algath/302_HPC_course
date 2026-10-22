# Exercice 7

Dans cet exercice, vous allez reprendre l’exercice 4 de la partie C++ (produit scalaire de deux vecteurs) et accélérer le calcul en utilisant MPI.

Le processus de rang 0 crée les deux vecteurs et les remplit avec des valeurs aléatoires. Il les répartit ensuite entre tous les processus à l’aide de **MPI_Scatter**. Chaque processus calcule le produit scalaire de sa portion puis les résultats locaux sont additionnés sur le processus 0 à l’aide de **MPI_Reduce** comme dans l’exercice 4 de la partie MPI. Le processus 0 affiche le résultat final, qui doit être identique à celui obtenu sans MPI.

Comme dans l’exercice 4 de la partie C++, la taille des vecteurs doit être passée en argument. Pour simplifier, choisissez une taille divisible par le nombre de processus. Exemple de lancement avec 4 processus :

```
mpirun -np 4 ./run 100000000
```

Mesurez le temps du calcul pour 1, 2, 4 et 8 processus avec des vecteurs de 100 millions d’éléments et affichez-le en millisecondes. Pour que la mesure soit juste, appelez **MPI_Barrier** juste avant de démarrer le chronomètre afin que tous les processus commencent en même temps.

Quel est le gain obtenu en fonction du nombre de processus ? Mesurez ensuite le temps en incluant la répartition des données avec **MPI_Scatter**. Le gain est-il toujours le même ? Qu’en concluez-vous ?

Attention au type du résultat : le type MPI utilisé dans **MPI_Reduce** doit correspondre au type de vos variables (par exemple **MPI_LONG_LONG** pour un `long long`).

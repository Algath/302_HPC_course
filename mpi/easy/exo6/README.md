# Exercice 6

Dans cet exercice, vous allez écrire un programme en C++ utilisant MPI pour effectuer une collecte de données entre plusieurs processus. Chaque processus doit commencer par créer un tableau d’entiers aléatoires dont la taille est de 1 000 000. Une fois le tableau créé, chaque processus calcule le maximum des valeurs qu’il contient.

Ensuite, tous les processus envoient leur valeur maximale au processus de rang 0 à l’aide de **MPI_Gather**. Le processus 0 reçoit alors un tableau contenant les maximums de tous les processus et l’affiche dans le terminal.

Attention aux paramètres de **MPI_Gather** : le nombre d’éléments à recevoir indique combien d’éléments le processus 0 reçoit **de chaque processus** et non le nombre total d’éléments reçus.

Exemple de résultat avec 4 processus :

```
Rank: 0, maximum is: 2147480021
Rank: 1, maximum is: 2147481746
Rank: 2, maximum is: 2147476614
Rank: 3, maximum is: 2147482544
```
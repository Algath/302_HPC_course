# Exercice 4

Dans cet exercice, vous allez écrire un programme en C++ utilisant MPI pour répartir le calcul de la somme d’un tableau entre plusieurs processus. Le processus de rang 0 commence par créer un tableau d’entiers aléatoires, qu’il divise en autant de parties qu’il y a de processus. Il envoie ensuite une partie du tableau à chaque processus à l’aide de **MPI_Scatter**. Pour simplifier, choisissez une taille de tableau divisible par le nombre de processus.

Chaque processus reçoit sa portion du tableau et calcule la somme locale des éléments reçus. Les sommes locales sont ensuite additionnées à l’aide de **MPI_Reduce** : comme **MPI_Scatter**, c’est une opération collective que tous les processus doivent appeler, et le résultat n’est disponible que sur le processus de rang 0. Enfin, le processus 0 affiche la somme totale dans le terminal.

Pour vérifier votre résultat, le processus 0 peut également calculer la somme du tableau complet sans MPI et la comparer à celle obtenue avec **MPI_Reduce**.

Attention au type des sommes : quelle valeur maximale la somme totale peut-elle atteindre ? Le type MPI utilisé dans **MPI_Reduce** doit correspondre au type de vos variables (par exemple **MPI_LONG_LONG** pour un `long long`).

Option : implémentez une variante pour laquelle tous les processus connaissent la somme totale à la fin du programme (**MPI_Allreduce**).

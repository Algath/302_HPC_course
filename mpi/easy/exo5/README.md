# Exercice 5

Dans cet exercice, vous allez écrire un programme en C++ utilisant MPI dans lequel le processus de rang 0 lit le fichier texte **data.txt** fourni avec l’exercice. Il conserve uniquement la première ligne du fichier et l’envoie à tous les autres processus à l’aide de **MPI_Bcast**. Comme **MPI_Scatter** et **MPI_Reduce**, **MPI_Bcast** est une opération collective que tous les processus doivent appeler.

Si le fichier ne peut pas être ouvert, le processus 0 doit afficher un message d’erreur avec **cerr** et arrêter tous les processus à l’aide de **MPI_Abort**.

Chaque processus affiche ensuite la ligne reçue dans le terminal, en précisant son rang. Exemple de résultat avec 4 processus :

```
Processor 2 received: La diffraction de la lumière:
Processor 0 received: La diffraction de la lumière:
Processor 3 received: La diffraction de la lumière:
Processor 1 received: La diffraction de la lumière:
```

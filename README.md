# TP Grammaire et Langage

*Auteurs :* BATEL Arthur, Buonomo Fanny

## Introduction
L'objectif de ce TP est de construire un automate LALR (analyseur ascendant) afin de permettre l'analyse de la grammaire suivante :

1. `E'-> E` (axiome)
2. `E -> E+E`
3. `E -> E*E`
4. `E -> (E)`
5. `E -> val`

## Fonctionnement de l'automate
### Le rendu du projet
Notre rendu est constitué d'un **Makefile**, des fichiers sources, ainsi qu'un **README**. 

|Commande |Description|
|---------|-----------|
|`make` | Compile le projet et crée l'exécutable `main`|
|`make clean`| Supprime l'exécutable et les fichiers compilés|
|`make help`| Explique rapidement le fonctionnement de l'automate|

### Exécuter l'automate
Une fois compilé, l'automate s'exécute avec la commande `./main <formule>`. Le paramètre formule est obligatoire, et il ne doit en avoir qu'un. La formule doit respecter les règles suivantes :

* Ne contient pas d'espace
* Respecte les règles de la grammaire
* Contient uniquement les symboles `+`   `*`   `(`   `)` ainsi que des *entiers positifs*
* Est noté entre crochets

À titre d'exemple, `./main "45+2"` est acceptée mais `./main "(45+2"` ne l'est pas.
Si la formule est correcte, le résultat du calcul est affiché dans le terminal.
Si la formule n'est pas valable, un message d'erreur sera affiché. Ce message précise si 
l'analyseur a rencontré un symbole qu'il ne connait pas, ou si la formule ne respecte pas 
les règles de la grammaire. La valeur affichée par le programme ne correpond donc pas au calcul
de la formule passée en paramètre.
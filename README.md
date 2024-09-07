# S1.01 - Implémentation d'un besoin client
## 🔱 - Le jeu de l'équipage
Dans le cadre de mes enseignements à l'IUT de Bayonne et du Pays Basque, j'ai pu réalisé ce tout premier projet en C++ avec un autre étudiant.  
  
Le jeu vous oppose à la machine, que vous devez donc battre en plusieurs manche, et chacune de celle-ci est composée de 3 lancers.  

### 🏁 - Démarrage du jeu
Au démarrage du jeu, vous avez la possibilité de paramétrer le nombre de points que vous rapporte chacun des équipements du bateau. 
  
Pour commencer à marquer des points, vous devez réunir dans l'ordre un bateau, un capitaine et un équipage. *(Vous ne pouvez pas avoir un capitaine sans bateau, et un équipage sans capitaine)*  
- Afin d'obtenir le bateau, vous devrez obtenir un 6 dans un lancer.
- Vous devrez obtenir un 5 pour posséder un capitaine.
- Et pour obtenir l'équipage, un des dés obtenus devra être égal à 4.

Après avoir monter votre bateau, vous pourrez marquer des points.

### 🎲 - Comment marquer des points ?
Plusieurs possibilités pour marquer des points :
- L'obtention d'une des trois parties de votre équipage.
- Une fois votre équipage monté, l'addition des dés.

À chaque manche, vous devrez reconstruire votre équipage.

### 🏅 - Fin de partie
La partie se termine par défaut au bout de 5 manches.  

À l'issue des 5 manches, le joueur ayant le plus grand score remporte la partie.

**Retrouvez le dossier de conception dans le fichier PDF.**

# CPool_Tree_2026

## 🎄 Sapin de Noël ASCII - Projet B-CPE-100

Repository contenant l'implémentation du **sapin ASCII redimensionnable** pour le module B1 Unix et C.

## Fonctionnalités

- ✅ Sapin parfaitement centré
- ✅ Gestion taille = 0 (rien affiché)
- ✅ Utilisation EXCLUSIVE de `my_putchar`
- ✅ Seule syscall `write()` autorisée
- ✅ Code modulaire et testable


Architecture du code

tree.c
├── afficher_etoiles()     → Affiche les * de la couronne
├── afficher_troncs()      → Affiche les | du tronc
├── afficher_espaces()     → Centrage du sapin
├── afficher_couche_sapin()→ Une ligne complète de couronne
├── afficher_tronc_sapin() → Tronc complet (2 lignes)
└── tree()                → Fonction principale

Algorithme du sapin

1. Calculer largeurTronc = taille/2 + 1
2. POUR i de 0 à taille-1:
     afficher_couche(taille + 2*i, largeurTronc)
3. afficher_tronc(largeurTronc, 2)

Largeur couche i = taille + 2×i
Centrage = (largeurTronc - largeurCouche) ÷ 2
Compilation
bash

cc -Wall -Wextra main.c my_putchar.c tree.c -o sapin
./sapin 5

Tests automatisés (local)
bash

#!/bin/bash
# tests.sh

for taille in 0 1 3 5 7; do
    echo "Test taille $taille:"
    ./sapin $taille
    echo "---"
done

Conformité 100%
Contraintes	Statut
Fichier unique tree.c	✅
Pas de main()	✅
Seulement my_putchar	✅
Pas de fichiers inutiles	✅
Fonctions à responsabilité unique	✅
Style de code EPITECH	✅
Dépôt Git

CPool_Tree_2026/
├── tree.c      # SEUL fichier à livrer
├── README.md   # Documentation
└── .gitignore  # Ignore binaires/obj

.gitignore:
*.o
a.out
sapin
*~



# CPool_Tree_2026 (dernier jour de la piscine)

## 🎄 Sapin de Noël ASCII - Projet B-CPE-100

Repository contenant l'implémentation du **sapin ASCII redimensionnable** pour le module B1 Unix et C.

## Fonctionnalités

- ✅ **Sapin parfaitement centré** : Calcul dynamique de la largeur maximale.
- ✅ **Gestion `taille = 0`** : Aucune sortie sur le terminal.
- ✅ **Utilisation EXCLUSIVE** de `my_putchar`.
- ✅ **Seule syscall `write()`** autorisée (via `my_putchar`).
- ✅ **Code modulaire** : Fonctions courtes et spécialisées.

---

## Architecture du code

Le fichier `tree.c` est découpé selon une logique de responsabilité unique :

* **`print_chars(int n, char c)`** : Affiche `n` fois le caractère `c`.
* **`get_max_width(int size)`** : Calcule la largeur de la dernière ligne (essentiel pour le centrage).
* **`draw_trunk(int size, int max_width)`** : Gère l'affichage du tronc centré.
* **`tree(int size)`** : Orchestre les étages et les sauts de ligne.

---

## Algorithme du sapin

Le sapin suit une progression géométrique précise :
1.  **Nombre de lignes par étage** : $étage + 3$.
2.  **Largeur du tronc** : `size` si impair, `size + 1` si pair.
3.  **Réduction entre étages** : Un retrait d'étoiles est appliqué à chaque nouveau palier pour créer la forme de sapin.

### Formules clés :
* **Largeur Tronc** : `(size % 2 == 0) ? size + 1 : size`
* **Centrage** : `(largeurMax - largeurActuelle) / 2`

---

## Compilation & Usage

Pour compiler le projet avec les flags de sécurité standard :

```bash
gcc -Wall -Wextra main.c my_putchar.c tree.c -o sapin
```

Pour exécuter le programme :
```bash
./sapin 5
```

---

## Tests automatisés (Local)

Tu peux utiliser ce script shell pour vérifier rapidement le rendu de plusieurs tailles :

```bash
#!/bin/bash
# tests.sh

for taille in 0 1 3 5; do
    echo "--- Test taille $taille ---"
    ./sapin $taille
    echo -e "\n"
done
```

---

## Conformité 100%

| Contraintes | Statut |
| :--- | :--- |
| Fichier unique `tree.c` | ✅ |
| Pas de `main()` dans le rendu final | ✅ |
| Seulement `my_putchar` | ✅ |
| Pas de fichiers inutiles (binaires, etc.) | ✅ |
| Fonctions à responsabilité unique | ✅ |
| Style de code (Coding Style) | ✅ |

---

## Structure du Dépôt

```text
CPool_Tree_2026/
├── tree.c      # SEUL fichier à livrer pour le ramassage
├── README.md   # Cette documentation
└── .gitignore  # Exclusion des fichiers temporaires
```

---


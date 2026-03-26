#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

static void print_chars(int n, char c)
{
    while (n-- > 0)
        my_putchar(c);
}

// La clé : Calculer précisément la largeur de la ligne la plus basse
static int get_max_width(int size)
{
    int width = 1;
    int section_height = 4;
    for (int i = 1; i <= size; i++)
    {
        width += 2 * (section_height - 1);
        if (i < size)
        {
            width -= 2 * ((i + 2) / 2);
        }
        section_height++;
    }
    return width;
}

void tree(int size)
{
    if (size <= 0)
        return;

    int max_width = get_max_width(size);
    int stars = 1;
    int section_height = 4;

    // --- DESSIN DES FEUILLES ---
    for (int i = 1; i <= size; i++)
    {
        for (int line = 0; line < section_height; line++)
        {
            int spaces = (max_width - stars) / 2;
            print_chars(spaces, ' ');
            print_chars(stars, '*');
            my_putchar('\n');
            stars += 2;
        }
        // Calcul du "saut" en arrière pour l'étage suivant
        section_height++;
        stars -= 2 * ((i + 2) / 2 + 1);
    }

    // --- DESSIN DU TRONC ---
    int trunk_w = (size % 2 == 0) ? size + 1 : size;
    for (int i = 0; i < size; i++)
    {
        print_chars((max_width - trunk_w) / 2, ' ');
        print_chars(trunk_w, '|');
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    tree(atoi(argv[1]));
    return 0;
}
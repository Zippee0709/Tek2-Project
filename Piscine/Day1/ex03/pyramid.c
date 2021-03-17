/*
** EPITECH PROJECT, 2020
** pyramid.c
** File description:
** pyramid.c
*/

int pyramid_calc(int size, const int **tab, int x, int y)
{
    int new_x;
    int new_y;

    if (size == x)
        return (0);
    new_x = tab[x][y] + pyramid_calc(size, tab, x + 1, y);
    new_y = tab[x][y] + pyramid_calc(size, tab, x + 1, y + 1);
    if (new_x < new_y) {
        printf("check bigger\n");
        return (new_x);
    }
    return (new_y);
}

int pyramid_path(int size, int **tab)
{
    printf("C'est partie\n");
    int res = pyramid_calc(size, tab, 0, 0);
    printf("res = %d\n", res);
    return (res);
}

int main(void)
{
    int **tab;
    // int **tab = tab[5][5];
    // tab = { 
    //     {0},
    //     {7, 2}, 
    //     {2, 3, 6}, 
    //     {8, 5, 9, 3}
    //     };
    pyramid_path(4, tab);
    return (0);
}
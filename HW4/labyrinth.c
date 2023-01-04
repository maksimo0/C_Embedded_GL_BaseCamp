#include "labyrinth.h"

void labyrinth_print(int arr[SIZE][SIZE])
{  
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n\n");
    }
}

int find_exit(int x, int y, int lab[SIZE][SIZE], int sol[SIZE][SIZE])
{
    if ((x == SIZE - 1) /*&& (y == 5)*/ && lab[SIZE - 1][y] == 1) {
        sol[x][y] = 1;
        return 1;
    }
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && lab[x][y] == 1 && sol[x][y] == 0) {
        sol[x][y] = 1;
        if (find_exit(x + 1, y, lab, sol)) {
            return 1;
        }
        if (find_exit(x, y + 1, lab, sol)) {
            return 1;
        }
        if (find_exit(x - 1, y, lab, sol)) {
            return 1;
        }
        if (find_exit(x, y - 1, lab, sol)) {
            return 1;
        }
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}
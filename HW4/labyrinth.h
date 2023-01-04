#include <stdio.h>

#define SIZE 11

void labyrinth_print(int arr[SIZE][SIZE]);
int find_exit(int x, int y, int lab[SIZE][SIZE], int sol[SIZE][SIZE]);
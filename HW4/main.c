#include "labyrinth.h"

int main(void)
{
    int labyrinth[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    int solution[SIZE][SIZE] = {0};

    if (find_exit(0, 5, labyrinth, solution)) {
        printf("Labyrinth:\n");
        labyrinth_print(labyrinth);
        printf("\nSolution:\n");
        labyrinth_print(solution);
    } else {
        printf("There is no way out of the labyrinth!");
    }
    
    return 0;
}

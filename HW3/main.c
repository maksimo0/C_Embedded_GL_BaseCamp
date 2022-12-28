#include <stdio.h>
#include "book.h"

int main(void) {
    struct book book_1, book_2, book_3, book_4, book_5, book_6, book_7;

    book_init(&book_1, "Harry Potter: Philosopher's Stone", 23.99, 223, "English", 0.40, 1997);
    book_init(&book_2, "Harry Potter: Chamber of Secrets", 23.84, 251, "English", 0.42, 1998);
    book_init(&book_3, "Harry Potter: Prisoner of Azkaban", 21.56, 317, "English", 0.40, 1999);
    book_init(&book_4, "Harry Potter: Goblet of Fire", 25.45, 636, "English", 0.75, 2000);
    book_init(&book_5, "Harry Potter: Order of the Phoenix", 24.73, 766, "English", 0.85, 2003);
    book_init(&book_6, "Harry Potter: Half-Blood Prince", 24.85, 607, "English", 0.55, 2005);
    book_init(&book_7, "Harry Potter: Deathly Hallows", 23.71, 607, "English", 0.68, 2007);

    book_link(&book_1, &book_2);
    book_link(&book_2, &book_3);
    book_link(&book_3, &book_4);
    book_link(&book_4, &book_5);
    book_link(&book_5, &book_6);
    book_link(&book_6, &book_7);
    book_link(&book_7, NULL);

    book_print_all(&book_1);
    
    return 0;
}
#include <stdio.h>
#include "book.h"

void book_init(struct book *this, const char *title, float price, 
                unsigned short pages, const char *language, 
                float weight, unsigned short year)
{
    this->title =       title;
    this->price =       price;
    this->pages =       pages;
    this->language =    language;
    this->weight =      weight;
    this->year =        year;
}

void book_link(struct book *this, struct book *other) 
{
    this->next = other;
}

void book_print(struct book *this)
{
    printf("Book title - %s\n", this->title);
    printf("Price: %.2f\n", this->price);
    printf("Number of pages: %u\n", this->pages);
    printf("Language: %s\n", this->language);
    printf("Weight: %.2f kg\n", this->weight);
    printf("Year: %u\n\n", this->year);
}

void book_print_all(struct book *this) 
{

    for (; this != NULL; this = this->next)
        book_print(this);
}
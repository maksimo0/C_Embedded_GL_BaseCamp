#pragma once

struct book {
    const char      *title;
    float           price;
    unsigned short  pages;
    const char      *language;
    float           weight;
    unsigned short  year;
    struct book     *next;
};

void book_init(struct book *this, const char *title, float price, 
                unsigned short pages, const char *language, 
                float weight, unsigned short year);
void book_link(struct book *this, struct book *other);
void book_print(struct book *this);
void book_print_all(struct book *this);
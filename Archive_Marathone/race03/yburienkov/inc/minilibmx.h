#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct cards {
    int rank;
    char suit;
} card;

enum suit {
    clubs,
    diamonds,
    hearts,
    spades
};

enum rank {
    two=2,
    three=3,
    four=4,
    five=5,
    six=6,
    seven=7,
    eight=8,
    nine=9,
    ten=10,
    jack=11,
    queen=12,
    king=13,
    ace=14
};

bool mx_isdigit(int c);
bool mx_isspace(char c);
bool mx_isalpha(int c);
int mx_toupper(int c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_atoi(const char *str);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_is_valid_card(const char *s);
void mx_init_card(const char *c, card *c_card);
void mx_printerr(const char *s);
void mx_sort_cards(card **arr, int size);
card *mx_check_dup(card **arr, int size);
bool mx_is_royal_flush(card **hand);
bool mx_is_straight_flush(card **hand);
bool mx_is_four(card **hand);
bool mx_is_full_house(card **hand);
bool mx_is_flush(card **hand);
bool mx_is_straight(card **hand);
bool mx_is_three(card **hand);
bool mx_is_two_pair(card **hand);
bool mx_is_two(card **hand);
void mx_comb_finder(card **hand);
void mx_rank_to_str(int rank, char suit, char *container);

#endif

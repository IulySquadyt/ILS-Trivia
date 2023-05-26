#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_NAME_LENGTH 100
#define MAX_USERS 100

typedef struct intrebare {
    char *text;
    char raspuns1;
    char raspuns2;
    char raspuns3;
    char raspuns4;
    char *text_raspuns1;
    char *text_raspuns2;
    char *text_raspuns3;
    char *text_raspuns4;
    int raspuns_corect[4];
    char *hint;
} Qst;

typedef struct user {
    char *name;
    int score;
} User;

void print_banner();
void print_big_V();
void print_big_X();
void write_your_name();
void print_main_menu();
Qst *read_question(FILE *fptr);
void print_question(Qst *qst);
int check_answer(Qst *qst, char answer);
void print_hint(Qst *qst);
void print_question_50(Qst *qst);
void sort_users(User *users, int nr_users);
void print_leaderboard(User *users, int nr_users);
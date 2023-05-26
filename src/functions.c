#include "functions.h"

void print_banner()
{
    printf("==================================================================================================\n");
    printf("                _  _      ____       ______  ______  _ __      __ _     __                        \n");
    printf("               | || |    | ___|     |_    _|| .--. || |\\ \\    / /| |   /  \\                    \n");
    printf("               | || |    |___ \\       |  |  | '--'_|| | \\ \\  / / | |  / /\\ \\                 \n");
    printf("               | || |___  ___) |      |  |  |  |\\ \\ | |  \\ \\/ /  | | / ____ \\                \n");
    printf("               |_||_____||____/       |__|  |__| \\_\\|_|   \\__/   |_|/_/    \\_\\               \n");
    printf("                                                                                                  \n");
    printf("==================================================================================================\n");
}

void write_your_name()
{
    printf("\nWrite your name: ");
}

void print_main_menu()
{
    printf("==================================================================================================\n");
    printf("\n");
    printf("1. Start Game\n");
    printf("2. See Leaderboard\n");
    printf("3. Exit\n");
    printf("\n");
}

void print_big_V()
{
    printf(" _       _   \n");
    printf(" \\\\     //    \n");
    printf("  \\\\   //      \n");
    printf("   \\\\ //       \n");
    printf("    \\_/          \n");
}

void print_big_X()
{
    printf("\\       /\n");
    printf(" \\     /\n");
    printf("  \\   /\n");
    printf("   \\ /\n");
    printf("    X\n");
    printf("   / \\\n");
    printf("  /   \\\n");
    printf(" /     \\\n");
    printf("/       \\\n");

}

// functie de citire a unei intrebari din fisier

Qst *read_question(FILE *fptr)
{
    Qst *qst = (Qst *)malloc(sizeof(Qst));
    char *line = (char *)malloc(BUFFER_SIZE * sizeof(char));
    fgets(line, BUFFER_SIZE, fptr);
    qst->text = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->text, line);
    // citesc raspunsurile
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns1 = line[0];
    qst->text_raspuns1 = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->text_raspuns1, line + 2);
    // cistesc valoarea intreaga care imi indica daca raspunsul este corect
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns_corect[0] = atoi(line);
    // citesc restul raspunsurilor
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns2 = line[0];
    qst->text_raspuns2 = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->text_raspuns2, line + 2);
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns_corect[1] = atoi(line);
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns3 = line[0];
    qst->text_raspuns3 = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->text_raspuns3, line + 2);
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns_corect[2] = atoi(line);
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns4 = line[0];
    qst->text_raspuns4 = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->text_raspuns4, line + 2);
    fgets(line, BUFFER_SIZE, fptr);
    qst->raspuns_corect[3] = atoi(line);
    fgets(line, BUFFER_SIZE, fptr);
    qst->hint = (char *)malloc(BUFFER_SIZE * sizeof(char));
    strcpy(qst->hint, line);
    free(line);
    return qst;
}

// functie de afisare a unei intrebari

void print_question(Qst *qst)
{
    printf("%s", qst->text);
    printf("\n");
    printf("%c) %s", qst->raspuns1, qst->text_raspuns1);
    printf("%c) %s", qst->raspuns2, qst->text_raspuns2);
    printf("%c) %s", qst->raspuns3, qst->text_raspuns3);
    printf("%c) %s", qst->raspuns4, qst->text_raspuns4);
    printf("\n");
}

// functie de afisare a unui hint

void print_hint(Qst *qst)
{
    printf("%s", qst->hint);
    printf("\n");
}

// functie de afisare a intrebarii, dar fara 2 raspunsuri gresite

void print_question_50(Qst *qst)
{
    printf("%s", qst->text);
    printf("\n");
    int nr = 2;
    if(qst->raspuns_corect[0] == 0)
    {
        nr--;
    } else {
        printf("%c) %s", qst->raspuns1, qst->text_raspuns1);
    }
    if(qst->raspuns_corect[1] == 0)
    {
        nr--;
    } else {
        printf("%c) %s", qst->raspuns2, qst->text_raspuns2);
    }
    if (nr == 0) {
        printf("%c) %s", qst->raspuns3, qst->text_raspuns3);
    } else if(qst->raspuns_corect[2] == 0)
    {
        nr--;
    } else {
        printf("%c) %s", qst->raspuns3, qst->text_raspuns3);
    }
    if (nr == 0) {
        printf("%c) %s", qst->raspuns4, qst->text_raspuns4);
    } else if(qst->raspuns_corect[3] == 0)
    {
        nr--;
    } else {
        printf("%c) %s", qst->raspuns4, qst->text_raspuns4);
    }
    printf("\n");
}
// functie de verificare a raspunsului

int check_answer(Qst *qst, char answer)
{
    printf("The answer is ");
    if (answer == qst->raspuns1 && qst->raspuns_corect[0] == 1) {
        sleep(5);
        printf("correct!\n");
        return 1;
    }
    if (answer == qst->raspuns2 && qst->raspuns_corect[1] == 1) {
        sleep(5);
        printf("correct!\n");
        return 1;
    }
    if (answer == qst->raspuns3 && qst->raspuns_corect[2] == 1) {
        sleep(5);
        printf("correct!\n");
        return 1;
    }
    if (answer == qst->raspuns4 && qst->raspuns_corect[3] == 1) {
        sleep(5);
        printf("correct!\n");
        return 1;
    }
    sleep(5);
    printf("incorrect!\n");
    return 0;
}

// functie de sortare a userilor in functie de scor

void sort_users(User *users, int nr_users)
{
    int i, j;
    User aux;
    for (i = 0; i < nr_users - 1; i++)
        for (j = i + 1; j < nr_users; j++)
            if (users[i].score < users[j].score)
            {
                aux = users[i];
                users[i] = users[j];
                users[j] = aux;
            }
}

// functie de afisare a clasamentului

void print_leaderboard(User *users, int nr_users)
{
    int i;
    printf("Leaderboard:\n\n");
    for (i = 0; i < nr_users; i++)
    {
        printf("%d. %s - %d points\n", i + 1, users[i].name, users[i].score);
    }
}
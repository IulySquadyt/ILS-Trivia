#include "functions.h"

int main() {
    char *name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    int option;
    int nr_users = 0;
    User *user = malloc(MAX_USERS * sizeof(User));
    // numele primului user se introduce in primul element al vectorului
    for(int i = 0; i < MAX_USERS; i++) {
        user[i].name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    }
    int score = 0;
        int variante_ajutor[2] = {2, 2};
        char **nume_ajutor = malloc(2 * sizeof(char *));
        for(int i = 0; i < 2; i++) {
            nume_ajutor[i] = malloc(10 * sizeof(char));
        }
        strcpy(nume_ajutor[0], "50/50");
        strcpy(nume_ajutor[1], "Hint");
        int prag[25] = {100, 200, 300, 400, 500, 1000, 2000, 3000, 4000, 
                        5000, 10000, 20000, 30000, 40000, 50000, 100000,
                        200000, 300000, 400000, 500000, 1000000, 2000000,
                        3000000, 4000000, 5000000};
    
    int nr_intrebari = 25;
    // afiseaza bannerul

    print_banner();
    // cere numele jucatorului
    write_your_name();
    scanf(" %[^\n]s", name);
    printf("Hello, %s!\n", name);
    strcpy(user[0].name, name);
    printf("\n");
    // afiseaza meniul principal
    print_main_menu();
    
    printf("Choose option: ");
    scanf("%d", &option);
    printf("\n");
    
    while(option != 3 && nr_users <= MAX_USERS) {
        if(option == 1) {
            // incepe jocul
            printf("========================================\n\n");
            printf("Game started!\n");
            printf("\n");
            printf("Your score right now is: %d\n", score);
            printf("\n");
            // deschid fisierul cu intrebari
            FILE *fptr = fopen("intrebari.txt", "r");
            if(fptr == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            int j = 0;
            while(j < nr_intrebari) {
                
                char raspuns_ajutor;
                // citesc o intrebare
                Qst *qst = read_question(fptr);
                if(qst == NULL) {
                    break;
                }
                // afisez intrebarea
                print_question(qst);
                
                // intreb daca vrea ajutor
                if(variante_ajutor[0] > 0 || variante_ajutor[1] > 0) {
                    printf("Wanna use a lifeline?\n");
                    // afisez variantele de ajutor
                    printf("Lifelines:\n");
                    for(int i = 0; i < 2; i++) {
                        printf("%d. %s %d\n", i + 1, nume_ajutor[i], 
                        variante_ajutor[i]);
                    }
                    printf("y/n: ");
                    scanf(" %c", &raspuns_ajutor);
                    printf("\n");
                    if(raspuns_ajutor == 'y') {
                        int option;
                        if(variante_ajutor[1] <= 0 && variante_ajutor[0] > 0) {
                            option = 1;
                        } else if (variante_ajutor[1] > 0 && variante_ajutor[0] <= 0) {
                            option = 2;
                        } else {
                            printf("Choose lifeline: ");
                            scanf("%d", &option);
                            printf("\n");
                        }
                        // scad numarul de variante de ajutor
                        variante_ajutor[option - 1]--;
                        // afisez ajutorul
                        if(option == 1) {
                            print_question_50(qst);
                        } else {
                            printf("Hint: ");
                            print_hint(qst);
                        }
                    }
                } else {
                    printf("No more lifelines!\n\n");
                }
                // citesc raspunsul
                char raspuns;
                printf("Your answer is: ");
                scanf(" %c", &raspuns);
                printf("\n");
                // verific raspunsul
                if(check_answer(qst, raspuns)) {
                    score = prag[j];
                    print_big_V();
                    printf("\nYour score right now is: %d\n\n", score);
                    printf("========================================\n\n");
                    j++;
                    printf("\n");
                } else {
                    printf("\n");
                    print_big_X();
                    printf("\nYour final score is: %d\n", score);
                    printf("Congratulations!\n");
                    printf("\n");
                    user[nr_users].score = score;
                    nr_users++;
                    free(qst->text);
                    free(qst->text_raspuns1);
                    free(qst->text_raspuns2);
                    free(qst->text_raspuns3);
                    free(qst->text_raspuns4);
                    free(qst->hint);
                    free(qst);
                    break;
                }
                free(qst->text);
                free(qst->text_raspuns1);
                free(qst->text_raspuns2);
                free(qst->text_raspuns3);
                free(qst->text_raspuns4);
                free(qst->hint);
                free(qst);
                sleep(5);
            }
            if(j == nr_intrebari) {
                printf("Your final score is: %d\n", score);
                printf("YOU ARE THE GRAND CHAMPION!!\n");
                printf("\n");
                user[nr_users].score = score;
                nr_users++;
                printf("\n");
            }
            fclose(fptr);
            // se introduce un nou jucator
            printf("Game ended!\n\n");
            printf("========================================\n\n");
            write_your_name();
            scanf(" %[^\n]s", name);
            printf("Hello, %s!\n", name);
            strcpy(user[nr_users].name, name);
            printf("\n");

        } else if(option == 2) {
            if(nr_users == 0) {
                printf("No players!\n");
                printf("\n");
                // afiseaza mesaj de eroare
                print_main_menu();
                printf("Choose option: ");
                scanf("%d", &option);
                printf("\n");
                continue;
            }
            printf("\n");
            printf("========================================\n\n");
            // se sorteaza jucatorii
            sort_users(user, nr_users);
            // afiseaza clasamentul
            print_leaderboard(user, nr_users);
            printf("\n");
            printf("========================================\n\n");
            // afiseaza meniul principal
            print_main_menu();

        } else if(option == 3) {
            
            // se elibereaza memoria alocata dinamic si se inchide programul
            free(name);
            for(int i = 0; i <= nr_users; i++) {
                free(user[i].name);
            }
            free(user);
            for(int i = 0; i < 2; i++) {
                free(nume_ajutor[i]);
            }
            free(nume_ajutor);

            return 0;
        
        } else {
           
            printf("Invalid option!\n");
            printf("\n");
            // afiseaza mesaj de eroare
        }
        print_main_menu();
        printf("Choose option: ");
        scanf("%d", &option);
        printf("\n");
    }

    // se elibereaza memoria alocata dinamic si se inchide programul
    free(name);
    for(int i = 0; i <= MAX_USERS; i++) {
        free(user[i].name);
    }
    free(user);
    for(int i = 0; i < 2; i++) {
        free(nume_ajutor[i]);
    }
    free(nume_ajutor);
    return 0;
}

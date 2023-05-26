# ILS-Trivia
Cel mai smecher joc de cultura generala

Ideea proiectului consta in realizarea unui joc de cultura generala distractiv utilizand concepte ale limbajului C.
Aplicatia incepe cu introducerea username-ului, intrarea in meniu si selectarea optiunilor.
La prima iterarie nu va exista un leaderboard deoarece nu exista inca recorduri, 
desi optiunea de afisare apare in meniu (se va afisa un mesaj corespunzator).
Cand incepe jocul, vor fi afisate scorul curent, prima intrebare, variantele de raspuns si optiunile de variante ajutatoare. 
Jucatorul va fi intrebat daca doreste o varianta ajutatoare. Daca da, o va selecta si va primi un hint sau 50/50, 
numarul variantelor ajutatoare fiind decrementat la urmatoarea iteratie, daca nu, se cere pur si simplu raspunsul. 
De precizat ca atunci cand nu mai e disponibil un lifeline de un tip, se va allege automat cel disponibil.
Un raspuns corect inseamna cresterea scorului si trecerea la urmatoarea intrebare, cu aceleasi optiuni ca si cea precedenta. 
Un raspuns gresit inseamna incheierea jocului. La incheierea jocului, numele si scorul jucatorului 
vor fi introduce in leaderboard, care va putea fi vizualizat de catre urmatorul user.

Explicarea codului: 

Se printeaza un banner si se cere introducerea numelui utilizatorului, o varabila string alocata dinamic, 
care va fi introdusa in campul name al primului element din vectorul user (de tip User). 
Se declara un vector int pentru contorizarea variantelor de ajutor disponibile, si de asemenea un vector de 
stringuri pentru afisarea disponibilitatii acestor variante. Iau de asemenea un vector cu 25 de elemente 
intregi, reprezentand pragurile fiecarei intrebari. Din acest vector se vor lua valori pentru actualizarea 
scorului Pentru evitarea unor buguri, am citit stringul nume ca orice caracter pana la intalnirea lui \n.
Variabila intreaga option indica optiunea din meniu aleasa de jucator. Daca valoarea intreaga nu este 
o optiune din meniu, se va afisa un mesaj corespunzator.

1. Start Game:

Se afiseaza scorul curent, cu toate ca nu e necesar fiindca e 0.
Se va intra intr-un loop de intrebari, care se va incheia o data ce s-au terminat intrebarile.
Se declara o variabila de tip Qst pointer pentru a retine datele intrebarii, apoi se afiseaza pe ecran, 
impreuna cu optiunea de a alege un lifeline. Se va introduce caracterul ‘y’ pentru da sau oricare altul pentru nu.
In cazul in care s-a ales optiunea da, se va cere un input pentru variabila intreaga option pentru a stabili 
care din cele 2 variante a fost aleasa. Pentru acea varianta se va decrementa elementul din vectorul 
variante_ajutor si se va afisa ajutorul. In cazul in care nu mai exista posibilitatea de a alege una dintre variante, 
se alege automat cealalta, iar daca nu e niciuna disponibila, se afiseaza un mesaj si nu se mai ofera optiunea.
Dupa aceasta, se va cere raspunsul final al jucatorului sub forma unui caracter. Daca acel caracter introdus de jucator 
coincide cu cel corespunzator campului din variabila qst, raspunsul este corect, se afiseaza scorul curent, are loc 
un delay de 5 secunde pentru vizualizarea rapida a rezultatului si se trece la intrebarea urmatoare, cu aceleasi optiuni.
Daca nu coincide, se va iesi din loop, se afiseaza scorul curent si se introduce in leaderboard, revenind la meniul 
principal dupa ce s-a introdus un nou username.
De mentionat ca intre introducerea raspunsului si afisarea rezultatului este un delay de 5 secunde pentru suspans.
Cel care a raspuns corect la toate intrebarile va primi un mesaj special.
La terminarea jocului se elibereaza memoria alocata pentru variabila intrebare.

2. Leaderboard:

Se foloseste o functie externa de sortare a vectorului curent de useri pentru afisarea lor de la cel mai bun la cel mai rau.
Se afiseaza vectorul sub forma unui leaderboard.
Se revine in meniul principal.

3. Exit:

Se elibereaza toata memoria alocata si se inchide programul.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//zad1----------------------------------------------------------------
typedef struct {
    char* imie;
    char* nazwisko;
    char* nrTelefonu;
} Contact;

Contact** ksiazkaAdresowa = NULL;
int liczbaKontaktow = 0;

void dodajKontakt() {
    ksiazkaAdresowa = realloc(ksiazkaAdresowa, (liczbaKontaktow + 1) * sizeof(Contact*));
    ksiazkaAdresowa[liczbaKontaktow] = malloc(sizeof(Contact));

    ksiazkaAdresowa[liczbaKontaktow]->imie = malloc(50 * sizeof(char));
    ksiazkaAdresowa[liczbaKontaktow]->nazwisko = malloc(50 * sizeof(char));
    ksiazkaAdresowa[liczbaKontaktow]->nrTelefonu = malloc(20 * sizeof(char));

    printf("Podaj imię: ");
    scanf("%s", ksiazkaAdresowa[liczbaKontaktow]->imie);
    printf("Podaj nazwisko: ");
    scanf("%s", ksiazkaAdresowa[liczbaKontaktow]->nazwisko);
    printf("Podaj numer telefonu: ");
    scanf("%s", ksiazkaAdresowa[liczbaKontaktow]->nrTelefonu);

    liczbaKontaktow++;
    printf("Kontakt dodany pomyślnie!\n");
}

void wyszukajKontakt() {
    char nazwisko[50];
    printf("Podaj nazwisko kontaktu do wyszukania: ");
    scanf("%s", nazwisko);

    int znaleziony = 0;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i]->nazwisko, nazwisko) == 0) {
            printf("Znaleziony kontakt: %s %s, Telefon: %s\n",
                   ksiazkaAdresowa[i]->imie, ksiazkaAdresowa[i]->nazwisko, ksiazkaAdresowa[i]->nrTelefonu);
            znaleziony = 1;
        }
    }

    if (!znaleziony) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", nazwisko);
    }
}

void usunKontakt() {
    char nazwisko[50];
    printf("Podaj nazwisko kontaktu do usunięcia: ");
    scanf("%s", nazwisko);

    int znaleziony = -1;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i]->nazwisko, nazwisko) == 0) {
            znaleziony = i;
            break;
        }
    }

    if (znaleziony != -1) {
        free(ksiazkaAdresowa[znaleziony]->imie);
        free(ksiazkaAdresowa[znaleziony]->nazwisko);
        free(ksiazkaAdresowa[znaleziony]->nrTelefonu);
        free(ksiazkaAdresowa[znaleziony]);

        for (int i = znaleziony; i < liczbaKontaktow - 1; i++) {
            ksiazkaAdresowa[i] = ksiazkaAdresowa[i + 1];
        }

        liczbaKontaktow--;
        ksiazkaAdresowa = realloc(ksiazkaAdresowa, liczbaKontaktow * sizeof(Contact*));

        printf("Kontakt o nazwisku %s został usunięty.\n", nazwisko);
    } else {
        printf("Nie znaleziono kontaktu do usunięcia o nazwisku %s.\n", nazwisko);
    }
}


void wypiszWszystkieKontakty() {
    if (liczbaKontaktow == 0) {
        printf("Brak zapisanych kontaktów w książce adresowej.\n");
    } else {
        printf("\nLista kontaktów:\n");
        for (int i = 0; i < liczbaKontaktow; i++) {
            printf("%d. %s %s, Telefon: %s\n", i + 1, 
                   ksiazkaAdresowa[i]->imie, ksiazkaAdresowa[i]->nazwisko, ksiazkaAdresowa[i]->nrTelefonu);
        }
    }
}

void freeMemory() {
    for (int i = 0; i < liczbaKontaktow; i++) {
        free(ksiazkaAdresowa[i]->imie);
        free(ksiazkaAdresowa[i]->nazwisko);
        free(ksiazkaAdresowa[i]->nrTelefonu);
        free(ksiazkaAdresowa[i]);
    }
    free(ksiazkaAdresowa);
}

int main()
{
    char* imiona[] = {"Mariusz", "Robert", "Adam"};
    char* nazwiska[] = {"Pudzianowski", "Kubica", "Małysz"};
    char* numery[] = {"123456789", "987654321", "135792468"};

    for (int i = 0; i < 3; i++) {
        ksiazkaAdresowa = realloc(ksiazkaAdresowa, (liczbaKontaktow + 1) * sizeof(Contact*));
        ksiazkaAdresowa[liczbaKontaktow] = malloc(sizeof(Contact));

        ksiazkaAdresowa[liczbaKontaktow]->imie = strdup(imiona[i]);
        ksiazkaAdresowa[liczbaKontaktow]->nazwisko = strdup(nazwiska[i]);
        ksiazkaAdresowa[liczbaKontaktow]->nrTelefonu = strdup(numery[i]);

        liczbaKontaktow++;
    }
    wypiszWszystkieKontakty();

    printf("\nDodawanie nowego kontaktu:\n");
    dodajKontakt();

    printf("\nWyszukiwanie kontaktu:\n");
    wyszukajKontakt();

    printf("\nUsuwanie kontaktu:\n");
    usunKontakt();

    printf("\nPo modyfikacjach:\n");
    wypiszWszystkieKontakty();
}


//zad2------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void trojkatPascala(int N) {
    if (N <= 0) {
        printf("Wysokość musi być większa niż 0!\n");
        return;
    }

    int *poprzedni = (int*)malloc(sizeof(int));
    int *obecny = NULL;

    poprzedni[0] = 1;

    printf("1\n");

    for (int i = 1; i < N; i++) {
        obecny = (int*)malloc((i + 1) * sizeof(int));
        obecny[0] = obecny[i] = 1;

        for (int j = 1; j < i; j++) {
            obecny[j] = poprzedni[j - 1] + poprzedni[j];
        }

        for (int j = 0; j <= i; j++) {
            printf("%d ", obecny[j]);
        }
        printf("\n");

        free(poprzedni);
        poprzedni = obecny;
    }

    free(obecny);
}

int main() {
    int N;
    printf("Podaj wysokość Trójkąta Pascala: ");
    scanf("%d", &N);

    trojkatPascala(N);

    return 0;
}
//zad3-------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alokujMacierz(int wiersze, int kolumny) {
    int **macierz = (int**)malloc(wiersze * sizeof(int*));
    if (macierz == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(1);
    }

    for (int i = 0; i < wiersze; i++) {
        macierz[i] = (int*)malloc(kolumny * sizeof(int));
        if (macierz[i] == NULL) {
            printf("Błąd alokacji pamięci!\n");
            exit(1);
        }
    }

    return macierz;
}

void wypelnijMacierz(int **macierz, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % 100;
        }
    }
}

void wyswietlMacierz(int **macierz, int wiersze, int kolumny) {
    printf("\nMacierz %dx%d:\n", wiersze, kolumny);
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%3d ", macierz[i][j]);
        }
        printf("\n");
    }
}

void zwolnijMacierz(int **macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
}

int main() {
    int wiersze, kolumny;

    printf("Podaj liczbę wierszy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbę kolumn: ");
    scanf("%d", &kolumny);

    srand(time(NULL));

    int **macierz = alokujMacierz(wiersze, kolumny);
    wypelnijMacierz(macierz, wiersze, kolumny);
    wyswietlMacierz(macierz, wiersze, kolumny);

    zwolnijMacierz(macierz, wiersze);

    return 0;
}

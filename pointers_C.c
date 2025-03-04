
#include <stdio.h>
#include <string.h>
#define MAX_KONTAKTY 100

//zad 2---------------------------------------------------------
void podwojWartosc(float *wsk) {
    *wsk *= 2;
}

//zad 3---------------------------------------------------------
typedef struct {
    float x;
    float y;
} Point;

void zmienWspolrzedne(Point *p, float noweX, float noweY) {
    (*p).x = noweX;
    (*p).y = noweY;
}

typedef struct {
    float szerokosc;
    float wysokosc;
} Rectangle;

void obliczPoleObwod(Rectangle r, float *pole, float *obwod) {
    *pole = r.szerokosc * r.wysokosc;
    *obwod = 2 * (r.szerokosc + r.wysokosc);
}

//zad 4----------------------------------------------------------------
typedef struct {
    char imie[50];
    float ocena;
} Student;

void sortujStudentow(Student *tablica, int rozmiar) {
    Student temp;
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - 1 - i; j++) {
            if (tablica[j].ocena < tablica[j + 1].ocena) {
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}



//zad 5-------------------------------------------------------------------------
typedef struct{
    char imie[50];
    char nazwisko[50];
    char nrTelefonu[20];
} Contact;

Contact ksiazkaAdresowa[MAX_KONTAKTY] = {
        {"Mariusz", "Pudzianowski", "123456789"},{"Robert", "Kubica", "987654321"}, {"Adam", "Małysz", "135792468"}
    };
int liczbaKontaktow = 3;

void dodajKontakt() {
    if (liczbaKontaktow < MAX_KONTAKTY) {
        Contact nowyKontakt;
        printf("Podaj imię: ");
        scanf("%s", nowyKontakt.imie);
        printf("Podaj nazwisko: ");
        scanf("%s", nowyKontakt.nazwisko);
        printf("Podaj numer telefonu: ");
        scanf("%s", nowyKontakt.nrTelefonu);

        ksiazkaAdresowa[liczbaKontaktow] = nowyKontakt;
        liczbaKontaktow++;
        printf("Kontakt dodany pomyślnie!\n");
    } else {
        printf("Brak miejsca na nowy kontakt w książce adresowej.\n");
    }
}

void wyszukajKontakt() {
    char nazwisko[50];
    printf("Podaj nazwisko kontaktu do wyszukania: ");
    scanf("%s", nazwisko);

    int znaleziony = 0;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziony kontakt: %s %s, Telefon: %s\n", ksiazkaAdresowa[i].imie, ksiazkaAdresowa[i].nazwisko, ksiazkaAdresowa[i].nrTelefonu);
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

    int znaleziony = 0;
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(ksiazkaAdresowa[i].nazwisko, nazwisko) == 0) {
            for (int j = i; j < liczbaKontaktow - 1; j++) {
                ksiazkaAdresowa[j] = ksiazkaAdresowa[j + 1];
            }
            liczbaKontaktow--;
            printf("Kontakt o nazwisku %s został usunięty.\n", nazwisko);
            znaleziony = 1;
            break;
        }
    }

    if (!znaleziony) {
        printf("Nie znaleziono kontaktu do usunięcia o nazwisku %s.\n", nazwisko);
    }
}

void wypiszWszystkieKontakty() {
    if (liczbaKontaktow == 0) {
        printf("Brak zapisanych kontaktów w książce adresowej.\n");
    } else {
        printf("\nLista kontaktów:\n");
        for (int i = 0; i < liczbaKontaktow; i++) {
            printf("%d. %s %s, Telefon: %s\n", i + 1, ksiazkaAdresowa[i].imie, ksiazkaAdresowa[i].nazwisko, ksiazkaAdresowa[i].nrTelefonu);
        }
    }
}

int main() {

//zad 1----------------------------------------------------------------------------------
    int x = 1;
    int *pointer = &x;
    *pointer = 100;

    printf("Wartosc zmiennej bezposrednio: %d\n", x);
    printf("Wartosc zmiennej przez wskaznik: %d\n", *pointer);

//zad 2---------------------------------------------------------------------
    float x2 = 5.5;
    printf("Przed modyfikacja: %.2f\n", x2);

    podwojWartosc(&x2);

    printf("Po modyfikacji: %.2f\n", x2);
    
//zad 3---------------------------------------------------------------------
    Point p = {1.0, 2.0};
    printf("Przed zmiana: x = %.2f, y = %.2f\n", p.x, p.y);

    zmienWspolrzedne(&p, 3.0, 4.0);
    printf("Po zmianie: x = %.2f, y = %.2f\n", p.x, p.y);

    Rectangle rect = {5.0, 10.0};
    float pole, obwod;
    
    obliczPoleObwod(rect, &pole, &obwod);
    printf("Prostokat: szerokosc = %.2f, wysokosc = %.2f\n", rect.szerokosc, rect.wysokosc);
    printf("Pole = %.2f, Obwod = %.2f\n", pole, obwod);

//zad 4----------------------------------------------------------------
    Student studenci[3] = {
        {"Mariusz Pudzianowski", 6},{"Robert Kubica", 4}, {"Adam Małysz", 5}
    };
    
    int rozmiar = 3;
    sortujStudentow(studenci, rozmiar);

    printf("Po sortowaniu:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%s - %.2f\n", studenci[i].imie, studenci[i].ocena);
    }

//zad 5-------------------------------------------------------------------------
    wypiszWszystkieKontakty();

    printf("\nDodawanie nowego kontaktu:\n");
    dodajKontakt();

    printf("\nWyszukiwanie kontaktu:\n");
    wyszukajKontakt();

    printf("\nUsuwanie kontaktu:\n");
    usunKontakt();

    printf("\nPo modyfikacjach:\n");
    wypiszWszystkieKontakty();
    
    return 0;
}

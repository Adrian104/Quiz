#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pytanie
{
    int odpGracza;
    int odpPoprawna;

    string nazwaPytania;
    string odpowiedz[3];
};

int punkty;
int iloscPytan;
Pytanie *pytania;

void Wczytaj();
void Powitanie();
void ZadajPytania();
void LiczPunkty();
void PrzedstawWynik();
void Posprzataj();

int main()
{
    return 0;
}

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
{
    cout << pytania[0].nazwaPytania << endl;
}
void LiczPunkty();
void PrzedstawWynik();

void Posprzataj()
{
    delete[] pytania;
}

int main()
{
    Posprzataj();
    return 0;
}

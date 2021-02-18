#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

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

void Wczytaj()
{

}

void Powitanie()
{
    cout<<"Witam w Quiz'ie!"<<endl;
    cout<<"Na ekranie wyswietla sie pytania, na ktore musisz odpowiedziec."<<endl;
    cout<<"Na kazde pytanie odpowiedz klikajac jedna z liter: "<<" 'A' lub 'B' lub 'C'."<<endl;
    cout<<"Na koncu dostaniesz informacje ile punktow zdobyles/as!"<<endl;
    cout<<"Powodzenia!";
}

void ZadajPytania()
{
    cout << pytania[0].nazwaPytania << endl;
}

void LiczPunkty()
{

}

void PrzedstawWynik()
{
    cout<<"Gratulacje ukonczyles/as Quiz!"<<endl;
    cout<<"Twoj wynik to: "<<punkty<<"\n";
    cout<<"Brawo!";
}

void Posprzataj()
{
    delete[] pytania;
}

int main()
{
    // Polskie znaki.
    setlocale(LC_ALL, "polish");

    Wczytaj();
    Powitanie();
    PrzedstawWynik();
    Posprzataj();

    return 0;
}

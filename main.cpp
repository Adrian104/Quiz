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
void Powitanie()
{
    cout<<"Witam w Quiz'ie!"<<endl;
    cout<<"Na ekranie wyswietla sie pytania, na ktore musisz odpowiedziec."<<endl;
    cout<<"Na kazde pytanie odpowiedz klikajac jedna z liter: "<<" 'A' lub 'B' lub 'C'."<<endl;
    cout<<"Na koncu dostaniesz informacje ile punktow zdobyles/as!"<<endl;
    cout<<"Powodzenia!";
}
void ZadajPytania();
{
    cout << pytania[0].nazwaPytania << endl;
}
void LiczPunkty();
void PrzedstawWynik()
{
    cout<<"Gratulacje ukonczyles/as Quiz!"<<endl;
    cout<<"Twoj wynik to: "<<wynik<<"\n";
    cout<<"Brawo!";
}
    

void Posprzataj()
{
    delete[] pytania;
}

int main()
{
    Posprzataj();
    return 0;
}

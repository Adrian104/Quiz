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
{
    count<<"Witam w Quiz'ie!"<<endl;
    count<<"Na ekranie wyswietla sie pytania, na ktore musisz odpowiedziec."<<endl;
    count<<"Na kazde pytanie odpowiedz klikajac jedna z liter: "<<" 'A' lub 'B' lub 'C'."<<endl;
    count<<"Na koncu dostaniesz informacje ile punktow zdobyles/as!"<<endl;
    count<<"Powodzenia!"
}
void ZadajPytania();
{
    cout << pytania[0].nazwaPytania << endl;
}
void LiczPunkty();
void PrzedstawWynik();
{
    count<<"Gratulacje ukonczyles/as Quiz!"<<endl;
    count<<"Twoj wynik to: "<<wynik<<"\n";
    count<<"Brawo!"
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

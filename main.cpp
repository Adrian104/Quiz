#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Pytanie
{
    int odpGracza;
    int odpPoprawna;

    string nazwaPytania;
    string odpowiedz[3];
};

int punkty = 0;
int iloscPytan;
Pytanie *pytania;

void Wczytaj()
{
    std::fstream plik("pytania.txt", std::ios::in);
    if (!plik.good())
    {
        plik.close();
        std::cout << "Nie uda³o siê otworzyæ pliku pytania.txt" << "\n";
        throw 1;
    }

    int iloscLinii = 0;
    std::string linia;

    while (!plik.eof())
    {
        getline(plik, linia);
        if (linia.length() == 0) continue;

        iloscLinii++;
    }

    if (iloscLinii % 5 > 0)
    {
        plik.close();
        std::cout << "Z³y format pliku pytania.txt" << "\n";
        throw 2;
    }

    iloscPytan = iloscLinii / 5;
    pytania = new Pytanie[iloscPytan]{};

    plik.clear();
    plik.seekg(0, std::ios::beg);

    int stan = -1;
    int indeks = 0;

    Pytanie *aktualnePytanie = pytania + indeks;
    while (!plik.eof())
    {
        getline(plik, linia);
        if (linia.length() == 0) continue;

        if (++stan > 4)
        {
            stan = 0;
            aktualnePytanie = pytania + (++indeks);
        }

        switch(stan)
        {
        case 0:
            aktualnePytanie -> nazwaPytania = linia;
            break;

        case 1:
            aktualnePytanie -> odpPoprawna = std::stoi(linia);
            break;

        default:
            aktualnePytanie -> odpowiedz[stan - 2] = linia;
        }
    }

    plik.close();
}

// UWAGA !!!
// Funkcja Wyswietl() jest u¿ywana tylko do testowania quiz-u i zostanie usuniêta w koñcowej wersji.
void Wyswietl()
{
    for (int i = 0; i < iloscPytan; i++)
    {
        cout << "Tytu³ : " << pytania[i].nazwaPytania << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Odp : " << pytania[i].odpowiedz[j];

            if (pytania[i].odpPoprawna == j) cout << " POPRAWNA" << endl;
            else cout << endl;
        }

        cout << endl;
    }

    cout << endl;
}

void Losuj()
{
    for (int cykl = 0; cykl < 5; cykl++)
    {
        for (int i = 0; i < iloscPytan; i++)
        {
            Pytanie &aktualnePytanie = pytania[i];
            Pytanie &losowePytanie = pytania[rand() % iloscPytan];

            Pytanie tymczasowePytanie = losowePytanie;
            losowePytanie = aktualnePytanie;
            aktualnePytanie = tymczasowePytanie;
        }
    }
}

void Powitanie()
{
    cout<<"Witam w Quiz'ie!"<<endl;
    cout<<"Na ekranie wyswietla sie pytania, na ktore musisz odpowiedziec."<<endl;
    cout<<"Na kazde pytanie odpowiedz klikajac jedna z liter: "<<" 'a' lub 'b' lub 'c'."<<endl;
    cout<<"Na koncu dostaniesz informacje ile punktow zdobyles/as!"<<endl;
    cout<<"Powodzenia!" << endl;
}

void ZadajPytania()
{
    char odp;

    for (int i = 0; i < iloscPytan; i++)
    {
        cout << pytania[i].nazwaPytania << endl;

        for(int j = 0; j < 3; j++)
        {
            cout << pytania[i].odpowiedz[j] << endl;
        }

        powtorka:
        cout << "Twoja odpowiedz: ";
        cout << endl;
        cin >> odp;

        if(odp == 97|| odp == 98|| odp == 99)
        {
            pytania[i].odpGracza = odp - 97;
        }
        else
        {
            goto powtorka;
        }
    }
}

void LiczPunkty()
{
    for (int i = 0; i < iloscPytan; i++)
    {
        if (pytania[i].odpGracza == pytania[i].odpPoprawna) punkty++;
    }
}

void PrzedstawWynik()
{
    cout<<"Gratulacje ukonczyles/as Quiz!"<<endl;
    cout<<"Twoj wynik to: "<< punkty <<"\n";
    cout<<"Brawo!";
}

void Posprzataj()
{
    delete[] pytania;
}

int main()
{
    setlocale(LC_ALL, "polish");
    srand(unsigned(time(0)));

    try { Wczytaj(); } catch (int x) { return x; }

    // UWAGA !!!
    // Funkcja Wyswietl() jest u¿ywana tylko do testowania quiz-u i zostanie usuniêta w koñcowej wersji.
    // Wyswietl();

    Losuj();
    Powitanie();
    ZadajPytania();
    LiczPunkty();
    PrzedstawWynik();
    Posprzataj();

    return 0;
}

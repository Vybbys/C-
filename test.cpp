#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int dodawanie(int a, int b)
{

    int wynik = a + b;

    cout << "Wynik dodawania to: " << wynik << endl;
    return wynik;
}

int odejmowanie(int a, int b)
{

    int wynik = a - b;

    cout << "Wynik odejmowania to: " << wynik << endl;
    return wynik;
}

int mnozenie(int a, int b)
{

    int wynik = a * b;

    cout << "Wynik mnozenia to: " << wynik << endl;
    return wynik;
}

int dzielenie(int a, int b)
{

    if (b == 0)
    {
        cout << "Mianowkin nie moze rownac sie 0 !!!" << endl;
        cin >> b;
        while (b == 0)
        {
            cin >> b;
        }
    }

    int wynik = a / b;

    cout << "Wynik dzielenia to: " << wynik << endl;
}

void menu()
{
    cout << "Witaj uzytkowniku! \n Jakie dzialania matematyczne wykonaujemy dzisiaj ? " << endl;

    int wybor;
    int c;
    int d;

    cout << "1. Dodawanie \n"
            "2. Odejmowanie \n"
            "3. Mnozenie \n"
            "4. Dzielenie \n"
            "0. Wyjscie z programu"
         << endl;
    cin >> wybor;

    cout << "Super! Teraz podaj zmienne do obliczenia: \n";
    cin >> c;
    cout << endl;
    cin >> d;

    switch (wybor)
    {

    case 1:
    {

        dodawanie(c, d);
        break;
    }

    case 2:
    {

        odejmowanie(c, d);
        break;
    }

    case 3:
    {

        mnozenie(c, d);
        break;
    }

    case 4:
    {

        dzielenie(c, d);
        break;
    }

    case 0:
    {

        exit;
    }
    }
}

int main()
{

    menu();
}
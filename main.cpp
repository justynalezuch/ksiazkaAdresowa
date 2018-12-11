#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

struct Adresat
{
    int id;
    string imie, nazwisko, nrTelefonu, email, adres;
};

string wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}


void dodajAdres (vector <Adresat> &adresaci, int &idOstatniegoElementu)
{
    string imie, nazwisko, email, adres, nrTelefonu;

    cout<<"Podaj imie: "<<endl;
    imie = wczytajLinie();
    cout<<"Podaj nazwisko: "<<endl;
    nazwisko = wczytajLinie();
    cout<<"Podaj nr telefonu: "<<endl;
    nrTelefonu = wczytajLinie();
    cout<<"Podaj email: "<<endl;
    email = wczytajLinie();
    cout<<"Podaj adres: "<<endl;
    adres = wczytajLinie();

    adresaci.push_back({idOstatniegoElementu+1, imie, nazwisko, nrTelefonu, email, adres});

    fstream plik;
    plik.open("ksiazkaAdresowa.txt", ios::out | ios::app);

    if(plik.good())
    {
        plik<<idOstatniegoElementu+1<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<email<<"|"<<adres<<"|"<<endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }

    cout << endl << "Osoba zostala dodana"<<endl;
    system("pause");

    idOstatniegoElementu++;
}

void wyswietlWszystkieAdresy(vector <Adresat> &adresaci, int idOstatniegoElementu)
{

    for(int i = 0; i< adresaci.size(); i++)
    {
        cout<<endl;
        cout<<"ID: "<<adresaci[i].id<<endl;
        cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
        cout<<"Nr telefonu: "<<adresaci[i].nrTelefonu<<endl;
        cout<<"E-mail: "<<adresaci[i].email<<endl;
        cout<<"Adres: "<<adresaci[i].adres<<endl;
    }

    if(idOstatniegoElementu == 0 )
        cout<<"Nie masz jeszcze adresow w ksiazce"<<endl<<endl;

    system("pause");
}

void wyszukajPoImieniu (vector <Adresat> &adresaci, int idOstatniegoElementu)
{
    bool wyniki = false;
    string imie;
    cout<<"Podaj imie: "<<endl;
    imie = wczytajLinie();

    for(int i = 0; i< adresaci.size(); i++)
    {

        if(adresaci[i].imie == imie)
        {
            cout<<endl;
            cout<<"ID: "<<adresaci[i].id<<endl;
            cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
            cout<<"Nr telefonu: "<<adresaci[i].nrTelefonu<<endl;
            cout<<"E-mail: "<<adresaci[i].email<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;

            wyniki = true;
        }
    }

    if(wyniki == false)
        cout<<"Brak wynikow wyszukiwania dla danego imienia."<<endl<<endl;
    system("pause");
}

void wyszukajPoNazwisku(vector <Adresat> &adresaci, int idOstatniegoElementu)
{
    bool wyniki = false;
    string nazwisko;
    cout<<"Podaj nazwisko: "<<endl;
    nazwisko = wczytajLinie();

    for(int i = 0; i< adresaci.size(); i++)

        if(adresaci[i].nazwisko == nazwisko)
        {
            cout<<endl;
            cout<<"ID: "<<adresaci[i].id<<endl;
            cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
            cout<<"Nr telefonu: "<<adresaci[i].nrTelefonu<<endl;
            cout<<"E-mail: "<<adresaci[i].email<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;

            wyniki = true;
        }

    if(wyniki == false)
        cout<<"Brak wynikow wyszukiwania dla danego nazwiska."<<endl<<endl;
    system("pause");
}


void edytujAdres(vector <Adresat> &adresaci, int idOstatniegoElementu)
{
    bool czyIstnieje = false;
    int idAdresata, wybor;
    string imie, nazwisko, email, adres, nrTelefonu;

    cout<<"Podaj id adresata: "<<endl;
    idAdresata = wczytajLiczbeCalkowita();

    for(int i = 0; i< adresaci.size(); i++)
    {

        if(adresaci[i].id == idAdresata)
        {
            cout<<"1. imie"<<endl;
            cout<<"2. nazwisko"<<endl;
            cout<<"3. numer telefonu"<<endl;
            cout<<"4. email"<<endl;
            cout<<"5. adres"<<endl;
            cout<<"6. powrot do menu"<<endl;

            cout<<"Wybierz dana do edycji:"<<endl;
            wybor = wczytajLiczbeCalkowita();

            switch(wybor)
            {

            case 1:

                cout<<"Podaj imie: "<<endl;
                adresaci[i].imie = wczytajLinie();
                cout<<"Edytowano uzytkownika"<<endl;
                system("pause");
                break;

            case 2:

                cout<<"Podaj nazwisko: "<<endl;
                adresaci[i].nazwisko = wczytajLinie();
                cout<<"Edytowano uzytkownika"<<endl;
                system("pause");
                break;


            case 3:

                cout<<"Podaj numer telefonu: "<<endl;
                adresaci[i].nrTelefonu = wczytajLinie();
                cout<<"Edytowano uzytkownika"<<endl;
                system("pause");
                break;

            case 4:

                cout<<"Podaj email: "<<endl;
                adresaci[i].email = wczytajLinie();
                cout<<"Edytowano uzytkownika"<<endl;
                system("pause");
                break;

            case 5:

                cout<<"Podaj adres: "<<endl;
                adresaci[i].adres = wczytajLinie();
                cout<<"Edytowano uzytkownika"<<endl;
                system("pause");
                break;

            case 6:
                system ("cls");

                break;
            default:
                break;

            }

            fstream plik;
            plik.open("ksiazkaAdresowa.txt", ios::out);

            if(plik.good())
            {
                for(int i = 0; i< adresaci.size(); i++)
                {

                    plik<<adresaci[i].id<<"|"<<adresaci[i].imie<<"|"<<adresaci[i].nazwisko<<"|"<<adresaci[i].nrTelefonu<<"|"<<adresaci[i].email<<"|"<<adresaci[i].adres<<"|"<<endl;

                }


                plik.close();
                czyIstnieje = true;
            }
            else
            {
                cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
                system("pause");
            }


        }
    }
    if(czyIstnieje == false)
    {

        cout<<"Adresat o podanym ID nie istnieje."<<endl;
        system("pause");

    }


}

void usunAdres(vector <Adresat> &adresaci, int &idOstatniegoElementu)
{

    bool czyIstnieje = false;
    int idAdresata, ktoryElement;

    cout<<"Podaj id adresata: "<<endl;
    idAdresata = wczytajLiczbeCalkowita();

    for(int i = 0; i< adresaci.size(); i++)
    {

        if(adresaci[i].id == idAdresata)
        {
            char wybor;
            cout<<"Czy na pewno chcesz usunac ten adres? Wcisnij 't' aby potwierdzic"<<endl;
            cin>> wybor;

            if(wybor == 't')
            {
                adresaci.erase(adresaci.begin()+i);
                czyIstnieje = true;
                cout<<"Usunieto adres"<<endl;
                idOstatniegoElementu = adresaci[adresaci.size()-1].id;
            }
            else
            {
                system("cls");
                return;
            }
        }
    }

    if(czyIstnieje == false)
    {

        cout<<"Nie ma adresu o podanym ID."<<endl;
    }

    if(czyIstnieje == true)
    {

        fstream plik;
        plik.open("ksiazkaAdresowa.txt", ios::out);

        if(plik.good())
        {
            for(int i = 0; i< adresaci.size(); i++)
            {

                plik<<adresaci[i].id<<"|"<<adresaci[i].imie<<"|"<<adresaci[i].nazwisko<<"|"<<adresaci[i].nrTelefonu<<"|"<<adresaci[i].email<<"|"<<adresaci[i].adres<<"|"<<endl;

            }


            plik.close();

        }
        else
        {
            cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
            system("pause");
        }
    }


    system("pause");


}



void wczytajAdresyZPliku (vector <Adresat> &adresaci, int &idOstatniegoElementu)
{
    fstream plik;
    plik.open("ksiazkaAdresowa.txt", ios::in);

    if(plik.good()==false)
        return;
    else
    {
        string slowo;
        int nrLinii=1;
        int id;
        string imie, nazwisko, email, adres, nrTelefonu;


        while(getline(plik, slowo, '|'))
        {

            switch(nrLinii)
            {
            case 1:
                id = atoi( slowo.c_str() );
                break;
            case 2:
                imie = slowo;
                break;
            case 3:
                nazwisko = slowo;
                break;
            case 4:
                nrTelefonu = slowo;
                break;
            case 5:
                email = slowo;
                break;
            case 6:
                adres = slowo;
                break;
            }

            if(nrLinii >= 6)
            {
                nrLinii = 0;
                adresaci.push_back({id, imie, nazwisko, nrTelefonu, email, adres});

            }
            nrLinii++;
        }

        plik.close();
        idOstatniegoElementu = adresaci[adresaci.size()-1].id;

    }
}


int main ()
{

    vector <Adresat> adresaci;
    char wybor;
    int idOstatniegoElementu = 0;

    wczytajAdresyZPliku(adresaci, idOstatniegoElementu);

    while(true)
    {

        system("cls");
        cout<<"KSIAZKA ADRESOWA"<<endl;
        cout<<"1. Dodaj adresata"<<endl;
        cout<<"2. Wyszukaj po imieniu"<<endl;
        cout<<"3. Wyszukaj po nazwisku"<<endl;
        cout<<"4. Wyswietl wszystkich adresatow"<<endl;
        cout<<"5. Usun adresata"<<endl;
        cout<<"6. Edytuj adresata"<<endl;
        cout<<"9. Zakoncz program"<<endl;
        cout<<"Twoj wybor:"<<endl;
        wybor = wczytajZnak();

        if(wybor == '1')
        {
            dodajAdres(adresaci, idOstatniegoElementu);
        }
        if(wybor == '2')
        {
            wyszukajPoImieniu(adresaci, idOstatniegoElementu);

        }
        if(wybor == '3')
        {
            wyszukajPoNazwisku(adresaci, idOstatniegoElementu);
        }
        if(wybor == '4')
        {
            wyswietlWszystkieAdresy(adresaci, idOstatniegoElementu);

        }
        if(wybor == '5')
        {
            usunAdres(adresaci, idOstatniegoElementu);

        }

        if(wybor == '6')
        {
            edytujAdres(adresaci, idOstatniegoElementu);

        }

        if(wybor == '9')
        {
            exit(0);
        }
    }


    return 0;
}



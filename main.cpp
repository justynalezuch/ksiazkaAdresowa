#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <windows.h>
#include <algorithm>


using namespace std;

struct Adresat
{
    int id = 0, idUzytkownika = 0;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";

};

struct Uzytkownik
{
    int id = 0;
    string login = "", haslo = "";

};

string konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();

    return str;
}
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
        if(getline(cin, wejscie))
        {

            if (wejscie.length() == 1)
            {
                znak = wejscie[0];
                break;
            }
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
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

string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{

    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void dopiszAdresataDoPliku(Adresat adresat, string nazwaPliku)
{

    nazwaPliku = nazwaPliku+".txt";
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);

    if (plik.good())
    {
        plik << adresat.id << '|';
        plik << adresat.idUzytkownika << '|';
        plik << adresat.imie << '|';
        plik << adresat.nazwisko << '|';
        plik << adresat.nrTelefonu << '|';
        plik << adresat.email << '|';
        plik << adresat.adres << '|' << endl;
        plik.close();

        cout << endl << "Adresat zostal dodany" << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        system("pause");
    }
}

void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik, string nazwaPliku)
{

    nazwaPliku = nazwaPliku+".txt";
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);

    if (plik.good())
    {
        plik << uzytkownik.id << '|';
        plik << uzytkownik.login << '|';
        plik << uzytkownik.haslo << '|'<<endl;
        plik.close();

        cout << endl << "Konto zalozone!" << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        system("pause");
    }
}

void wyswietlWszystkieAdresy(vector <Adresat> &adresaci)
{
    system("cls");
    if (!adresaci.empty())
    {
        for(int i = 0; i< adresaci.size(); i++)
        {
            cout<<endl;
            cout<<"ID:                  "<<adresaci[i].id<<endl;
            cout<<adresaci[i].imie<<"   "<<adresaci[i].nazwisko<<endl;
            cout<<"Nr telefonu:         "<<adresaci[i].nrTelefonu<<endl;
            cout<<"E-mail:              "<<adresaci[i].email<<endl;
            cout<<"Adres:               "<<adresaci[i].adres<<endl;
        }
    }
    else
        cout<<"Nie masz jeszcze adresow w ksiazce."<<endl<<endl;

    system("pause");
}

void wyszukajPoImieniu (vector <Adresat> &adresaci)
{
    int iloscAdresatow = 0;
    string szukaneImie = "";

    system("cls");
    if (!adresaci.empty())
    {
        cout << "--- WYSZUKIWANIE ADRESATOW O IMIENIU ---" << endl << endl;
        cout<<"Podaj imie: "<<endl;
        szukaneImie = wczytajLinie();
        szukaneImie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneImie);

        for(int i = 0; i< adresaci.size(); i++)
        {
            if(adresaci[i].imie == szukaneImie)
            {
                cout<<endl;
                cout<<"ID:                  "<<adresaci[i].id<<endl;
                cout<<adresaci[i].imie<<"   "<<adresaci[i].nazwisko<<endl;
                cout<<"Nr telefonu:         "<<adresaci[i].nrTelefonu<<endl;
                cout<<"E-mail:              "<<adresaci[i].email<<endl;
                cout<<"Adres:               "<<adresaci[i].adres<<endl;

                iloscAdresatow++;
            }
        }

        if (iloscAdresatow == 0)
        {
            cout << endl << "Nie ma adresatow z tym imieniem w ksiazce adresowej" << endl;
        }
        else
        {
            cout << endl << "Ilosc adresatow z imieniem: " << szukaneImie << " w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    }

    else
    {
        cout<<"Nie masz jeszcze adresow w ksiazce."<<endl<<endl;
    }
    system("pause");
}

void wyszukajPoNazwisku(vector <Adresat> &adresaci)
{
    int iloscAdresatow = 0;
    string szukaneNazwisko;


    system("cls");
    if (!adresaci.empty())
    {
        cout << "--- WYSZUKIWANIE ADRESATOW O NAZWISKU ---" << endl << endl;
        cout<<"Podaj nazwisko: "<<endl;
        szukaneNazwisko = wczytajLinie();
        szukaneNazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneNazwisko);

        for(int i = 0; i< adresaci.size(); i++)
        {
            if(adresaci[i].nazwisko == szukaneNazwisko)
            {
                cout<<endl;
                cout<<"ID:                  "<<adresaci[i].id<<endl;
                cout<<adresaci[i].imie<<"   "<<adresaci[i].nazwisko<<endl;
                cout<<"Nr telefonu:         "<<adresaci[i].nrTelefonu<<endl;
                cout<<"E-mail:              "<<adresaci[i].email<<endl;
                cout<<"Adres:               "<<adresaci[i].adres<<endl;
                iloscAdresatow++;
            }
        }

        if (iloscAdresatow == 0)
        {
            cout << endl << "Nie ma adresatow z tym nazwiskiem w ksiazce adresowej" << endl;
        }
        else
        {
            cout << endl << "Ilosc adresatow z nawiskiem: " << szukaneNazwisko <<" w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    }
    else
    {
        cout<<"Nie masz jeszcze adresow w ksiazce."<<endl<<endl;
    }
    system("pause");
}

void zaktualizujDaneWPliku(vector <Adresat> &adresaci, int i, int idAdresata, string tryb)
{
    fstream plik;
    plik.open("ksiazkaAdresowa.txt", ios::in);

    fstream plikTymczasowy;
    plikTymczasowy.open("ksiazkaAdresowa_tymczasowy.txt", ios::out);


    if(plik.good()==false)
        return;
    else
    {
        Adresat adresat;
        string slowo;
        int nrLinii = 1;

        while(getline(plik, slowo, '|'))
        {

            switch(nrLinii)
            {
            case 1:
                adresat.id = atoi( slowo.c_str() );
                break;
            case 2:
                adresat.idUzytkownika = atoi(slowo.c_str());
                break;
            case 3:
                adresat.imie = slowo;
                break;
            case 4:
                adresat.nazwisko = slowo;
                break;
            case 5:
                adresat.nrTelefonu = slowo;
                break;
            case 6:
                adresat.email = slowo;
                break;
            case 7:
                adresat.adres = slowo;
                break;
            }

            if(nrLinii >= 7)
            {
                if(adresat.id != idAdresata)
                {
                    plikTymczasowy<<adresat.id<<"|"<<adresat.idUzytkownika<<"|"<<adresat.imie<<"|"<<adresat.nazwisko<<"|"<<adresat.nrTelefonu<<"|"<<adresat.email<<"|"<<adresat.adres<<"|"<<endl;
                }
                else if(adresat.id == idAdresata && tryb == "edytuj")
                {
                    plikTymczasowy<<adresaci[i].id<<"|"<<adresaci[i].idUzytkownika<<"|"<<adresaci[i].imie<<"|"<<adresaci[i].nazwisko<<"|"<<adresaci[i].nrTelefonu<<"|"<<adresaci[i].email<<"|"<<adresaci[i].adres<<"|"<<endl;
                }
                else if(adresat.id == idAdresata && tryb == "usun")
                {
                    ;
                }

                nrLinii = 0;
            }
            nrLinii++;
        }

        plik.close();
        plikTymczasowy.close();

        remove("ksiazkaAdresowa.txt");
        rename("ksiazkaAdresowa_tymczasowy.txt", "ksiazkaAdresowa.txt");

    }

}

void edytujAdres(vector <Adresat> &adresaci)
{
    bool czyIstnieje = false;
    int idAdresata, wybor;

    system("cls");
    if (!adresaci.empty())
    {
        cout << "--- EDYCJA ADRESATA ---" << endl << endl;
        cout<<"Podaj ID adresata: "<<endl;
        idAdresata = wczytajLiczbeCalkowita();

        for(int i = 0; i< adresaci.size(); i++)
        {


            if(adresaci[i].id == idAdresata)
            {
                czyIstnieje = true;

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
                    adresaci[i].imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].imie);
                    cout<<"Edytowano uzytkownika"<<endl;
                    break;

                case 2:

                    cout<<"Podaj nazwisko: "<<endl;
                    adresaci[i].nazwisko = wczytajLinie();
                    adresaci[i].nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].nazwisko);
                    cout<<"Edytowano uzytkownika"<<endl;
                    break;


                case 3:

                    cout<<"Podaj numer telefonu: "<<endl;
                    adresaci[i].nrTelefonu = wczytajLinie();
                    cout<<"Edytowano uzytkownika"<<endl;
                    break;

                case 4:

                    cout<<"Podaj email: "<<endl;
                    adresaci[i].email = wczytajLinie();
                    cout<<"Edytowano uzytkownika"<<endl;
                    break;

                case 5:

                    cout<<"Podaj adres: "<<endl;
                    adresaci[i].adres = wczytajLinie();
                    cout<<"Edytowano uzytkownika"<<endl;
                    break;

                case 6:
                    system ("cls");

                    break;
                default:
                    break;

                }

                zaktualizujDaneWPliku(adresaci, i, idAdresata, "edytuj");

            }
        }

        if(czyIstnieje == false)
        {

            cout<<"Adresat o podanym ID nie istnieje."<<endl;

        }

    }
    else
    {
        cout<<"Nie masz jeszcze adresow w ksiazce."<<endl<<endl;
    }
    system("pause");


}


void usunAdres(vector <Adresat> &adresaci)
{

    bool czyIstnieje = false;
    int idAdresata;

    system("cls");
    if (!adresaci.empty())
    {
        cout << "--- USUWANIE ADRESATA ---" << endl << endl;

        cout<<"Podaj ID adresata: "<<endl;
        idAdresata = wczytajLiczbeCalkowita();

        for(int i = 0; i< adresaci.size(); i++)
        {

            if(adresaci[i].id == idAdresata)
            {
                 czyIstnieje = true;
                char wybor;
                cout<<"Czy na pewno chcesz usunac ten adres? Wcisnij 't' aby potwierdzic"<<endl;
                cin>> wybor;

                if(wybor == 't')
                {
                    adresaci.erase(adresaci.begin()+i);
                    czyIstnieje = true;
                    zaktualizujDaneWPliku(adresaci, i, idAdresata, "usun");
                    cout<<"Usunieto adres"<<endl;
                }
                else
                {
                    cout<<"Adres nie zostal usuniety"<<endl;
                }
            }
        }

        if(czyIstnieje == false)
        {

            cout<<"Nie ma adresu o podanym ID."<<endl;
        }
    }
    else
    {
        cout<<"Nie masz jeszcze adresow w ksiazce."<<endl<<endl;
    }
    system("pause");

}

void dodajAdres (vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int &idOstatniegoAdresu)
{
    Adresat adresat;
    system("cls");
    cout << "--- DODAWANIE NOWEGO ADRESATA ---" << endl << endl;

    cout<<"Podaj imie: "<<endl;
    adresat.imie = wczytajLinie();
    adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout<<"Podaj nazwisko: "<<endl;
    adresat.nazwisko = wczytajLinie();
    adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);


    cout<<"Podaj nr telefonu: "<<endl;
    adresat.nrTelefonu = wczytajLinie();
    cout<<"Podaj email: "<<endl;
    adresat.email = wczytajLinie();
    cout<<"Podaj adres: "<<endl;
    adresat.adres = wczytajLinie();

    adresat.idUzytkownika = idZalogowanegoUzytkownika;

    adresat.id = idOstatniegoAdresu+1;
    idOstatniegoAdresu++;

    adresaci.push_back(adresat);
    dopiszAdresataDoPliku(adresat, "ksiazkaAdresowa");

}

void wczytajAdresyZPliku (vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int &idOstatniegoAdresu)
{
    Adresat adresat;
    fstream plik;
    plik.open("ksiazkaAdresowa.txt", ios::in);

    if(plik.good())
    {
        string slowo;
        int nrLinii = 1;

        while(getline(plik, slowo, '|'))
        {

            switch(nrLinii)
            {
            case 1:
                adresat.id = atoi( slowo.c_str() );
                break;
            case 2:
                adresat.idUzytkownika = atoi(slowo.c_str());
                break;
            case 3:
                adresat.imie = slowo;
                break;
            case 4:
                adresat.nazwisko = slowo;
                break;
            case 5:
                adresat.nrTelefonu = slowo;
                break;
            case 6:
                adresat.email = slowo;
                break;
            case 7:
                adresat.adres = slowo;
                break;
            }

            if(nrLinii >= 7)
            {

                idOstatniegoAdresu = adresat.id;

                if(adresat.idUzytkownika == idZalogowanegoUzytkownika)
                {
                    adresaci.push_back(adresat);
                }
                nrLinii = 0;


            }
            nrLinii++;
        }

        plik.close();

    }
    else
    {
        cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
    }

}

void wczytajUzytkownikowZPliku (vector <Uzytkownik> &uzytkownicy)
{

    Uzytkownik uzytkownik;
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);

    if(plik.good())
    {


        string slowo;
        int nrLinii = 1;

        while(getline(plik, slowo, '|'))
        {

            switch(nrLinii)
            {
            case 1:
                uzytkownik.id = atoi( slowo.c_str() );
                break;
            case 2:
                uzytkownik.login = slowo;
                break;
            case 3:
                uzytkownik.haslo = slowo;
                break;
            }

            if(nrLinii >= 3)
            {
                nrLinii = 0;
                uzytkownicy.push_back(uzytkownik);

            }
            nrLinii++;
        }

        plik.close();

    }
    else
    {
        cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
    }

}

void rejestracja (vector <Uzytkownik> &uzytkownicy)
{
    Uzytkownik uzytkownik;
    uzytkownik.id = (uzytkownicy.empty()) ? (1) : (uzytkownicy.back().id + 1);
    string login = "", haslo = "";

    system("cls");
    cout << "--- REJESTRACJA UZYTKOWNIKA ---" << endl << endl;

    cout<<"Podaj login uzytkownika: "<<endl;
    uzytkownik.login = wczytajLinie();
    int i = 0;

    while(i < uzytkownicy.size())
    {
        if(uzytkownicy[i].login == uzytkownik.login)
        {
            cout<<"Taki uzytkownik istnieje. Wpisz inny login uzytkownika: "<<endl;
            uzytkownik.login = wczytajLinie();
            i =0;
        }
        else
        {
            i++;
        }
    }

    cout<<"Podaj haslo: "<<endl;
    cin >> uzytkownik.haslo;
    cin.ignore();

    uzytkownicy.push_back(uzytkownik);
    dopiszUzytkownikaDoPliku(uzytkownik, "Uzytkownicy");

}


void logowanie (vector <Uzytkownik> &uzytkownicy, int &idZalogowanegoUzytkownika)
{

    string login = "", haslo = "";



    system("cls");
    cout << "--- LOGOWANIE ---" << endl << endl;
    cout<<"Podaj login: "<<endl;
    login = wczytajLinie();
    int i = 0;

    while(i < uzytkownicy.size())
    {
        if(uzytkownicy[i].login == login)
        {
            for(int proby = 0 ; proby< 3; proby++)
            {
                cout<<"Podaj haslo. Pozostalo prob "<< 3 -proby<<": "<<endl;
                haslo = wczytajLinie();

                if(uzytkownicy[i].haslo == haslo)
                {
                    cout<<"Zalogowales sie. "<<endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].id;
                    return;
                }
            }
            cout<<"Podales 3 razy bledne haslo. Sprobuj ponownie."<<endl;
            system("pause");
            return;
        }
        i++;

    }

    cout<<"Nie ma uzytkownika z takim loginem."<<endl;
    system("pause");
    return;

}

void zapiszWszystkichUzytkownikowDoPliku (vector <Uzytkownik> uzytkownicy)
{

    fstream plik;

    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good())
    {
        for (int i = 0; i< uzytkownicy.size(); i++)
        {
            plik<<uzytkownicy[i].id<<'|'<<uzytkownicy[i].login<<'|'<<uzytkownicy[i].haslo<<'|'<<endl;

        }
        plik.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku Uzytkownicy.txt" << endl;
    }
}


void zmienHaslo(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
    string noweHaslo = "";


    system("cls");
    cout << "--- ZMIANA HASLA ---"<< endl;

    cout<<"Podaj nowe haslo: "<<endl;
    cin>>noweHaslo;
    cin.ignore();

    for(int i = 0; i < uzytkownicy.size(); i++)
    {

        if(uzytkownicy[i].id == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo = noweHaslo;
            zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
            cout<<"Twoje haslo zostalo zmienione."<<endl;
            system("pause");
        }
    }


}



void wylogujUzytkownika( int &idZalogowanegoUzytkownika)
{
    idZalogowanegoUzytkownika = 0;

}




int main ()
{

    vector <Adresat> adresaci;
    vector <Uzytkownik> uzytkownicy;

    char wybor;
    bool wczytanoAdresy = false;
    int idZalogowanegoUzytkownika = 0, idOstatniegoAdresu = 0;

    wczytajUzytkownikowZPliku(uzytkownicy);


    while(true)
    {
        system("cls");
        if(idZalogowanegoUzytkownika == 0)
        {
            cout<<"KSIAZKA ADRESOWA"<<endl;
            cout<<"1. Logowanie"<<endl;
            cout<<"2. Rejestracja"<<endl;
            cout<<"3. Zamknij program"<<endl;

            cout << "Twoj wybor: ";
            wybor = wczytajZnak();

            if(wybor == '1')
            {
                logowanie(uzytkownicy, idZalogowanegoUzytkownika);
                wczytanoAdresy = false;
            }
            if(wybor == '2')
            {
                rejestracja(uzytkownicy);
            }
            if(wybor == '3')
            {
                exit(0);
            }
        }

        else
        {
            if(!wczytanoAdresy)
            {
                wczytajAdresyZPliku(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresu);
                wczytanoAdresy = true;
            }

            cout<<"KSIAZKA ADRESOWA"<<endl;
            cout<<"1. Dodaj adresata"<<endl;
            cout<<"2. Wyszukaj po imieniu"<<endl;
            cout<<"3. Wyszukaj po nazwisku"<<endl;
            cout<<"4. Wyswietl wszystkich adresatow"<<endl;
            cout<<"5. Usun adresata"<<endl;
            cout<<"6. Edytuj adresata"<<endl;
            cout<<"7. Zmien haslo"<<endl;
            cout<<"8. Wyloguj sie"<<endl;
            cout<<"Twoj wybor:"<<endl;

            wybor = wczytajZnak();

            if(wybor == '1')
            {
                dodajAdres(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresu);
            }
            if(wybor == '2')
            {
                wyszukajPoImieniu(adresaci);

            }
            if(wybor == '3')
            {
                wyszukajPoNazwisku(adresaci);
            }
            if(wybor == '4')
            {
                wyswietlWszystkieAdresy(adresaci);

            }
            if(wybor == '5')
            {
                usunAdres(adresaci);
            }

            if(wybor == '6')
            {
                edytujAdres(adresaci);
            }
            if(wybor == '7')
            {
                zmienHaslo(uzytkownicy, idZalogowanegoUzytkownika);
            }

            if(wybor == '8')
            {
                wylogujUzytkownika(idZalogowanegoUzytkownika);
            }

        }
    }


    return 0;
}



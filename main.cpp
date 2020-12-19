#include <iostream>
#include <string>

#include "RandomNameGenerator.hpp"

using namespace std;

const double CI=100;
const int CMag=200;
const int CMkt=200;
const int CR=200;

const double cel=1000000;

const int max_pracownikow=50;
const int max_kredytow=10;
const int max_czas_splaty_kredytu=24;
const double M=1;

int miesiac=1;
double stan_konta=10000;

struct Korposzczur
{
  public:
  Korposzczur()
  {
    name=get_random_name();
  }

  double get_salary()
  {
    return salary;
  }

  virtual void print()
  {
    cout << "Imie: " << name << " Wynagrodzenie: " << salary << '\n';
  }
  int typ;

  protected:
  string name;
  double salary;
};

struct Inz : public Korposzczur
{
  public:
  Inz()
  {
    salary=5000.;
    wydzial="MEiL";
    typ=0;
    
  }

  void print() override
  {
    cout << "Imie: " << name << " | Stanowisko: Inzynier" << " | Wynagrodzenie: " << salary << " | Wydzial: " << wydzial << '\n';
  }

  private:
  string wydzial;
};

struct Mag : public Korposzczur
{
  public:
  Mag()
  {
    salary=4000.;
    wwid=false;
    typ=1;
  }

  void print() override
  {
    cout << "Imie: " << name << " | Stanowisko: Magazynier" << " | Wynagrodzenie: " << salary << " | Uprawnienia do wozkow widlowych: ";
    if (wwid==1) cout << "TAK \n";
    else cout << "NIE \n";
  }

  private:
  bool wwid;
};

struct Mkt : public Korposzczur
{
  public:
  Mkt()
  {
    salary=5000.;
    folow=10000;
    typ=2;
  }

  void print() override
  {
    cout << "Imie: " << name << " | Stanowisko: Marketer" << " | Wynagrodzenie: " << salary << " | Obserwujacy: " << folow << '\n';
  }

  private:
  int folow;
};

struct Rob : public Korposzczur
{
  public:
  Rob()
  {
    salary=3000.;
    nrbut=44.5;
    typ=3;
  }

  void print() override
  {
    cout << "Imie: " << name << " | Stanowisko: Robotnik" << " | Wynagrodzenie: " << salary << " | Numer buta " << nrbut << '\n';
  }

  private:
  double nrbut;
};

struct Korposzczury
{
  public:
  Korposzczury()
  {
    p[0]=new Inz;
    p[1]=new Mag;
    p[2]=new Mkt;
    p[3]=new Rob;
    liczba_pracownikow=4;
    liczba_inz=1;
    liczba_mag=1;
    liczba_mkt=1;
    liczba_rob=1;
  }

  void print_all()
  {
    for (int i=0; i<liczba_pracownikow; i++)
    {
      p[i]->print();
    }
  }

  double suma_wynagrodzen()
  {
    double suma=0;
    for (int i=0;i<liczba_pracownikow;i++)
    {
      suma+=p[i]->get_salary();
    }
    return suma;
  }

  void zatrudnij_pracownika(int typ)
  {
    if (liczba_pracownikow<max_pracownikow)
    {
      string komenda;
    if (typ==0)
    {
      for (int i=0;i!=1;)
      {
        cout << "Koszt utrzymania inzyniera wynosi 5000 cebulionow miesiecznie. Czy jestes pewny, ze chcesz zatrudnic inzyniera? (TAK/NIE)\n";
        cin >> komenda;
        if(komenda == "TAK")
        {
          p[liczba_pracownikow]=new Inz;
          liczba_inz++;
          liczba_pracownikow++;
          cout << "Inzynier zatrudniony.\n";
          i=1;
        }
        else if (komenda =="NIE")
        {
          cout << "Inzynier nie zatrudniony.\n";
          i=1;
        }
        else
        {
          cout <<"Komenda nierozpoznana, powtorz.\n";
        }
      }
    }
    else if (typ==1)
    {
      for (int i=0;i!=1;)
      {
        cout << "Koszt utrzymania magazyniera wynosi 4000 cebulionow miesiecznie. Czy jestes pewny, ze chcesz zatrudnic magazyniera? (TAK/NIE)\n";
        cin >> komenda;
        if(komenda == "TAK")
        {
          p[liczba_pracownikow]=new Mag;
          liczba_mag++;
          liczba_pracownikow++;
          cout << "Magazynier zatrudniony.\n";
          i=1;
        }
        else if (komenda =="NIE")
        {
          cout << "Magazynier nie zatrudniony.\n";
          i=1;
        }
        else
        {
          cout <<"Komenda nierozpoznana, powtorz.\n";
        }
      }
    }
    else if (typ==2)
    {
      for (int i=0;i!=1;)
      {
        cout << "Koszt utrzymania marketera wynosi 5000 cebulionow miesiecznie. Czy jestes pewny, ze chcesz zatrudnic marketera? (TAK/NIE)\n";
        cin >> komenda;
        if(komenda == "TAK")
        {
          p[liczba_pracownikow]=new Mkt;
          liczba_mkt++;
          liczba_pracownikow++;
          cout << "Marketer zatrudniony.\n";
          i=1;
        }
        else if (komenda =="NIE")
        {
          cout << "Marketer nie zatrudniony.\n";
          i=1;
        }
        else
        {
          cout <<"Komenda nierozpoznana, powtorz.\n";
        }
      }
    }
    else if (typ==3)
    {
      for (int i=0;i!=1;)
      {
        cout << "Koszt utrzymania robotnika wynosi 3000 cebulionow miesiecznie. Czy jestes pewny, ze chcesz zatrudnic robotnika? (TAK/NIE)\n";
        cin >> komenda;
        if(komenda == "TAK")
        {
          p[liczba_pracownikow]=new Rob;
          liczba_rob++;
          liczba_pracownikow++;
          cout << "Robotnik zatrudniony.\n";
          i=1;
        }
        else if (komenda =="NIE")
        {
          cout << "Robotnik nie zatrudniony.\n";
          i=1;
        }
        else
        {
          cout <<"Komenda nierozpoznana, powtorz.\n";
        }
      }
    }
    }
    else
    {
      cout << "Nie mozesz zatrudnic wiecej pracownikow \n";
    }

  }

  bool zaplac_pracownikom()
  {
    bool bankrut;
    if (stan_konta>=suma_wynagrodzen())
    {
      stan_konta-= suma_wynagrodzen();
      bankrut=false;
    }
    else
    {
      bankrut=true;
    }
    return bankrut;
  }

  Korposzczur* p[max_pracownikow];
  int liczba_pracownikow;
  int liczba_inz;
  int liczba_mag;
  int liczba_mkt;
  int liczba_rob;
};

struct Kredyt
{
  Kredyt(double r, int t)
  {
    rata=r;
    pozostaly_czas=t;
  }

  double rata;
  int pozostaly_czas;
};

struct Zadluzenie
{
  Zadluzenie()
  {
    liczba_kredytow=0;
  }

  void nowy_kredyt(double r, int t)
  {
    lista_kredytow[liczba_kredytow]=new Kredyt{r,t};
    liczba_kredytow++;
    cout << "Kredyt przyznany\n";
  }

  double suma_zadluzenia()
  {
    double suma=0;
    for (int i=0;i<liczba_kredytow;i++)
    {
      suma+=lista_kredytow[i]->rata*lista_kredytow[i]->pozostaly_czas;
    }
    return suma;
  }

  void usun_kredyt(int nr)
  {
    for (int i=nr; i<liczba_kredytow-1; i++)
    {
      lista_kredytow[i]->rata=lista_kredytow[i+1]->rata;
      lista_kredytow[i]->pozostaly_czas=lista_kredytow[i+1]->pozostaly_czas;
    }
    liczba_kredytow--;
  }

  bool splac_raty()
  {
    bool bankrut;
    double suma=0;
    for (int i=0;i<liczba_kredytow;i++)
    {
      suma+=lista_kredytow[i]->rata;
      lista_kredytow[i]->pozostaly_czas--;
      if (lista_kredytow[i]->pozostaly_czas==0)
      {
        usun_kredyt(i);
        i--;
      }
    }

    if (stan_konta>=suma)
    {
      stan_konta-=suma;
      bankrut=false;
    }
    else
    {
      bankrut=true;
    }
    return bankrut;
  }

  Kredyt* lista_kredytow[max_kredytow];
  int liczba_kredytow;
};

struct Korpo
{
  public:
  Korpo()
  {
    przychod=0;
    wartosc=stan_konta;
    tablica_przychodow[0]=0;
    tablica_przychodow[1]=0;
    tablica_przychodow[2]=0;
    tablica_przychodow[3]=0;
    tablica_przychodow[4]=0;
  }

  int pojemnosc_magazynu()
  {
    return crew.liczba_mag*CMag;
  }

  int cena_produktu()
  {
    return crew.liczba_inz*CI;
  }

  int popyt()
  {
    return crew.liczba_mkt*CMkt;
  }

  int max_produkcja()
  {
    return crew.liczba_rob*CR;
  }

  void nowy_pracownik(int typ)
  {
    crew.zatrudnij_pracownika(typ);
  }

  void wez_kredyt()
  {
    double kwota;
    int czas;
    
    cout << "Podaj kwote kredytu \n";
    cin >> kwota;
    cout << "Podaj czas splaty kredytu \n";
    cin >> czas;
    string komenda;

    if (czas>max_czas_splaty_kredytu)
    {
      cout << "Przekroczony maksymalny czas splaty";
    }
    else
    {
      if (kwota*(1.+czas*0.004)+dlug.suma_zadluzenia()>M*wartosc)
      {
        cout << "Przekroczony limit zadluzenia\n";
      }
      else
      {
        cout << " Dla wybranej kwoty i czasu splaty oprocentowanie wynosi " << 0.4*czas << "%. \n Calkowita kwota do splaty wynosi " << kwota*(1.+czas*0.004) << " cebulionow. \n Miesieczna rata wynosi " << kwota*(1.+czas*0.004)/czas <<" cebulionow. \n Czy jestes pewny, ze chcesz wziac kredyt? (TAK/NIE) \n";

        cin >> komenda;

        if (komenda=="TAK")
        {
          dlug.nowy_kredyt(kwota*(1.+czas*0.004)/czas, czas);
          stan_konta+=kwota;
        }
        else if (komenda=="NIE")
        {
          cout << "Kredyt anulowany \n";
        }
        else
        {
          cout << "Komenda nierozpoznana \n";
        }

      }

    }

  }
  
  void oblicz_wartosc()
  {
    if (miesiac<5)
    {
      
      wartosc=0;
      for (int i=miesiac%5;i>0;i--)
      {
        wartosc+=tablica_przychodow[i];
      }
      wartosc=wartosc/miesiac;
    }
    else
    {
      wartosc=(tablica_przychodow[0]+tablica_przychodow[1]+tablica_przychodow[2]+tablica_przychodow[3]+tablica_przychodow[4])/5;
    }
    
  }

  void sprzedaj_produkty()
  {
    int liczba_sprzedanych_produktow;
    if (max_produkcja()<=pojemnosc_magazynu())
    {
      liczba_sprzedanych_produktow=max_produkcja();
    }
    else
    {
      liczba_sprzedanych_produktow=pojemnosc_magazynu();
    }
    if (liczba_sprzedanych_produktow>popyt())
    {
      liczba_sprzedanych_produktow=popyt();
    }
    
    stan_konta+=liczba_sprzedanych_produktow*cena_produktu();
    
    przychod=liczba_sprzedanych_produktow*cena_produktu();

    tablica_przychodow[miesiac%5]=przychod;
  }
  
  bool koniec_miesiaca()
  {
    sprzedaj_produkty();
    bool pensje=crew.zaplac_pracownikom();
    bool raty=dlug.splac_raty();
    if(pensje||raty)
    {
      return false;
    }
    else
    {
      oblicz_wartosc();
      miesiac++;
      return true;
    }
  }

  double get_wartosc()
  {
    return wartosc;
  }  

  void wylistuj_pracownikow()
  {
    crew.print_all();
  }
  
  double get_zadluzenie()
  {
    return dlug.suma_zadluzenia();
  }

  void raport()
  {
    cout << " ------------------------- \n Miesiac " << miesiac << "\n Wartosc firmy Januszex: " << wartosc << " cebulionow\n Saldo konta: " << stan_konta << " cebulionow\n Zadluzenie: " << dlug.suma_zadluzenia() << " cebulionow\n Pojemnosc magazynu: " << pojemnosc_magazynu() << " szt. \n Mozliwosci produkcyjne: " << max_produkcja() << "szt. \n Popyt: " << popyt() << "szt.\n Cena sprzedazy jednej sztuki produktu: " << cena_produktu() <<" cebulionow\n ------------------------- \n";
  }

  private:
  double przychod;
  double wartosc;
  double tablica_przychodow[5];
  Korposzczury crew;
  Zadluzenie dlug;
};

void help()
{
  cout << "Lista komend: \n lp - wylistuj pracowników \n zinz - zatrudnij inzyniera \n zmag - zatrudnij magazyniera \n zmkt - zatrudnij marketera \n zrob - zatrudnij robotnika \n kred - wez kredyt \n raport - wyswietl raport o stanie firmy \n kt - zakoncz ture \n help - wyswietl liste komend \n";
}


int main() {
  

  Korpo Januszex;
  cout << "Witamy w firmie Januszex! \nTwoje poczatkowe saldo konta wynosi: " << stan_konta << " cebulionow.\nW swoim kolchozie wykorzystujesz obecnie 4 pracownikow. \nZatrudnij wiecej wspolczesnych niewolnikow, okradaj panstwo szybciej niz ono okrada Ciebie i zwieksz wartosc firmy do 1 000 000 cebulionow, zeby somsiad zlodziej zazdroscil. \n";

  help();

  string komenda;
  bool koniec_miesiaca;

  for(int j=0;j!=1;) //petla glowna, jeden krok=jeden miesiac
  {
  koniec_miesiaca=false;
  for (int i=0;i!=1;) //petla komend
  {
    cin >> komenda;
    
    if (komenda=="lp")
    {
      Januszex.wylistuj_pracownikow();
    }
    else if (komenda=="zinz")
    {
      Januszex.nowy_pracownik(0);
    }
    else if (komenda =="zmag")
    {
      Januszex.nowy_pracownik(1);
    }
    else if (komenda=="zmkt")
    {
      Januszex.nowy_pracownik(2);
    }
    else if (komenda =="zrob")
    {
      Januszex.nowy_pracownik(3);
    }
    else if (komenda == "kred")
    {
      Januszex.wez_kredyt();
    }
    else if (komenda == "kt")
    {
      koniec_miesiaca=Januszex.koniec_miesiaca();
      i=1;
    }
    else if (komenda=="help")
    {
      help();
    }
    else if (komenda=="raport")
    {
      Januszex.raport();
    }
    else
    {
      cout << "Komenda nierozpoznana \n";
    }
    
    }
      if (koniec_miesiaca)
      {
        if (Januszex.get_wartosc()>=cel)
        {
          cout << "Wygrana \n";
          j=1;
        }
        else
        {
          cout << " ------------------------- \n Miesiac " << miesiac << "\n Wartosc firmy Januszex: " << Januszex.get_wartosc() << " cebulionow\n Saldo konta: " << stan_konta << " cebulionow\n Zadluzenie: " << Januszex.get_zadluzenie() << " cebulionow\n ------------------------- \n";
        }
      }
      else
      {
        j=1;
        cout << "Bankrut \n";
      }
  }
  cout << "Koniec gry \n";
}
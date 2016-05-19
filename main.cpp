/*Kim.uwb.edu.pl/programowanie*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
const string wojewodztwo_t[16]{"dolnoslaskie","kujawsko-pomorskie","lubelskie,lubuskie","lodzkie","pomorskie","podlaskie","opolskie","mazowieckie","malopolskie","slaskie","swietokrzyskie","warminsko-mazurskie","wielkopolskie","zachodniopomorskie"};
const string plec_t[2]{"mezczyzna","kobieta"};
struct osoba
{
	string imie;
	string nazwisko;
	int wiek;
	int waga;
	string plec;
	string wojewodztwo;
	int wzrost;
};
struct id
{
	int ile;
	osoba lista[50];
};
//obliczanie sredniej wieku
double srednia(id p)
{
	double srednia = 0;
	for(int i = 0; i < p.ile; i++)
	{
		srednia += p.lista[i].wiek;
	}
	return srednia / p.ile;
}
//obliczanie bmi
double bmi(id p, int i)
{
	return (p.lista[i].waga) / (pow((p.lista[i].wzrost*0.01), 2));
}
//wyswietlanie bmi
void wysbmi(id p, int i)
{
	double BMI = bmi(p, i);
	if(BMI < 16)cout << "wyglodniale " << BMI << endl;
	else
		if(BMI >= 16 && BMI<17)cout << "wychudzenie " << BMI << endl;
		else
			if(BMI >= 17 && BMI<18.5)cout << "niedowaga " << BMI << endl;
			else
				if(BMI >= 18.5 && BMI <25)cout << "wartosc prawidlowa" << BMI << endl;
				else
					if(BMI >= 25 && BMI<30)cout << "nadwaga" << BMI << endl;
					else
						if(BMI >= 30 && BMI <35)cout << "I stopien otylosci" << BMI << endl;
						else
							if(BMI >= 35 && BMI<40)cout << "II stopien otylosci" << BMI << endl;
							else
								if(BMI >= 40)cout << "otylosc skrajna " << BMI << endl;
}
//wyswietlanie osoby
void wyswietl(id s, int i)
{
	cout << "Imie " << s.lista[i].imie << endl;
	cout << "nazwisko " << s.lista[i].nazwisko << endl;
	cout << "wiek " << s.lista[i].wiek << endl;
	cout << "waga " << s.lista[i].waga << endl;
	cout << "plec " << s.lista[i].plec << endl;
	cout << "wojewodztwo " << s.lista[i].wojewodztwo << endl;
	cout << "wzrost " << s.lista[i].wzrost << endl;
}
//dodawanie osoby
void dodaj(id *s)
{
    bool flaga=false;//flaga do sprawdzania stringow
	cout << "Podaj imie" << endl;
	while(!flaga) //dopóki flaga jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cin>>s->lista[s->ile].imie;
        for(int i=0;i<(s->lista[s->ile].imie.length());i++)
        {
            if(s->lista[s->ile].imie[i]<='9'&&s->lista[s->ile].imie[i]>='1')
        {
            cout<<"Podano zle imie"<<endl;// komunikat błędu
            cin.sync(); //kasowanie zbędnych znaków z bufora
            break;
        }
        flaga=true;
        }
    }
    flaga=false;
	cout << "Podaj nazwisko" << endl;
    while(!flaga) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cin>>s->lista[s->ile].nazwisko;
        for(int i=0;i<(s->lista[s->ile].nazwisko.length());i++)
        {
            if(s->lista[s->ile].nazwisko[i]<='9'&&s->lista[s->ile].nazwisko[i]>='1')
        {
            cout<<"Podano zle nazwisko"<<endl;// komunikat błędu
            cin.sync(); //kasowanie zbędnych znaków z bufora
            break;
        }
        flaga=true;
        }
    }
    flaga=false;
	cout << "Podaj wiek" << endl;
	while(!flaga){
    while(!(cin>>s->lista[s->ile].wiek)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cout<<"podano zly wiek osoby"<<endl;//komunikat błędu
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.sync(); //kasowanie zbędnych znaków z bufora
    }
    if((s->lista[s->ile].wiek<1) || (s->lista[s->ile].wiek>100))
        cout<<"podano zly wiek osoby"<<endl;
    else flaga=true;
    }
    flaga=false;
	cout << "Podaj waga" << endl;
	while(!flaga){
    while(!(cin>>s->lista[s->ile].waga)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cout<<"Podano zla wage"<<endl;//ew komunikat błędu
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.sync(); //kasowanie zbędnych znaków z bufora
    }if(s->lista[s->ile].waga<1&&s->lista[s->ile].waga>300)
    cout<<"podano zla wage"<<endl;
    else flaga=true;
    }
    flaga=false;
	cout << "Podaj plec" << endl;
    while(!flaga) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cin>>s->lista[s->ile].plec;
        for(int i=0;i<2;i++)
            if(s->lista[s->ile].plec==plec_t[i])
        {
           flaga=true;
            break;
        }
        if(!flaga)
        {
            cout<<"podano zla plec"<<endl;
            cin.sync(); //kasowanie zbędnych znaków z bufora
        }
    }
    flaga=false;
	cout << "Podaj wojewodztwo" << endl;
    while(!flaga) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cin>>s->lista[s->ile].wojewodztwo;
        for(int i=0;i<16;i++)
            if(s->lista[s->ile].wojewodztwo==wojewodztwo_t[i])
        {
           flaga=true;
            break;
        }
        if(!flaga){
        cout<<"podano zle wojewodztwo\noto lista wojewodztw\ndolnoslaskie\nkujawsko-pomorskie\nlubelskielubuskie\nlodzkie\npomorskie\npodlaskie\nopolskie\nmazowieckie\nmalopolskie\nslaskie\nswietokrzyskie\nwarminsko-mazurskie\nwielkopolskie\nzachodniopomorskie"<<endl;
        cin.sync(); //kasowanie zbędnych znaków z bufora}
    }}
    flaga=false;
	cout << "Podaj wzrost w cm" << endl;
	while(!flaga)
    {
    while(!(cin>>s->lista[s->ile].wzrost)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cout<<"Podano zly wzrost"<<endl;//ew komunikat błędu
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.sync(); //kasowanie zbędnych znaków z bufora
    }
    if(s->lista[s->ile].wzrost<50||s->lista[s->ile].wzrost>250)
    cout<<"podano zly wzrost"<<endl;
    else flaga=true;
    }
	s->ile++;
}
//sortowanie od najmlodszego
void sortowanie(id *s)
{
	osoba temp;
	int ile;
	ile = s->ile;
	for(int i = 0; i < ile; i++)
		for(int j = 0; j < s->ile; j++)
		{
			if(s->lista[i].wiek>s->lista[j].wiek)
			{
				temp = s->lista[i];
				s->lista[i] = s->lista[j];
				s->lista[j] = temp;
			}
		}

}
//wyswietl osobe najstarsza
void najstarsza(id p)
{
	int najstarsza = 0, i_najstarszej;
	for(int i = 0; i<p.ile; i++)
	{
		if(p.lista[i].wiek>najstarsza)
		{
			najstarsza = p.lista[i].wiek;
			i_najstarszej = i;
		}
	}
	wyswietl(p, i_najstarszej);
}
//wyswietl osobe najmlodsza
void najmlodsza(id p)
{
	int najmlodsza = 0, i_najmlodsza;
	for(int i = 0; i<p.ile; i++)
	{
		if(p.lista[i].wiek>najmlodsza)
		{
			najmlodsza = p.lista[i].wiek;
			i_najmlodsza = i;
		}
	}
	wyswietl(p, i_najmlodsza);
}
//sortowanie wedlog bmi
void sortowaniebmi(id *s)
{
	osoba stemp;
	double temp;
	int ile;
	ile = s->ile;
	double BMI[50];
	for(int i = 0; i < ile; i++)
	{
		BMI[i] = bmi(*s, i);
	}
	for(int i = 0; i < ile; i++)
		for(int j = 0; j < ile-i; j++)
		{
			if(BMI[i]<BMI[j])
			{
				stemp = s->lista[i];
				s->lista[i] = s->lista[j];
				temp=BMI[i];
				BMI[i]=BMI[j];
				s->lista[j] = stemp;
				BMI[j]=temp;
			}
		}

}
int main(int argc, char *argv[])
{
	id Ludzie;
	int kogo;
	Ludzie.ile = 0;
	bool koniec = false;
	int wybor = 0;

	while(koniec != true)
	{
		cout << "1.Dodaj\n2.Wyswietl\n3.sortuj wzrost\n4.sortuj bmi\n5.osoba najstarsza\n6.osoba najmlodsza\n7.srednia wiekowa\n8.obliczanie bmi" << endl;
		cin >> wybor;
		switch(wybor)
		{
			case 1:
				dodaj(&Ludzie);
				break;
			case 2:
				for(int i = 0; i < Ludzie.ile; i++)
					wyswietl(Ludzie, i);
				break;
			case 3:
				sortowanie(&Ludzie);
				break;
			case 4:
				sortowaniebmi(&Ludzie);
				break;
			case 5:
				najstarsza(Ludzie);
				break;
			case 6:
				najmlodsza(Ludzie);
				break;
			case 7:
				cout << srednia(Ludzie) << endl;
				break;
			case 8:
				cout << "czyje bmi chcesz obliczyc(podaj id)" << endl;
				cin >> kogo;
				wysbmi(Ludzie, kogo);
				break;
			case 0:
				koniec = true;
				break;
			default:
				cout << "dokonano zlego wyboru" << endl;
				break;

		}


	}
	system("PAUSE");
	return 0;
}

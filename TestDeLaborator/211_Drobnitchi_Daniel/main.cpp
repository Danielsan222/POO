/* Drobnitchi Daniel Nicusor 211
Codeblocks GNU GCC Compiler, mingw32
Szmeteanca Eduard*/


#include <iostream>
#include <vector>
#include <cstring>
#include <list>
//Clasele au alt nume fata de cele din document, am crezut ca nu este nevoie sa scriem la fel.
//Am copiat indicatiile din document, de aceea sunt erori la schema vaccinare;
using namespace std;//Clasele sunt facute dupa un template facut de mine pentru a salva timp. Nu am folosit char* din cauza timpului;
class Vaccin{
protected:
    int pret;
    int temperatura;
    string substante;
    string numeProducator;
public:
    Vaccin(int pret, int temperatura, string substante, string numeProducator );
    Vaccin(){pret=0;temperatura=0;substante="Necunoscute";}
    Vaccin(Vaccin&);
    virtual ~Vaccin();

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, Vaccin& z);
    friend ostream& operator<<(ostream &out, Vaccin& z);
    virtual string schemaVaccinare() = 0;

    Vaccin& operator=(Vaccin &z);
    string getProducator(){return this->numeProducator;};
};
Vaccin::Vaccin(int pret, int temperatura, string substante, string numeProducator){
this->pret= pret;
this->temperatura = temperatura;
this->substante = substante;
this->numeProducator = numeProducator;
}
Vaccin::Vaccin(Vaccin &z){
   this->pret=z.pret;
   this->temperatura= z.temperatura;
   this->substante = z.substante;
   this->numeProducator = z.numeProducator;

}

Vaccin::~Vaccin(){

}

void Vaccin::citire(istream &in){
    cout<<"Numele producatorului este: :";
    cin>>numeProducator;

    cout<<"Spune pret:";cin>>pret;
    cout<<"Temperatura :";cin>>temperatura;
    cout<<"Ingrediente: ";cin>>substante;

}

istream& operator>>(istream& in,Vaccin& z){
    z.citire(in);
    return in;
}

void Vaccin::afisare(ostream &out){
    cout<<"Pretul este: "<<this->pret<<endl;
    cout<<"Temperatura este : "<<this->temperatura<<endl;
    cout<<"Ingredientele sunt : "<<this->substante<<endl;
}


ostream& operator<<(ostream& out, Vaccin& z){
    z.afisare(out);
    return out;
}

Vaccin& Vaccin::operator=(Vaccin &z){
    if (this!=&z)
    {
        pret=z.pret;
        temperatura = z.temperatura;
        substante = z.substante;

    }
    return *this;
}

class SarsCov:public Vaccin{
private:
    string Reactii;
    string Contraindicate;
    float rataEficienta;
public:

    SarsCov(int pret, int temperatura, string substante, string Reactii, string Contraindicate, float rataEficienta);
    SarsCov(){pret=0; temperatura=0, substante = "Necunoscute", Reactii = "Necunoscute", Contraindicate = "Necunoscute";};
    SarsCov(SarsCov&);
    ~SarsCov();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, SarsCov& z);
    friend ostream& operator<<(ostream &out, SarsCov& z);
    friend istream& operator>>(istream &in, SarsCov*z);
    friend ostream& operator<<(ostream &out, SarsCov*z);
    SarsCov& operator=(SarsCov &z);
    string schemaVaccinare()
    {
        return "Sars-Cov2 se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 zile. ";
    }

};


SarsCov::SarsCov(int pret, int temperatura, string substante, string Reactii, string Contraindicate, float rataEficienta):Vaccin(pret, temperatura, substante, numeProducator)
{
    this->Reactii = Reactii;
    this->Contraindicate = Contraindicate;
    this->rataEficienta = rataEficienta;
}

SarsCov::~SarsCov(){
}

SarsCov::SarsCov(SarsCov &z):Vaccin(z)
{
   Reactii= z.Reactii;
   Contraindicate = z.Contraindicate;
   this->rataEficienta = z.rataEficienta;
}

void SarsCov::citire(istream &in){
    Vaccin::citire(in);
    cout<<"Reactiile sunt :";
    cin>>Reactii;
    cout<<"Contraindicatele sunt: ";
    cin>>Contraindicate;
    cout<<"Rata de eficienta este :";
    cin>>rataEficienta;
}

void SarsCov::afisare(ostream &out){
    Vaccin::afisare(out);
    cout<<"Reactiile suint :"<<Reactii<<endl;
    cout<<"Contraindicatele sunt:"<<Contraindicate<<endl;
    cout<<"Rata de eficienta este :"<<rataEficienta<<endl;
}

istream& operator>>(istream& in,SarsCov& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, SarsCov& z){
    z.afisare(out);
    return out;
}


SarsCov& SarsCov :: operator=(SarsCov &z)
{
    if(this!=&z)
    {
        Vaccin::operator=(z);
        Reactii= z.Reactii;
        Contraindicate = z.Contraindicate;
        rataEficienta = z.rataEficienta;

    }
    return *this;
}

class AntiGripal:public Vaccin{
private:
    string tulpina;
    string respecta;
public:
    AntiGripal(int pret, int temperatura, string substante, string tulpina, string respecta);
    AntiGripal(){pret=0; temperatura=0, substante = "Necunoscute", tulpina = "Necunoscute", respecta = "Necunoscute";};
    AntiGripal(AntiGripal&);
    ~AntiGripal();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, AntiGripal& z);
    friend ostream& operator<<(ostream &out, AntiGripal& z);
    friend istream& operator>>(istream &in, AntiGripal*z);
    friend ostream& operator<<(ostream &out, AntiGripal*z);
    AntiGripal& operator=(AntiGripal &z);
    string schemaVaccinare()
    {
        return "Vaccinul antigripal se administrează la adulti o doza de 0.5 ml, iar la copii si adolescenti o doza de 0.3 ml, repetandu-se din 2 in 2 ani";
    }

};


AntiGripal::AntiGripal(int pret, int temperatura, string substante, string tulpina, string respecta):Vaccin(pret, temperatura, substante, numeProducator)
{
    this->tulpina = tulpina;
    this->respecta = respecta;
}

AntiGripal::~AntiGripal(){
}

AntiGripal::AntiGripal(AntiGripal &z):Vaccin(z)
{
   tulpina= z.tulpina;
   respecta = z.respecta;
}

void AntiGripal::citire(istream &in){
    Vaccin::citire(in);
    cout<<"tulpina este :";
    cin>>tulpina;
    cout<<"Vaccinul respecta indicatiile: ";
    cin>>respecta;
}

void AntiGripal::afisare(ostream &out){
    Vaccin::afisare(out);
    cout<<"tulpina este :"<<tulpina<<endl;
    cout<<"Vaccinul respecta indicatiile:"<<respecta<<endl;
}

istream& operator>>(istream& in,AntiGripal& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, AntiGripal& z){
    z.afisare(out);
    return out;
}


AntiGripal& AntiGripal :: operator=(AntiGripal &z)
{
    if(this!=&z)
    {
        Vaccin::operator=(z);
        tulpina= z.tulpina;
        respecta = z.respecta;

    }
    return *this;
}

class AntiHepatic:public Vaccin{
private:
    string tipHepatita;
    string modul;
public:
    AntiHepatic(int pret, int temperatura, string substante, string tipHepatita, string modul);
    AntiHepatic(){pret=0; temperatura=0, substante = "Necunoscute", tipHepatita = "Necunoscuta", modul = "Necunoscute";};
    AntiHepatic(AntiHepatic&);
    ~AntiHepatic();

    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream &in, AntiHepatic& z);
    friend ostream& operator<<(ostream &out, AntiHepatic& z);
    AntiHepatic& operator=(AntiHepatic &z);
    string schemaVaccinare()
    {
        return " Antihepatita A și B, la copii cu varsta mai mica de 1 an se adminstreaza 2 injectari la un interval de o luna, a treia injectare după 6 luni de la prima administrare, laadulți conform schemei de imunizare recomandată de medic; cel Antihepatita C doar la recomandarea medicului";
    }

};


AntiHepatic::AntiHepatic(int pret, int temperatura, string substante, string tipHepatita, string modul):Vaccin(pret, temperatura, substante, numeProducator)
{
    this->tipHepatita = tipHepatita;
    this->modul = modul;
}

AntiHepatic::~AntiHepatic(){
}

AntiHepatic::AntiHepatic(AntiHepatic &z):Vaccin(z)
{
   tipHepatita= z.tipHepatita;
   modul = z.modul;
}

void AntiHepatic::citire(istream &in){
    Vaccin::citire(in);
    cout<<"tipHepatita este :";
    cin>>tipHepatita;
    cout<<"Modul de vaccinare: ";
    cin>>modul;
}

void AntiHepatic::afisare(ostream &out){
    Vaccin::afisare(out);
    cout<<"tipHepatita este :"<<tipHepatita<<endl;
    cout<<"Modul de vaccinare:"<<modul<<endl;
}

istream& operator>>(istream& in,AntiHepatic& z){
    z.citire(in);
    return in;
}

ostream& operator<<(ostream& out, AntiHepatic& z){
    z.afisare(out);
    return out;
}


AntiHepatic& AntiHepatic :: operator=(AntiHepatic &z)
{
    if(this!=&z)
    {
        Vaccin::operator=(z);
        tipHepatita= z.tipHepatita;
        modul = z.modul;

    }
    return *this;
}
class Comanda{
protected:
    string data;
    int cantitate;
    string nume;
    string numeSpital;
public:
    Comanda(string data, int cantitate, string nume, string numeSpital);
    Comanda(Comanda&);
    virtual ~Comanda();

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream &in, Comanda& z);
    friend ostream& operator<<(ostream &out, Comanda& z);

    Comanda& operator=(Comanda &z);
};
Comanda::Comanda(string data, int cantitate, string nume, string numeSpital){
this->data = data;
this->cantitate = cantitate;
this->nume = nume;
this->numeSpital = numeSpital;
}
Comanda::Comanda(Comanda &z){
   this->data = z.data;
this->cantitate = z.cantitate;
this->nume = z.nume;
this->numeSpital = z.numeSpital;
}

Comanda::~Comanda(){

}

void Comanda::citire(istream &in){
    cout<<"Introduceti numele spitalului:";cin>>numeSpital;
    cout<<"Introduceti cantitatea :";cin>>cantitate;
    cout<<"Introduceti numele vaccinului :";cin>>nume;
    cout<<"Introduceti cantitatea :";cin>>data;
}

istream& operator>>(istream& in,Comanda& z){
    z.citire(in);
    return in;
}

void Comanda::afisare(ostream &out){
    cout<<"Numele spitalului:"<<numeSpital;
    cout<<"Cantitate: "<<cantitate;
    cout<<"Vaccin: "<<nume;
    cout<<"Data :"<<data;

}


ostream& operator<<(ostream& out, Comanda& z){
    z.afisare(out);
    return out;
}

Comanda& Comanda::operator=(Comanda &z){
    if (this!=&z)
    {

    return *this;
}

}

void menu_output(vector<AntiGripal*> G, vector<AntiHepatic*> H, vector<SarsCov*> S)//Meniu asemanator cu cel de la laborator
{
cout<<"Meniu"<<endl;
cout<<"1.Adaugarea unui vaccin nou"<<endl;
cout<<"2.Afisarea tuturor vaccinurilor detinute"<<endl;
}
void menu()
{
    int option;
    vector<AntiGripal*> Gripal;
    vector<AntiHepatic*> Hepatic;
    vector<SarsCov*> Sars;
    AntiGripal G;
    AntiHepatic H;
    SarsCov S;
    vector<AntiGripal*>::iterator it;
    vector<AntiHepatic*>::iterator it2;
    vector<SarsCov*>::iterator it3;
    do
    {
        menu_output(Gripal, Hepatic, Sars);
        cin>>option;
        if(option==1)
        {   string tip;//Se face un loop aici , nu inteleg de ce.
            cout<<"Introduceti tipul de vaccin: "<<endl;
            cin>>tip;
            cout<<tip;
            try
            {
                if(tip=="Covid" || tip=="AntiCovid")
                {
                    cin>>S;
                    Sars.push_back(&S);
                }
                else
                    if(tip=="Gripal" || tip=="AntiGripal")
                {
                    cin>>G;
                    Gripal.push_back(&G);
                }
                else
                    if(tip=="Hepatic" || "AntiHepatic")
                {
                    cin>>H;
                    Hepatic.push_back(&H);
                    break;
                }
                else
                    throw 10;



            }
                catch(bad_alloc var )
                {
                    cout<<"Allocation failure";
                    break;
                }
                catch(int tip)
                {
                    cout<<"Te rog sa introduci o optiune valida";
                }


    }
    if(option==2)
    {
        //cout<<"Vaccinurile antigripale sunt: ";
       // for(it=Gripal.begin();it!=Gripal.end();++it)
//            cout<<*it;
        //cout<<"Vaccinurile antiHepatice sunt: ";
        //for(it2=Hepatic.begin();it2!=Hepatic.end();++it2)
         //   cout<<(*it2);
    }
    }
    while(option!=0);

}
int main()
{
AntiGripal a;
AntiHepatic b;
SarsCov c;
cin>>a>>b>>c;
cout<<a<<b<<c;
Vaccin *list[3];
list[0] = new AntiGripal;
list[1] = new AntiHepatic;
list[2] = new SarsCov;
for(int i=0;i<3;i++)
    list[i]->schemaVaccinare();
}

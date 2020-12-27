#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

class Client
{
         const int ID_Persoana;
         int nrMarimi;
         int* marimi;
         bool abonament;
         char* nume;
         char genul[0];
         int varsta ;
         float* greutate ;
         double numarCaloriiMentinere ;
         int pretAbonament = 80;
   public :
    static int lunaCurenta;
    static void mesaj ()
    {

    cout<<"Bine ati venit la World gym!";

    }

    Client():ID_Persoana(00000)
    {
    varsta =0;
    abonament = false;
    nume = "Anonim";
    nume = new char [strlen("Niciuna")+1];
    strcpy(this->nume, "Niciuna");
    numarCaloriiMentinere = 0;
    greutate = 0;
    marimi = NULL;
    }



    Client(int id, bool abonament,int nrMarimi, int* marimi, char* nume, int varsta, float* greutate, double numarCaloriiMentinere, char genul[0] ):ID_Persoana(id)
    {

        this->varsta = varsta;
        this->nume = new char [strlen(nume)+1];
        strcpy(this->nume, nume);

        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];

        for (int i = 0; i<nrMarimi; i++)
        {
            this->marimi[i] = marimi[i];
        }

        this-> greutate = new float [2];

        for  (int i = 0;i<2;i++){
            this->greutate[i] = greutate[i];
        }
        this-> genul[0]= genul[0];

        this-> abonament = abonament;

    }

    Client(const Client& cl):ID_Persoana(cl.ID_Persoana)
    {
        this->varsta = cl.varsta;

        this->nume = new char [strlen(nume)+1];
        strcpy(this->nume, cl.nume);
        this->nrMarimi = cl.nrMarimi;

        this->marimi = new int [cl.nrMarimi];

        for (int i =0; i<cl.nrMarimi;i++){
        this->marimi[i] = cl.marimi[i];
        }
        this->greutate = new float [2];

        for (int i = 0;i<2;i++){
        this->greutate[i] = cl.greutate[i];
        }

        this->genul[0] = cl.genul[0];

        this->abonament = cl.abonament;

        }

    Client& operator= (const Client& cl)
    {

        if(this!=&cl)
            {
        this->varsta = cl.varsta;

        this->nrMarimi = cl.nrMarimi;

        if (this->nume!=NULL)
            delete[] this->nume;

        this->nume = new char [strlen(cl.nume)+1];
        strcpy(this->nume,cl.nume);

        if(this->marimi!=NULL)
            delete [] this->marimi;

        this->marimi = new int [cl.nrMarimi];

        for (int i =0; i<= cl.nrMarimi;i++)
            this->marimi[i] = cl.marimi[i];

        if(this->greutate!=NULL)
            delete this->greutate;

        this->greutate = new float [2];

        for(int i =0;i<=2;i++)
            this->greutate[i] = cl.greutate[i];

        this->genul[0]  = cl.genul[0];

        this->abonament = cl.abonament;
    }
    }

    friend ostream& operator<<(ostream& out, const Client cl)
    {

    out<<"\nClientuL "<<cl.nume<<" are urmatoarele marimi : ";
    for (int i =0; i<cl.nrMarimi;i++){
        out<<cl.marimi[i]<<", ";
    }
    out<<endl;
    out<<"Acesta are "<<cl.varsta<<" ani\n";
    out<<"Acesta are greutatea "<<cl.greutate[0]<<" si isi doreste sa ajunga la greutatea "<< cl.greutate[1]<<endl;
    out<<cl.genul;
    if(strcmp(cl.genul, "M") == 0)
        out<<"Acesta este barbat \n";

    return out;


    }
    friend istream& operator>>(istream& in, Client& cl)
    {//VARSTA STRICA VARIABILA GENUL[0], NU INTELEG DE CE.

        char aux[100];


        cout<<"Introduceti numele persoanei :\n";
        in>>aux;
        if(cl.nume!=NULL)
            delete [] cl.nume;

        cl.nume = new char[strlen(aux)+1];
        strcpy(cl.nume, aux);


        cout<<"Introduceti varsta :\n";
        in>>cl.varsta;

        cout<<"Introduceti numarul de marimi pe care vreti sa le introduceti : Inaltime / Bust/ Abdomen / Solduri (1/2/3/4)";
        in>>cl.nrMarimi;
        cout<<"Introduceti marimile \n";
        if(cl.marimi!=NULL)
            delete [] cl.marimi;
        cl.marimi = new int [cl.nrMarimi];
        for (int i = 0; i<cl.nrMarimi; i++)
            {
            in>>cl.marimi[i];
            }
        cout<<"Introduceti greutatile (Greutatea actuala + Greutatea la care se doreste sa se ajunga) : \n";
        if(cl.greutate!=NULL)
            delete []cl.greutate;
        cl.greutate = new float [2];
        for (int i = 0; i<2; i++)
            {
            cout   <<"Introduceti greutatea "<<i<<" \n";
            in>>cl.greutate[i];
            }
        cout<<"Introduceti genul dumneavoastra : M / F ";
        in>>cl.genul[0];
        cout<<&cl.genul[0];
        return in;

    }

   /* const Client operator++()
    {
    this->varsta++;
    return *this;
    }

    const Client operator++(int)
    {
        Client aux(*this);
        this->varsta++;
        return aux;
    }
    */

    Client operator+(int a)
    {
        int marimi2 [100];
        if (this->marimi!=NULL)
        {
         for(int i =0;i<this->nrMarimi;i++)
         marimi2[i]=this->marimi[i];
        delete this->marimi;
        }
        this->nrMarimi++;
        for (int i=0;i<nrMarimi;i++)
            this->marimi[i]=marimi2[i];
        this->marimi[nrMarimi-1]=a;
        return *this;
    }
    Client operator -(int a)
    {   int marimi3[100];
        if(this->marimi!=NULL)
        {
            for(int i =0;i<this->nrMarimi;i++)
                marimi3[i]=marimi[i];
            delete []this->marimi;
        }
        this->nrMarimi--;
        for(int i=0;i<nrMarimi;i++)
            this->marimi[i]=marimi3[i];
        return *this;
    }
    int operator [](int index)
    {
        if(index<this->nrMarimi&&index>0)
            return this->marimi[index];
        else
        {
            cout<<"Index invalid";
            return -1;
        }

    }

       void Citire()
    {
        char aux[100];

        cout<<"Introduceti numele persoanei :\n";
        cin.get(aux,100);

        this->nume = new char [strlen(aux)+1];
        strcpy(this->nume, aux);

        cout<<"Introduceti varsta\n";
        cin>>this->varsta;

        cout<<"Introduceti numarul de marimi pe care vreti sa le introduceti : Inaltime + Bust + Abdomen + Solduri (1/2/3/4)";
        cin>>this->nrMarimi;
        cout<<"Introduceti marimile \n";
        this->marimi = new int [this->nrMarimi];
        for (int i = 0; i<this->nrMarimi; i++)
            {
            cin>>this->marimi[i];
            }
        cout<<"Introduceti greutatile (Greutatea actuala + Greutatea la care se doreste sa se ajunga) : \n";
        this->greutate = new float [2];
        for (int i = 0; i<2; i++)
            {
            cout   <<"Introduceti greutatea "<<i<<" \n";
            cin>>this->greutate[i];
            }
        cout<<"Introduceti genul dumneavoastra : M / F ";
        cin>>this->genul[0];


    }
    void Afisare()

    {
      cout<<"Clientul cu numele " << this->nume<<" este de genul "<< this->genul<<" si are ca target greutatea "<< greutate[1]<< " acesta plecand de la greutatea "<<greutate[0] <<"\n";
     // cout<<"Acesta are nevoie de "<<calculNumarCalorii()<< " calorii pentru a-si mentine greutatea";


    }
        int getID()
        {
            return this->ID_Persoana;
        }

        int getnrMarimi(){
            return this->nrMarimi;
        }

        int* getMarimi(){
        return this->marimi;
        }

        char* getNume(){
        return this->nume;
        }

        float* getGreutate(){
        return this->greutate;
        }

        int getVarsta(){
        return this->varsta;
        }

        char getGenul(){
        return this->genul[0];
        }
        bool getAbonament(){
        return this->abonament;
        }
        int getnumarCalorii()
        {
            return this->numarCaloriiMentinere;
        }

        void setVarsta(int a)
        {
        this->varsta = a;
        }


        void setNume(char* a)
        {
            if (this->nume!=nullptr)
                delete [] this->nume;
            this->nume = new char [strlen(a)+1];
                strcpy(this->nume,a);
        }

        void setMarimi(int* a, int b)
        {
            if (this->marimi!=nullptr)
                delete [] this->marimi;
            this->nrMarimi = b;
            this->marimi = new int [b];
            for (int i =0 ; i<nrMarimi;i++)
                this->marimi[i] = marimi[i];
        }

        void setGreutate(float* a)
        {
        if(this->greutate!=nullptr)
            delete[] this->greutate;
        this->greutate = new float[2];
        for (int i = 0; i<2;i++)
            this->greutate[i] = a[i];
        }

        void setGenul(char b)
        {
        this->genul[0]  = b;
        }

        void setnrMarimi(int a)
        {
        this->nrMarimi = a;
        }

        double calculNumarCalorii()
        {
            cout<<this->greutate[0]<<endl;
            cout<<this->marimi[0]<<endl;
            cout<<this->varsta<<endl;
            if (strcmp(&this->genul[0], "F") == 0)
            this->numarCaloriiMentinere = 10 * this->greutate[0] + 6.25 * this->marimi[0] - 5*varsta + 5;

            if (strcmp(&this->genul[0], "M") == 0)
            this->numarCaloriiMentinere = 10* this->greutate[0] +6.25 * this->marimi[0] - 5*varsta + 161;


        return this->numarCaloriiMentinere;
        }


        ~Client()
        {
        if (this->marimi!=nullptr)
            delete this->marimi;
        if(this->nume!=nullptr)
            delete this->nume;
        if(this->greutate!=nullptr)
            delete this->greutate;
        }

};

class Sala
{
    const int ID_Sala;
    int zileDeschise[7];
    int codZIP;
    char* numeSala;
    float* coordonate; //Coordonatele GPS ale salii;
    int* persoaneAbonate;
    bool deschisa;
    int nrCoordonate;
    int nrPersoane;
    //char conditie[1]; // Salile sunt repartizate pe conditii : B = Doar Fitness / Doar Bodybuilding, S = Fitness+Bodybuilding, G= Fitness+Bodybuilding+Inot//
public:
    static void mesaj()
    {
        cout<<"Bine ati venit la ";
    }

    Sala():ID_Sala(00000){
        codZIP=0;
        deschisa = true;
        nrCoordonate=0;
        nrPersoane=0;
        numeSala = "Necunoscut";
        numeSala = new char [strlen("Necunoscut")+1];
        strcpy(numeSala, "Necunoscut");
        coordonate=NULL;
        persoaneAbonate = NULL;
        for (int i =0; i<7;i++)
            zileDeschise[i] = 0;

    }

    Sala(int id, bool deschisa, int nrPersoane, int codZIP, int zileDeschise[7], char* numeSala, float* coordonate, int nrCoordonate, int* persoaneAbonate /*char conditie[1] */):ID_Sala(id)
    {

    this-> deschisa = deschisa;

    this->numeSala = new char [strlen(numeSala)+1];

    strcpy(this->numeSala,numeSala);

    for (int i = 0;i<7;i++)
        this->zileDeschise[i]=zileDeschise[i];

    this->codZIP = codZIP;

    this->nrCoordonate = nrCoordonate;

    this->coordonate = new float [nrCoordonate];
    for(int i = 0; i<nrCoordonate; i++ )
    {
        this->coordonate[i] = coordonate[i];
    }
    this->nrPersoane = nrPersoane;

    this->persoaneAbonate = new int[nrPersoane];
    for (int i =0; i<nrPersoane;i++)
        this->persoaneAbonate[i] = persoaneAbonate[i];

    //this->conditie[1] = conditie[1];


    }

    Sala(const Sala& sl):ID_Sala(sl.ID_Sala)
    {

    this-> deschisa = sl.deschisa;

    this->numeSala = new char [strlen(numeSala)+1];

    strcpy(this->numeSala,sl.numeSala);

    for (int i = 0;i<7;i++)
        this->zileDeschise[i]=sl.zileDeschise[i];

    this->codZIP = sl.codZIP;

    this->nrCoordonate = sl.nrCoordonate;

    this->coordonate = new float [sl.nrCoordonate];
    for(int i = 0; i<sl.nrCoordonate; i++ )
        this->coordonate[i] = sl.coordonate[i];

    this->nrPersoane = sl.nrPersoane;

    this->persoaneAbonate = new int[sl.nrPersoane];
    for (int i =0; i<sl.nrPersoane;i++)
        this->persoaneAbonate[i] = sl.persoaneAbonate[i];

    //this->conditie[1] = sl.conditie[1];
}

    Sala& operator= (const Sala& sl)
    {
    if (this!=&sl)
        {
        this->deschisa= sl.deschisa;

        if (this->numeSala!=NULL)
            delete [] this->numeSala;

        this->numeSala = new char[strlen(sl.numeSala)+1];
        strcpy(this->numeSala,sl.numeSala);

        for (int i =0 ; i<7; i++)
            this->zileDeschise[i] = sl.zileDeschise[i];

        this->nrCoordonate = sl.nrCoordonate;

        if(this->coordonate!=NULL)
            delete  this->coordonate;

        this->coordonate = new float [sl.nrCoordonate];

        for (int i =0;i<=sl.nrCoordonate;i++)
            this->coordonate[i]= sl.coordonate[i];

        if(this->persoaneAbonate!=NULL)
            delete this->persoaneAbonate;

        this->persoaneAbonate = new int[sl.nrPersoane];

        for (int i =0; i<sl.nrPersoane;i++)
            this->persoaneAbonate[i] = sl.persoaneAbonate[i];

        //this->conditie[1] = sl.conditie[1];
    }

    }
     float operator [](int index)
    {
        if(index<7&&index>0)
            return zileDeschise[index];
        else
        {
            cout<<"Nu se gaseste index-ul";
            return -1;
        }
    }

    friend ostream& operator<<(ostream& out, const Sala& sl)
    {
    out<<"Sala cu numele "<<sl.numeSala<<" se afla in locatia cu coordonatele ";
    for (int i=0;i<sl.nrCoordonate;i++)
    {

       out<<sl.coordonate[i]<<" ";
    }
    out<<"Aceasta are momentan "<< sl.nrPersoane<<" abonate";
    //out<<"Sala este de tipul"<<sl.conditie;

    return out;
    }

    friend istream& operator>>(istream& in, Sala& sl)
    {
        char aux[100];

        cout<<"Introduceti numele salii: \n";
        in>>aux;
        if(sl.numeSala!=NULL)
                delete [] sl.numeSala;
        sl.numeSala = new char [strlen(aux)+1];
        strcpy(sl.numeSala,aux);

        cout<<"Introduceti codul postal :\n";
        in>>sl.codZIP;

        cout<<"Introduceti numarul de coordonate pe care vreti sa le introduceti: \n";
        in>>sl.nrCoordonate;

        if(sl.coordonate!=NULL)
            delete []sl.coordonate;

        sl.coordonate = new float [sl.nrCoordonate];
        for (int i =0;i<sl.nrCoordonate;i++)
        {
            cout<<"Introduceti coordonata cu numarul: " << i+1<< "\n";
            in>>sl.coordonate[i];
        }

        cout<<"Introduceti numarul de persoane care sunt abonate la aceasta sala: \n";
        in>>sl.nrPersoane;
        sl.persoaneAbonate = new int[sl.nrPersoane];

        if(sl.persoaneAbonate!=NULL)
            delete [] sl.persoaneAbonate;

        for (int i =0 ;i<sl.nrPersoane;i++)
        {
            cout<<"Introduceti ID-ul persoanei cu numarul" <<i+1<< "\n";
            in>>sl.persoaneAbonate[i];
        }

        cout<<"Introduceti zilele in care sala este deschisa : 0(Inchis), 1(Deschisa) :\n" ;

        for (int i = 0;i<7;i++)
        {
                cout<<"Introduceti disponibilitatea pentru ziua "<<i+1<<" \n";
                in>>sl.zileDeschise[i];
        }

        //cout<<"Introduceti tipul salii";
        //in>>sl.conditie[1];
        return in;
    }

    void Citire()
    {
        char aux[100];

        cout<<"Introduceti numele salii: \n";
        cin>>aux;

        this->numeSala = new char [strlen(aux)+1];
        strcpy(this->numeSala,aux);

        cout<<"Introduceti codul postal :\n";
        cin>>this->codZIP;

        cout<<"Introduceti numarul de coordonate pe care vreti sa le introduceti: \n";
        cin>>this->nrCoordonate;

        this->coordonate = new float[nrCoordonate];
        for (int i =0;i<nrCoordonate;i++)
        {
            cout<<"Introduceti coordonata cu numarul: " << i+1<< "\n";
            cin>>this->coordonate[i];
        }

        cout<<"Introduceti numarul de persoane care sunt abonate la aceasta sala: \n";
        cin>>this->nrPersoane;
        this->persoaneAbonate = new int[this->nrPersoane];

        for (int i =0 ;i<this->nrPersoane;i++)
        {
            cout<<"Introduceti ID-ul persoanei cu numarul" <<i+1<< "\n";
            cin>>this->persoaneAbonate[i];
        }

        cout<<"Introduceti zilele in care sala este deschisa : 0(Inchis), 1(Deschisa) :\n" ;

        for (int i = 0;i<7;i++)
        {
                cout<<"Introduceti disponibilitatea pentru ziua "<<i+1<<" \n";
                cin>>zileDeschise[i];
        }

        //cout<<"Introduceti tipul salii";
        //cin>>this->conditie[1];
    }

    void Afisare()
    {
    cout<<"Sala cu numele "<<this->numeSala<<" se afla in locatia cu coordonatele: ";
    for (int i=0;i<this->nrCoordonate;i++)
        cout<<this->coordonate[i]<<" ";


    cout<<"Aceasta are momentan "<< this->nrPersoane<<" abonate.";
    //cout<<"Sala este de tipul "<<this->conditie[1];

    }

    char* getNume()
    {
        return this->numeSala;
    }
    int* getProgram()
    {
        return this->zileDeschise;
    }
    int getCod()
    {
        return this->codZIP;
    }
    int getID()
    {
       return this->ID_Sala;
    }
    float* getCoordonate()
    {
        return this->coordonate;
    }
    int* getPersoaneAbonate()
    {
        return this->persoaneAbonate;
    }
    bool getDeschisa()
    {
        return this->deschisa;
    }
    /*char* getConditie()
    {
        return this->conditie;
    }
    */
    void setNume(char* a)
    {
        if(this->numeSala!=NULL)
            delete [] this->numeSala;
        this->numeSala = new char [strlen(a)+1];
        strcpy(this->numeSala,a);
    }

    void setCoordonate(float*a, int b)
    {
        if(this->coordonate!=NULL)
            delete [] this->coordonate;
        this->nrCoordonate = b;
        this->coordonate = new float [b];
        for (int i=0;i<b;i++)
            this->coordonate[i] = a[i];
    }

    void setPersoane(int *a, int b)
    {
     if(this->persoaneAbonate!=NULL)
            delete []this->persoaneAbonate;
     this->nrPersoane = b;
     this->persoaneAbonate = new int [b];
     for (int i =0; i<b;i++)
        this->persoaneAbonate[i] = a[i];
    }

    void setProgram(int a[7])
    {
        for (int i =0; i<=7; i++)
            this->zileDeschise[i] = a[i];
    }
   /* void setConditie(char a[1])

    {
        this->conditie[1] = a[1];
    }
*/
    void setDeschisa(bool a)
    {
        this->deschisa = a;
    }

    void setZIP(int a)
    {
        this->codZIP = a;
    }

    void disponibilitateSala()
    {   int a;
        cout<<"Spuneti in ce zi at dori sa mergeti la o sala din complexul nostru"<<endl;
        cin>>a;
        if(this->zileDeschise[a]==1)
            cout<<"Exista o sala disponibila, aceasta sala se poate gasi in orasul cu codul postal: "<<this->codZIP<<endl;
        else
        {
            cout<< "Ne pare rau, nu avem sali disponibile in zona dumneavoastra\n";
        }
    }

        ~Sala()
    {
        if(this->coordonate!=nullptr)
            delete []this->coordonate;
        if(this->numeSala!=nullptr)
            delete []this->numeSala;
        if(this->persoaneAbonate!=nullptr)
            delete []this->persoaneAbonate;
    }


};

class ProgramAntrenament
{//CLASE ABSTRACTE >>
protected:
    int zileDisponibile;
    int caloriiMentinere;
    float *greutate;

public:
    void target()
    {
        if(greutate[0]<greutate[1])
        cout<<"Target-ul dumneavoastra este sa luati in greutate";
        if(greutate[0]>greutate[1])
        cout<<"Target-ul dumneavoastra este sa slabiti";
    }
    virtual void calcularecalorii()
    {
        cout<<"Targetul caloric este "<<caloriiMentinere<<endl;
    }
    ProgramAntrenament()
    {
        zileDisponibile = 0;
        caloriiMentinere = 0;
        greutate = NULL;
    }
    ProgramAntrenament(int zileDisponibile, int caloriiMentinere, float* greutate)
    {
        this->zileDisponibile = zileDisponibile;

        this->caloriiMentinere = caloriiMentinere;

        for(int i=0;i<2;i++)
        {
            this->greutate[i] = greutate[i];
        }

    }
    ProgramAntrenament(const ProgramAntrenament& li)
    {
        this->zileDisponibile = li.zileDisponibile;

        this->caloriiMentinere = li.caloriiMentinere;

        for(int i=0;i<2;i++)
            this->greutate[i] = li.greutate[i];

    }
    friend istream& operator>>(istream& in, ProgramAntrenament& p)
    {
        cout<<"Numarul de zile disponibile este :\n";
        in>>p.zileDisponibile;
        cout<<"Numarul de calorii pentru mentinere este :\n";
        in>>p.caloriiMentinere;
        if(p.greutate!=NULL)
            delete [] p.greutate;
        p.greutate = new float[2];
        cout<<"Greutatea actuala : \n";
        in>>p.greutate[0];
        cout<<"Greutate target: \n";
        in>>p.greutate[1];
        return in;
    }
    friend ostream& operator<<(ostream& out, const ProgramAntrenament& p)
    {
        out<<"Numarul de zile disponibile pentru dumneavoastra este "<<p.zileDisponibile<<", caloriile de mentinere sunt :"<<p.caloriiMentinere<<"\n";
        return out;
    }
    ~ProgramAntrenament()
    {
        if(this->greutate!=nullptr)
            delete this->greutate;
    }

};
class Slabire: public ProgramAntrenament
{
    public:
    void calcularecalorii()
    {
        int calorii = caloriiMentinere - (10/caloriiMentinere) * 100;
        cout<<"Targetul caloric este "<<calorii;
    }
};

class Greutate : public ProgramAntrenament
{
    public:
    void calcularecalorii()
    {
        int calorii = caloriiMentinere + (10/caloriiMentinere) *100;
        cout<<"Targetul caloric este "<<calorii;
    }
};


class Produse
{
    const int ID_produs;
    char* numeProdus;
    int pret;
    bool disponibilitate;
public:
    Produse():ID_produs(000000)
    {
        numeProdus = "Necunoscut";
        numeProdus = new char [strlen("Necunoscut")+1];
        strcpy(this->numeProdus, "Necunoscut");
        pret = 0;
        disponibilitate = false;
    }
    Produse(int id, char* numeProdus, bool disponibilitate, int pret):ID_produs(id)
    {
        this->disponibilitate = disponibilitate;

        this->pret = pret;

        this->numeProdus = new char [strlen(numeProdus)+1];
        strcpy(this->numeProdus,numeProdus);

    }
       Produse(const Produse& pr):ID_produs(pr.ID_produs)
    {
        this->disponibilitate = pr.disponibilitate;

        this->pret = pr.pret;

        this->numeProdus = new char [strlen(numeProdus)+1];
        strcpy(this->numeProdus,pr.numeProdus);


    }
    Produse& operator= (const Produse& pr)
    {
        if(this!=&pr)
        {

        this->disponibilitate = pr.disponibilitate;

        this->pret = pr.pret;

        if(this->numeProdus!=NULL)
            delete [] this->numeProdus;
        this->numeProdus = new char [strlen(numeProdus)+1];
        strcpy(this->numeProdus,pr.numeProdus);

        }
        return *this;

    }
    friend ostream& operator<<(ostream& out, const Produse& pr)
    {
        out<<"\n Produsul cu numele "<<pr.numeProdus<<" si cu id-ul"<<pr.ID_produs<<" este disponibil "<<pr.disponibilitate;
        out<<"Acesta are pretul de "<<pr.pret;
    }
    friend istream& operator>>(istream& in, Produse& pr)
    {
        char aux[100];
        cout<<"Introduceti numele produsului: \n";
        in>>aux;
        if(pr.numeProdus!=NULL)
            delete [] pr.numeProdus;
        pr.numeProdus = new char[strlen(aux)+1];
        strcpy(pr.numeProdus,aux);

        cout<<"Introduceti pretul :";
        in>>pr.pret;

        cout<<"Introduceti disponibilitatea";
        in>>pr.disponibilitate;

        return in;
    }
     void Citire()
    {
        char aux[100];
        cout<<"Introduceti numele produsului: \n";
        cin.get (aux,100);
        this->numeProdus = new char[strlen(aux)+1];
        strcpy(this->numeProdus,aux);
        delete [] aux;

        cout<<"Introduceti pretul :";
        cin>>this->pret;

        cout<<"Introduceti disponibilitatea";
        cin>>this->disponibilitate;
    }
    void Afisare()
    {
        cout<<"\n Produsul cu numele "<<this->numeProdus<<" si cu id-ul"<<this->ID_produs<<" este disponibil "<<this->disponibilitate<<"\n";
        cout<<"Acesta are pretul de "<<this->pret<<"\n";
    }
    ~Produse()
    {
        if(this->numeProdus!=nullptr)
            delete [] this->numeProdus;
    }
};

class Imbracaminte : public Produse
{
    private:
    char* marime;
    char* tipProdus;
    char culoare[1];//G=Galben,V=verde,A=Albastru,W=Alb,N-Negru,R-Rosu,

public:
    Imbracaminte():Produse()
    {
        marime = "Necunoscut";
        marime = new char [strlen("Necunoscut")+1];
        strcpy(this->marime,"Necunoscut");
        tipProdus = "Necunoscut";
        tipProdus = new char [strlen("Necunoscut")+1];
        strcpy(this->tipProdus,"Necunoscut");
        strcpy(this->culoare," ");
    }
    Imbracaminte(int id, char* numeProdus, bool disponibilitate, int pret, char* marime, char* tipProdus, char culoare[1]):Produse(id, numeProdus, disponibilitate, pret)
    {

        this->marime = new char [strlen(marime)+1];
        strcpy(this->marime, marime);

        this->tipProdus = new char[strlen(tipProdus)+1];
        strcpy(this->tipProdus,tipProdus);

        this->culoare[1] = culoare[1];
    }

    Imbracaminte(const Imbracaminte& im):Produse(im)
    {

        this->marime = new char [strlen(marime)+1];
        strcpy(this->marime, im.marime);

        this->tipProdus = new char[strlen(tipProdus)+1];
        strcpy(this->tipProdus,im.tipProdus);

        this->culoare[1] = im.culoare[1];

    }

    Imbracaminte& operator= (const Imbracaminte& im)
    {
        if(this!=&im)
        {

        Produse::operator=(im);
        if(this->marime!=NULL)
            Produse::operator=(im);
            delete [] this->marime;
        this->marime = new char [strlen(marime)+1];
        strcpy(this->marime, im.marime);

        if(this->tipProdus!=NULL)
            delete [] this->tipProdus;
        this->tipProdus = new char[strlen(tipProdus)+1];
        strcpy(this->tipProdus,im.tipProdus);

        this->culoare[1] = im.culoare[1];

        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Imbracaminte& im)
    {
        out<<(Produse&)im;
        out<<"Culoarea acestei haine este "<<im.culoare<<", de asemenea, marimea este"<<im.marime;
        return out;
    }

    bool operator == (Imbracaminte& im)
    {
        if (strcmp(this->tipProdus,im.tipProdus) == strcmp(this->culoare, im.culoare)== 1)
            return true;
        else
        {
            return false;
        }
    }

    friend istream& operator>>(istream& in, Imbracaminte& im)
    {

        in>>(Produse&)im;
        char aux[100];
        char buf[100];

        cout<<"Introduceti tipul produsului : \n";
        in>>aux;
        if(im.tipProdus!= NULL)
            delete [] im.tipProdus;

        im.tipProdus = new char [strlen(aux)+1];
        strcpy(im.tipProdus,aux);
        delete [] aux;

        cout<<"Introduceti marimea produsului : \n";
        in>>buf;
        if(im.marime!=NULL)
            delete []im.marime;
        im.marime = new char[strlen(buf)+1];
        strcpy(im.marime, buf);


        cout<<"Introduceti culoarea :";
        in>>im.culoare;

        return in;
    }
    void Citire()
    {
        char aux[100];
        Produse::Citire();
        cout<<"Introduceti tipul produsului : \n";
        cin>>aux;
        if(this->tipProdus !=NULL)
            delete [] this->tipProdus;
        this->tipProdus = new char [strlen(aux)+1];
        strcpy(this->tipProdus,aux);

        char buf[100];
        cout<<"Introduceti marimea produsului : \n";
        cin>>buf;
        if(this->marime!=NULL)
            delete [] this->marime;
        this->marime = new char[strlen(buf)+1];
        strcpy(this->marime, buf);


        cout<<"Introduceti culoarea :";
        cin.get(this->culoare,1);

    }

    ~Imbracaminte()
    {
        if(this->tipProdus!=nullptr)
            delete this->tipProdus;
        if(this->marime!=nullptr)
            delete this->marime;
    }

};


class Suplimente : public Produse

{

    private:
    double valoareCalorica;
    char categorie[100];
    int macrouri [3];

public:

    Suplimente():Produse()
    {
        this->valoareCalorica = 0;
        for (int i =0;i<3;i++)
            this->macrouri[i] = 0;
    }

    Suplimente(int id, char* numeProdus, int pret, bool disponibilitate, double valoareCalorica, char categorie[3], int macrouri[3]):Produse(id, numeProdus, disponibilitate, pret)
    {
        this->valoareCalorica = valoareCalorica;

        for (int i =0;i<3;i++)
            this->macrouri[i] = macrouri[i];

        this->categorie [100]= categorie[100];

    }

    Suplimente(const Suplimente& su): Produse(su)
    {
        this->valoareCalorica = su.valoareCalorica;

        for (int i =0;i<3;i++)
            this->macrouri[i] = su.macrouri[i];

        this->categorie [100]= su.categorie[100];

    }

    Suplimente& operator= (const Suplimente& su)
    {
        if(this!=&su)
        {
        Produse::operator=(su);
        this->valoareCalorica = su.valoareCalorica;

        for (int i =0;i<3;i++)
            this->macrouri[i] = su.macrouri[i];

        this->categorie [100]= su.categorie[100];

        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Suplimente& su)
    {
        out<<(Produse&)su;
        out<<" Acesta are urmatoarea valoare calorica "<<su.valoareCalorica<<endl;
        out<<"\n Coeficientul de grasimi, proteine respectiv carbohidrati este: ";
        for(int i = 0; i<3;i++)
            out<<su.macrouri[i]<<", ";
        out<<endl;
        return out;
    }

    friend istream& operator>>(istream& in, Suplimente& su)
    {
        in>>(Produse&)su;
        cout<<"Introduceti valoare calorica\n";
        in>>su.valoareCalorica ;

        cout<<"Introduceti grasimile \n";
        in>>su.macrouri[0];
        cout<<"Introduceti proteinele \n";
        in>>su.macrouri[1];
        cout<<"Introduceti carbohidratii \n";
        in>>su.macrouri[2];

        cout<<"Introduceti categoria produsului \n";
        in>>su.categorie;

        return in;

    }

    void Citire()
    {
        Produse::Citire();

        cout<<"Introduceti valoare calorica\n";
        cin>>this->valoareCalorica ;

        cout<<"Introduceti grasimile\n";
        cin>>this->macrouri[0];
        cout<<"Introduceti proteinele\n";
        cin>>this->macrouri[1];
        cout<<"Introduceti carbohidratii\n";
        cin>>this->macrouri[2];

        cout<<"Introduceti categoria produsului\n";
        cin.get(this->categorie, 100);


    }

    void Afisare()
    {
        Produse::Afisare();
        cout<<" Acesta are urmatoarea valoare calorica "<<this->valoareCalorica;
        cout<<"\n Coeficientul de grasimi, proteine respectiv carbohidrati este: ";
        for(int i = 0; i<3;i++)
            cout<<this->macrouri[i]<<" ";

    }

    char* tipSupliment()
    {
        if(this->macrouri[0]<20&&this->macrouri[1]<15)
            return "Acest produs este bun pentru mentinerea masei corporale";
        if(this->macrouri[0]<20&&this->macrouri[1]>15)
            return "Acest produs este bun pentru cresterea masei musculare";
        if(this->macrouri[0]>25&&this->valoareCalorica>550)
            return "Acest produs nu este optim pentru o dieta echilibrata";
            else
                {
                    return "Nu se poate spune nimic despre acest produs";
                }
    }



};

void menu_output(vector<Client*> C,int  nrDateC, vector<Produse*> P, int nrDateP, vector<Sala*> S, int nrDateS, int nr)
{
    if(nr==0)
    {
    cout<<"Bine ati venit la World Gym ! \n";
    cout<<"MENIU \n";
    cout<<"------------------------------------------"<<endl;
    }
    cout<<endl;
    cout<<"0.Iesire"<<endl;
    cout<<"1.Introduceti o persoana in baza de date, de asemenea, se introduce si in fisier."<<endl;
    cout<<"2.Introduceti o sala in baza de date, de asemenea, se introduce si in fisier."<<endl;
    cout<<"3.Introduceti un produs in baza de date, de asemenea, se introduce si in fisier."<<endl;
    cout<<"4.Afisare informatii persoana"<<endl;
    cout<<"5.Afisare informatii sala"<<endl;
    cout<<"6.Afisare informatii produs"<<endl;
    cout<<"7.Verificati disponibilitatea unei sali intr-o anumita zi"<<endl;
    cout<<"8.Verificati tipul de supliment"<<endl;
    cout<<"9.Verificati daca se potriveste o haina"<<endl;
    cout<<"10.Verificati numarul de calorii pentru mentinere"<<endl;
}

void menu()
{
    int option = 0;
    vector<Client*> Clie;
    vector<Sala*> Sal;
    vector<Produse*> Prod;
    Client c1;
    Sala s2;
    Produse p1;
    int nrDateC = 0;
    int nrDateS = 0;
    int nrDateP = 0;
    int index=0;
    int nr = 0;
    ofstream fisier;
    fisier.open("datein.txt");
    do
    {
        menu_output(Clie, nrDateC, Prod, nrDateP, Sal, nrDateS, nr);
        cin>>option;
        nr++;
        if(option==0)
        {
            fisier.close();
            break;

        }
        if(option==1)
        {
            cin>>c1;
            Clie.push_back(&c1);
            nrDateC++;

        }

        if(option==2)
        {
            s2.Citire();
            Sal.push_back(&s2);
            nrDateS++;
        }
        if(option==3)
        {
            cin>>p1;
            Prod.push_back(&p1);
            nrDateP++;
        }
        if(option==4)
        {
            int a;
            cout<<"Momentan avem "<< nrDateC<<" persoane."<<endl;
            cout<<"Alegeti persoana pe care vreti sa o detaliem :"<<endl;
            cin>>a;
            try
            {
                if(a>0&&a<=nrDateC)
                {
                   cout<<*Clie[a-1]<<endl;
                   fisier<<*Clie[a-1];
                }
                else
                {
                    throw(a);
                }
            }
            catch(int a)
            {

                if(a<0)
                cout<<"Numarul introdus de dumneavoastra este negativ, va rog sa introduceti unul pozitiv"<<endl;
                else
                {
                   cout<<nrDateC;
                    cout<<"Numarul dumneavoastra este mai mare decat numarul de persoane pe care il avem in baza de date"<<endl;
                }
            }
            catch(...)
            {
                cout<<"Eroare, ati introdus un sir de caractere"<<endl;
            }
        }
        if(option==5)
        {   int b;
            cout<<"Momentan avem "<<nrDateS<<" Sali."<<endl;
            cout<<"Alegeti sala pe care vreti sa o detaliem :"<<endl;
            cin>> b;
            try {
                if (b>0&&b<=nrDateS)
                {
                    cout<<*Sal[b-1]<<endl;
                    fisier<<*Sal[b-1]<<endl;
                }
                else
                {
                    throw(b);
                }
            }
                catch(int b)
                {

                if(b<0)
                cout<<"Numarul introdus de dumneavoastra este negativ, va rog sa introduceti unul pozitiv"<<endl;
                else
                {
                    cout<<nrDateC;
                    cout<<"Numarul dumneavoastra este mai mare decat numarul de persoane pe care il avem in baza de date"<<endl;
                }
                }
            catch(...)
            {
                cout<<"Eroare, ati introdus un sir de caractere"<<endl;
            }

        }
        if(option==6)
        {   int c;
            cout<<"Momentan avem"<<nrDateP<<" produse."<<endl;
            cout<<"Alegeti produsul despre care vreti sa vorbim: "<<endl;
            cin>>c;
            try{
                if(c>0&&c<=nrDateS)
                {
                    cout<<*Prod[c-1]<<endl;
                    fisier<<*Prod[c-1]<<endl;
                }
                else
                {
                    throw(c);
                }
            }
                catch(int c)
            {

                if(c<0)
                cout<<"Numarul introdus de dumneavoastra este negativ, va rog sa introduceti unul pozitiv"<<endl;
                else
                {
                    cout<<nrDateC;
                    cout<<"Numarul dumneavoastra este mai mare decat numarul de persoane pe care il avem in baza de date"<<endl;
                }
            }
            catch(...)
            {
                cout<<"Eroare, ati introdus un sir de caractere"<<endl;
            }
        }
        if(option==7)
        {
            cout<<"Introduceti numarul salii despre care vreti sa aflati: "<<endl;
            cin>>index;
            Sal[index-1]->disponibilitateSala();
        }
        if(option==8)
        {
            //DOWNCASTING, UPCASTING
        }
        if(option==9)
        {
            //DOWNCASTING, UPCASTING

        }
        if(option==10)
        {
            int A;
            cout<<"Introduceti numarul persoanei :"<<endl;
            cin>>A;
            cout<<"Numarul de calorii necesare pentru mentinerea greutatii este: ";
            cout<<Clie[A-1]->calculNumarCalorii()<< ". \n";
        }
        if(option>10 || option<=0)
        {
            cout<<"Introduceti un numar valid"<<endl;
        }
    }
    while (option!=0);
}
 /*
    Planuri :
    Clasa client sa fie o clasa care mosteneste clasa entitate: ENTITATE->CLIENT, ENTITATE->ANTRENOR, ENTITATE->ANGAJAT
    ->Idee cu clasa ProgramAntrenament : ne folosim de datele din client, sala si supliment pentru un rpogram.
    ->Idee cu sponsori pentru produse.
    Raman cateva overload-uri la clasele principale.
    Nu sunt comentate toate liniile, doar variabilele.
    Aici adaug sau completez ideile.
    */
int main()
{
   menu();




}

#include <iostream>
#include <string.h>// strcpy, strlen....

using namespace std;

class Student{
// private, protected, public

private:
    const int ID_Matricol;
    int varsta;
    char* nume;
    int nrNote;
    int* note;
public:
    static int anCurent;
    static void mesaj(){

        cout<<"Bine ati venit studenti de anul  "<<anCurent;

    }

    Student():ID_Matricol(00000){

        varsta=0;
        nume=new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        note=NULL;

    }



    Student(int id,int varsta, char* nume, int nrNote, int* note):ID_Matricol(id){

        this->varsta=varsta;

        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);

        this->nrNote=nrNote;

        this->note=new int[nrNote];

        for(int i=0; i<nrNote; i++)
            this->note[i]=note[i];



    }

    void citire(){


        char aux[100];

        cout<<"\n Introduceti numele";
        cin>>aux;

        this->nume=new char[strlen(aux)+1];
        strcpy(this->nume,aux);
        cout<<"Intoduceti varsta ";
        cin>>this->varsta;

        cout<<"\nIntroduceti numarul de nota ";
        cin>>this->nrNote;

        this->note=new int[this->nrNote];
        cout<<"\nIntroduceti notele: ";
        for(int i=0; i<nrNote; i++)
            cin>>this->note[i];







    }


    Student(int varsta):ID_Matricol(00){

        this->varsta=varsta;

    }


    void afisare(){

        cout<<"Student "<<this->nume<<" are "<<this->nrNote<<"  note, "<<" notele: ";
        for(int i=0; i<this->nrNote; i++)
            cout<<this->note[i]<<" ";

    }
    int getNrNote(){

        return this->nrNote;
    }

    char* getNume(){
        return this->nume;
    }
    int* getNote(){
        return this->note;// forma frumoasa este cu this

    }
    int getVarsta(){
        return varsta;

    }

    void setVarst(int a)
    {
        this->varsta=a;
    }

    void setNume(char* a){

            if(this->nume!=nullptr)
                delete[] this->nume;

            this->nume=new char[strlen(a)+1];
            strcpy(this->nume,a);

    }

    void setNote(int* a, int b)
   {
       if(this->note!=nullptr)
        delete[] this->note;

       this->nrNote=b;
       this->note=new int[b];

       for(int i=0; i<b;i++)
        this->note[i]=a[i];
   }

    float medieStudent(){

        float medie_note;
        for(int i=0; i<this->nrNote;i++)
            medie_note=medie_note+this->note[i];
        medie_note=medie_note/this->nrNote;
        return medie_note;


    }



    Student(const Student& stud):ID_Matricol(stud.ID_Matricol){

        this->varsta=stud.varsta;
        this->nrNote=stud.nrNote;

        this->nume=new char[strlen(stud.nume)+1];
        strcpy(this->nume, stud.nume);

        this->note=new int[stud.nrNote];
        for(int i=0; i<stud.nrNote;i++)
            this->note[i]=stud.note[i];



    }

    Student& operator =(const Student& stud){

        if(this!=&stud){

                this->varsta=stud.varsta;
                this->nrNote=stud.nrNote;

                if(this->nume!=NULL)
                    delete[] this->nume;

                this->nume=new char[strlen(stud.nume)+1];
                strcpy(this->nume, stud.nume);

                if(this->note!=NULL)
                   delete[] this->note;

                this->note=new int[stud.nrNote];
                for(int i=0; i<stud.nrNote;i++)
                    this->note[i]=stud.note[i];

        }
        return *this;





    }


    friend ostream& operator<< (ostream& out,  const Student stud){



            out<<"\nStudent "<<stud.nume<<" are "<<stud.nrNote<<"  note, "<<" notele: ";
            for(int i=0; i<stud.nrNote; i++)
            out<<stud.note[i]<<" ";
            out<<" are "<<stud.varsta<<" ani\n";



        return out;

    }




   friend istream& operator>> (istream& in,  Student& stud){

        char aux[100];

        cout<<"\n Introduceti numele";
        in>>aux;

        if(stud.nume!=NULL)
            delete[] stud.nume;

        stud.nume=new char[strlen(aux)+1];
        strcpy(stud.nume,aux);

        cout<<"Intoduceti varsta ";
        in>>stud.varsta;

        cout<<"\nIntroduceti numarul de note ";
        in>>stud.nrNote;

        if(stud.note!=NULL)
            delete[] stud.note;

        stud.note=new int[stud.nrNote];
        cout<<"\nIntroduceti notele: ";
        for(int i=0; i<stud.nrNote; i++)
            in>>stud.note[i];

        return in;

    }

    //op ++ pre-incremenatre
    const Student operator++(){
        this->varsta++;

        return *this;

    }

    //op ++ post-incrementare
    const Student operator++(int){

        Student aux(*this);

        this->varsta++;

        return aux;


    }






    ~Student(){

        if(this->note!=nullptr)
            delete[] this->note;
        if(this->nume!=nullptr)
            delete[] this->nume;


    }
// operator + (ob+int)

    Student operator +(int a)
    {
        int note2[100];
        if(this->note!=NULL)
        { for(int i=0; i<this->nrNote; i++)
            note2[i]=this->note[i];
          delete[] this->note;
        }

        this->nrNote++;
        this->note=new int[this->nrNote];
        for(int i=0; i<this->nrNote-1;i++)
            this->note[i]=note2[i];

        this->note[this->nrNote-1]=a;

        return *this;


    }

    //operator + (ob+ob)
    Student& operator +(Student stud)
    {

        Student *p=new Student(*this);

        char aux[100]={NULL};
        strcat(aux,this->nume);
        strcat(aux,stud.nume);

        delete[] p->nume;

        p->nume=new char[strlen(aux)+1];
        strcpy(p->nume,aux);

        return *p;

    }



};

int Student::anCurent=2;

int main()
{



   char nume1[]={"Andrei"};
   int note[]={10,9,9,8};

   Student s1(100,20,nume1,4,note);

  /* //constructor copiere
   Student  s3=s1, s2(s1);
   s3.afisare();

   //op =

   Student s4,s6;
   s4=s1;
   s4.afisare();

   // apelcare functie citire
   s6.citire();
   s6.afisare();

   // apelcare operator >> si <<
   Student s7;

   cin>>s7;
   cout<<s7;*/
// ++ pre incrementare
   cout<<s1.getVarsta();
   cout<<++s1;

 //++ post incrementare
 cout<<s1++;
 cout<<s1.getVarsta();

// operator + (ob+int)
  s1+9;
  int *a;
  s1=s1+10+9+100; // adauge 10 in lista de note
 cout<<s1;

//operator + (ob+ob)
    Student s2=s1,s3,s4=s1;
    s3=s1+s2+s4;
    cout<<s3;
    cout<<endl;
    cout<<s1.getNume();
    return 0;
}





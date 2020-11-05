#include <iostream>
#include <cstring>

using namespace std;

class Client {
         const int ID_Persoana;
         int ziuaAbonarii = 0;
         int nrMarimi;
         int* marimi;
         bool abonament;
         char* numeleClientului;
         char* zileDisponibile;
         int varsta = 0;
         float* greutate = 0;
         double numarCaloriiMentinere = 0;
         int pretAbonament = 80;
   public :
    char lunaCurenta;
    static void mesaj (){

    cout<<"Bine ati venit la Danabolic gym!";

    }

    Client():ID_Persoana(00000){
    varsta =0;
    abonament = false;
    numeleClientului = "Anonim";
    zileDisponibile = new char [strlen("Niciuna")+1];
    strcpy(this->numeleClientului, "Niciuna");
    numarCaloriiMentinere = 0;
    greutate = 0;
    }



    Client(int id, int ziuaAbonarii, bool abonament,int nrMarimi, int* marimi, char* numeleClientului, int varsta, float* greutate, double numarCaloriiMentinere ):ID_Persoana(id){

        this->varsta = varsta;
        this->numeleClientului = new char [strlen(numeleClientului)+1];
        strcpy(this->numeleClientului, numeleClientului);

        this->nrMarimi=nrMarimi;

        this->marimi=new int[nrMarimi];

        for (int i = 0; i<nrMarimi; i++){
            this->marimi[i] = marimi[i];
        }




    }






};

class Sala{




};




class ProgramAntrenament {




};


class Suplimente {







};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

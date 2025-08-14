#include "modulara.h"

void Introducerea_date(Carti *C,unsigned int nr_carti,fstream & pCarte){

 for(int i=0;i<nr_carti;i++){
        pCarte>>C[i].titlu;
        pCarte>>C[i].autorul;
        pCarte>>C[i].anul_editiei;
        pCarte>>C[i].limba;
        pCarte>>C[i].tematica;
        pCarte>>C[i].pret;
        pCarte>>C[i].numar_exemplare;
        pCarte>>C[i].id_furnizor;
    }
}
void Afiseaza_Carti(Carti* C,unsigned int nr_carti){
    cout<<setw(30)<<left<<"Titlu"<<setw(30)<<left<<"Autorul"<<setw(30)<<"Anul_editiei"<<setw(10)<<"Limba"<<setw(20)<<
    "Tematica"<<setw(15)<<"Pret"<<setw(20)<<"Numar_Exemplare"<<setw(10)<<"ID_furnizor\n";
    for(int i=0;i<nr_carti;i++){
        cout<<setw(30)<<left<<C[i].titlu<<setw(30)<<left;
        cout<<C[i].autorul<<setw(30);
        cout<<C[i].anul_editiei<<setw(10);
        cout<<C[i].limba<<setw(20);
        cout<<C[i].tematica<<setw(15);
        cout<<C[i].pret<<setw(20);
        cout<<C[i].numar_exemplare<<setw(15);
        cout<<C[i].id_furnizor<<endl;
    }
    cout<<endl;
}
void Introducere_date(Furnizor *F, unsigned int nr_furnizori,fstream & pFurnizor){
for(int i=0;i<nr_furnizori;i++){
        pFurnizor>>F[i].id_furnizor;
        pFurnizor>>F[i].denumirea;
        pFurnizor>>F[i].adresa;
        pFurnizor>>F[i].telefonul;

    }
}
void Afiseaza_Furnizor (Furnizor* F, unsigned int nr_furnizori){
        cout<<setw(30)<<left<<"Denumirea"<<setw(30)<<left<<"Id_furnizor"<<setw(30)<<"Adresa"<<setw(7)<<"Telefon\n";
        for(int i=0;i<nr_furnizori;i++){
        cout<<setw(30)<<left<<F[i].denumirea<<setw(30);
        cout<<F[i].id_furnizor<<setw(30);
        cout<<F[i].adresa<<setw(7);
        cout<<F[i].telefonul<<endl;
        }
  }

void Inregistrare_Carte(Carti *C,unsigned int &nr_Carti,fstream & pCarte){
        ofstream out("Books.txt");
        cout<<endl;
        nr_Carti++;
    cout<<"Introduceti datele unei carti noi\n";
    string titlu,autorul,limba,tematica;
    unsigned int anul_editiei,numar_exemplare,id_furnizor;
    float pret;
    cout<<"Titlul:";
    cin>>C[nr_Carti-1].titlu;
      cout<<"Autorul:";
    cin>>C[nr_Carti-1].autorul;
      cout<<"Anul editiei:";
    cin>>C[nr_Carti-1].anul_editiei;
      cout<<"Limba:";
    cin>>C[nr_Carti-1].limba;
      cout<<"Tematica:";
    cin>>C[nr_Carti-1].tematica;
     cout<<"Pret:";
    cin>>C[nr_Carti-1].pret;
     cout<<"Numarul de exemplare:";
    cin>>C[nr_Carti-1].numar_exemplare;
     cout<<"Id furnizor:";
    cin>>C[nr_Carti-1].id_furnizor;

    out<<nr_Carti<<endl;
    for(int i=0;i<nr_Carti;i++){
    out<<C[i].titlu<<" ";
    out<<C[i].autorul<<" ";
    out<<C[i].anul_editiei<<" ";
    out<<C[i].limba<<" ";
    out<<C[i].tematica<<" ";
    out<<C[i].pret<<" ";
    out<<C[i].numar_exemplare<<" ";
    out<<C[i].id_furnizor<<endl;
    }

    Introducerea_date(C,nr_Carti,pCarte);
cout<<endl;

}
void Inregistrare_Furnizor(Furnizor *F,unsigned int &nr_Furnizori,fstream & pFurnizor){
            ofstream out("Supplier.txt");
        string denumirea, adresa;
        unsigned int id_furnizor, telefonul;
        nr_Furnizori++;
        cout<<"ID Furnizor:";
    cin>>F[nr_Furnizori-1].id_furnizor;
      cout<<"Denumirea:";
    cin>>F[nr_Furnizori-1].denumirea;
      cout<<"Adresa:";
    cin>>F[nr_Furnizori-1].adresa;
      cout<<"Telefonul:";
    cin>>F[nr_Furnizori-1].telefonul;
        out<<nr_Furnizori<<endl;
    for(int i=0;i<nr_Furnizori;i++){
    out<<F[i].id_furnizor<<" ";
    out<<F[i].denumirea<<" ";
    out<<F[i].adresa<<" ";
    out<<F[i].telefonul<<" ";
}
Introducere_date(F,nr_Furnizori,pFurnizor);
cout<<endl;
}


void Stergerea_Carte(Carti *C,unsigned int &nr_carti,fstream & pCarte){
    ofstream out("Books.txt");
    cout<<"Introduceti titlul cartii:\n";
        string titlulCartii;
        cin>>titlulCartii;
        int pozitia;
        bool asemenea=false;
       for(int i=0;i<nr_carti;i++){
        if(titlulCartii==C[i].titlu){
            pozitia=i;
            asemenea=true;
            break;
        }
       }

       if(asemenea){
            C[pozitia]=C[pozitia+1];
            nr_carti--;
               out<<nr_carti<<endl;

    for(int i=0;i<nr_carti;i++){
    out<<C[i].titlu<<" ";
    out<<C[i].autorul<<" ";
    out<<C[i].anul_editiei<<" ";
    out<<C[i].limba<<" ";
    out<<C[i].tematica<<" ";
    out<<C[i].pret<<" ";
    out<<C[i].numar_exemplare<<" ";
    out<<C[i].id_furnizor<<endl;
    }

    Introducerea_date(C,nr_carti,pCarte);
cout<<endl;
       }else cout<<"Asa carte nu exista in lista\n\n";

}

//stergere furnizor
void Stergere_Furnizor(Furnizor *F,unsigned int &nr_furnizor,fstream & pFurnizor){
ofstream out("Supplier.txt");
    cout<<"Introduceti denumirea furnizorului:\n";
        string denumireFurnizor;
        cin>>denumireFurnizor;
        int pozitia;
        bool asemenea=false;
       for(int i=0;i<nr_furnizor;i++){
        if(denumireFurnizor==F[i].denumirea){
            pozitia=i;
            asemenea=true;
            break;
        }
       }
if(asemenea){
            F[pozitia]=F[pozitia+1];
            nr_furnizor--;
               out<<nr_furnizor<<endl;

    for(int i=0;i<nr_furnizor;i++){
    out<<F[i].id_furnizor<<" ";
    out<<F[i].denumirea<<" ";
    out<<F[i].adresa<<" ";
    out<<F[i].telefonul<<endl;
    }

    Introducere_date(F,nr_furnizor,pFurnizor);
cout<<endl;
       }else cout<<"Asa furnizor nu exista in lista\n\n";
}
//actualizare carte
void Actualizarea_Carte(Carti *C,unsigned int nr_carti,fstream & pCarte){
        ofstream out("Books.txt");
    string Titlu;
    cout<<"Introduceti titlul cartii care doriti sa schimbati\n";
    cin>>Titlu;
    int optiune,n;
    bool asemena=false;
        for(int i=0;i<nr_carti;i++){
            if(C[i].titlu==Titlu) {
                asemena=true;
                n=i;
                break;
            }
        }
        if(asemena){
    cout<<"Ce doriti sa schimbari la cartea cu titlul "<<Titlu<<endl;
    bool STOP=false;
   while(!STOP){
    cout<<"1.Titlu\n"
        <<"2.Autorul\n"
        <<"3.Anul editiei\n"
        <<"4.Tematica\n"
        <<"5.Limba\n"
        <<"6.Numar de exemplare\n"
        <<"7.Pret\n"
        <<"8.Id furnizor\n"
        <<"0.Gata\n";


        cout<<"Optiune:";
        cin>>optiune;
        switch(optiune){
            case 1: cin>>C[n].titlu;break;
            case 2: cin>>C[n].autorul;break;
            case 3:cin>>C[n].anul_editiei;break;
            case 4: cin>>C[n].tematica;break;
            case 5: cin>>C[n].limba;break;
            case 6: cin>>C[n].numar_exemplare;break;
            case 7: cin>>C[n].pret;break;
            case 8: cin>>C[n].id_furnizor;break;
            case 0: STOP=true;break;
            default: cout<<"NU ESTE ASA OPTIUNE\n";
        }
      }

      out<<nr_carti<<endl;
    for(int i=0;i<nr_carti;i++){
    out<<C[i].titlu<<" ";
    out<<C[i].autorul<<" ";
    out<<C[i].anul_editiei<<" ";
    out<<C[i].limba<<" ";
    out<<C[i].tematica<<" ";
    out<<C[i].pret<<" ";
    out<<C[i].numar_exemplare<<" ";
    out<<C[i].id_furnizor<<endl;
    }
      Introducerea_date(C,nr_carti,pCarte);
    }else {
        cout<<"Ati introdus text gresit\n";
        Actualizarea_Carte(C,nr_carti,pCarte);
    }
}
//Actualizare furnizor
//void Actualizare_Furnizor(Furnizor *F,unsigned int nr_furnizori,fstream & pFurnizor)

void carteaFurnizor(Carti *C, Furnizor *F, int nr_carti,  int nr_furnizori) {
    ofstream carteFurnizor("Delivery.txt");

    bool gasita=false;
    carteFurnizor<<"Furnizorii carora le lipsesc carti:\n";
    for (int i=0;i<nr_carti;i++) {
        bool este=false;
        for (int j=0;j<nr_furnizori;j++) {
            if(C[i].titlu==F[j].denumirea) {
                este = true;
                break;
    }
}
if (este) {
        gasita = true;
        carteFurnizor<<i+1<<'.'<<"Titlu Carte:"<<C[i].titlu<<'\n';
        carteFurnizor<< "ID Furnizor:"<<C[i].id_furnizor<<"\n\n";
    }
}

if (!gasita) {
        carteFurnizor<<"Toate cartile sunt disponibile la toti furnizorii.\n";
}

    cout << "Verificati fisierul Delivery.txt\n\n";
    carteFurnizor.close();
}


void cartiLimbaRomina(Carti *C,int nr_Carti){
   string V[100];
    int k=0;
        for(int i=0;i<nr_Carti;i++){
            if(C[i].limba=="Romina" || C[i].limba=="romina"){
                V[k]=C[i].titlu;
            k++;
            }
        }
    int gasit;
    do{
        gasit=0;
        for(int i=0;i<k-1;i++){
            if(V[i].at(0)>V[i+1].at(0)){
                swap(V[i],V[i+1]);
                gasit=1;
            }
        }
    }while(gasit==1);

    cout<<"Lista cartilor editate in limba romina\n";
        for(int i=0;i<k;i++){
                V[i].at(0)=toupper(V[i].at(0));
        cout<<"Titlul:"<<V[i]<<endl;
    }
    cout<<endl;
}


void pretulMediu(Carti *C, int nr_carti){
        int furn;
        cout<<"Scrieti id-ul furnizorului:";
        cin>>furn;
        int sum=0,k=0;
        bool asemenea=false;
        for(int j=0;j<nr_carti;j++){
        if(furn==C[j].id_furnizor){
            asemenea=true;
            sum+=C[j].pret;
            k++;
        }
    }
    if(asemenea){
        cout<<"Pretul mediua la furnizorul "<<furn<<" este "<<(float)sum/k<<" lei\n";

    cout<<endl;
    }else {
        cout<<"Asa id furnizor nu exista\n";
        pretulMediu(C,nr_carti);
        }
}

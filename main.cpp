#include "modulara.h"

const int MAX_CARTI=100;
const int MAX_FURNIZOR=100;
int main(){
    Carti * Carte=new Carti[MAX_CARTI];
    fstream pCarte("Books.txt");
    unsigned int nr_Carti;
    pCarte>>nr_Carti;
    Introducerea_date(Carte,nr_Carti,pCarte);

    Furnizor * Supplier=new Furnizor[MAX_FURNIZOR];
    fstream pFurnizor("Supplier.txt");
    unsigned int nr_furnizori;
    pFurnizor>>nr_furnizori;
    Introducere_date(Supplier,nr_furnizori,pFurnizor);

 bool STOP=false;
    while(!STOP){
cout<<"Ce sarcina doriti sa afisez?\n";
cout<<"1.Afiseaza la ecran informatia din fisierul Books.txt\n";
cout<<"2.Afiseaza la ecran informatia din fisierul Supplier.txt\n";
cout<<"3.Inregistrarea unei carti noi\n";
cout<<"4.Inregistrarea unui Furnizor nou\n";
cout<<"5.Exclude informatia despre o carte, denumirea careia a fost introdussa de la tastatura.\n";
cout<<"6.Exclude informatia despre un furnizor, identificatorul caruia se citeste de la tastatura.\n";
cout<<"7.Actualizeaza datele unei carti, denumirea careia se citeste de la tastatura.\n";
cout<<"8.Actualizeaza datele unui furnizor, identificatorul caruia se citeste de la tastatura.\n";
cout<<"9.Creaza fisierul textual Delivery.txt, ce va contine informatia despre furnizorii, cartile carora lipsesc in librarie.\n";
cout<<"10.Afiseaza la ecran lista cartilor in oridnea alfabetica a denumirilor, editate in limba romana.\n";
cout<<"11.Afiseaza la ecran informatia despre cartile cu numar maxim de exemplare.\n";
cout<<"12.Afiseaza la ecran pretul mediu a cartilor livrate de acelasi furnizor, identificatorul caruia este citit de la tastatura.\n";
cout<<"0-Stopeaza programul.\n";

    int optiune;
    cin>>optiune;

    switch(optiune){
    case 1:

        Afiseaza_Carti(Carte,nr_Carti);
        break;

    case 2:
        Afiseaza_Furnizor(Supplier,nr_furnizori);
        break;
    case 3: Inregistrare_Carte(Carte,nr_Carti,pCarte);break;
    case 4: Inregistrare_Furnizor(Supplier,nr_furnizori,pFurnizor);break;
    case 5: Stergerea_Carte(Carte,nr_Carti,pCarte);break;
    case 6: Stergere_Furnizor(Supplier,nr_furnizori,pFurnizor);break;
    case 7: Actualizarea_Carte(Carte,nr_Carti,pCarte);break;
//    case 8: Actualizare_Furnizor(Supplier,nr_furnizori,pFurnizor);break;
    case 9: carteaFurnizor(Carte, Supplier, nr_Carti,nr_furnizori);break;
    case 10: cartiLimbaRomina(Carte,nr_Carti);break;
    case 12: pretulMediu(Carte, nr_Carti);break;
    case 0:
            cout<<"Programul e stopat";
         STOP=true;
         break;
    default: cout << "Optiune invalida.\n";

    }
    }

delete[] Carte;
delete[] Supplier;

    return 0;
}

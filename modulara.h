#ifndef MODULARA_H
#define MODULARA_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


struct Carti{
    string titlu;
    string autorul;
    unsigned int anul_editiei;
    string limba;
    string tematica;
    float pret;
    unsigned int numar_exemplare;
    unsigned int id_furnizor;
};

struct Furnizor{
    unsigned int id_furnizor;
    string denumirea;
    string adresa;
    unsigned int telefonul;
};
//Pentru carti
void Introducerea_date(Carti *C,unsigned int nr_carti,fstream & pCarte);
void Afiseaza_Carti(Carti* C,unsigned int nr_carti);
//Pentru Furnizor
void Introducere_date(Furnizor *F, unsigned int nr_furnizori,fstream & pFurnizor);
void Afiseaza_Furnizor (Furnizor* F, unsigned int nr_furnizori);
// Inregistrarea unei carti
void Inregistrare_Carte(Carti *C,unsigned int &nr_carti,fstream & pCarte);
//Inregistrare furnizor
void Inregistrare_Furnizor (Furnizor *F, unsigned int &nr_Furnizor,fstream & pFurnizor);
//Stergerea Carte
void Stergerea_Carte(Carti *C,unsigned int &nr_carti,fstream & pCarte);
//stergere furnizor
void Stergere_Furnizor(Furnizor *F, unsigned int &nr_furnizor,fstream & pFurnizor);
//Actualizare Carte
void Actualizarea_Carte(Carti*C,unsigned int nr_carti,fstream & pCarte);
//Actualizare furnizor
void Actualizare_Furnizor(Furnizor *F,unsigned int nr_furnizori,fstream & pFurnizor);
//Delivery
void carteaFurnizor(Carti *C, Furnizor *F, int nr_carti,  int nr_furnizori);

void cartiLimbaRomina(Carti *C,int nr_Carti);

void pretulMediu(Carti *C, int nr_carti);
#endif // MODULARA_H

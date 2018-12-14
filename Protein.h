///Title: Protein Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef PROTEIN_H
#define PROTEIN_H

#include <iostream>
#include "Sequence.h"
#include "CodonsTable.h"
#include "DNA.h"

using namespace std;

class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p,Protein_Type atype);
 	 	~Protein();
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(DNA & bigDNA);
        void setsizee(int sz);
        void Print();
        char* operator+(Protein & p1);
        bool operator== (Protein &p1);
        bool operator!= (Protein &p1);
        friend istream& operator>> (istream& in,Protein &p1);
        friend ostream& operator<< (ostream& out, const Protein &p1);
        Protein& operator =(const Protein& rhs);
};

#endif // PROTEIN_H

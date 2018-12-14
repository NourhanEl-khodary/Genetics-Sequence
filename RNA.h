///Title: RNA Sequence Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef RNA_H
#define RNA_H

#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
using namespace std;


class Protein;
class CodonsTable;
class DNA;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
        DNA * DNA_strand;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein& ConvertToProtein(CodonsTable & table);

 	 	// function to convert the RNA sequence back to DNA
        DNA& ConvertToDNA();
        char* operator+(RNA & r1);
        bool operator== (RNA &r1);
        bool operator!= (RNA &r1);
        friend istream& operator>> (istream& in,RNA &r1);
        friend ostream& operator<< (ostream& out, const RNA &r1);
        RNA& operator =(const RNA& rhs);
};


#endif // RNA_H

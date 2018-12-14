/// Title: Genatics Sequence System Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;



class System
{
private:
    int choice;
    int choice1;
    int choice2;

public:
        System();
        ~System();
        void setChoice(int c);
        void setChoice1(int c);
        //void setChoice2(int c);
        void Choose();
        DNA_Type StrandType();
        RNA_Type rStrandType();
        Protein_Type pStrandType();
        int sizeofSeq();
        char* Strand(int num,int sz);
        void _DNA();
        void _RNA();
        void _Protein();
        void LoadSequenceFromFile();
        void SaveSequenceToFile(int sz,DNA_Type atype,char* Strand);
        void SaveSequenceToFile(int sz,RNA_Type atype,char* Strand);
        void SaveSequenceToFile(int sz,Protein_Type atype,char* Strand);


};

#endif // SYSTEM_H

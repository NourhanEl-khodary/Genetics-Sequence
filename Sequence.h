///Title: Sequence Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Sequence
{
protected:
    char * seq;
    int sizee;
public:

    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    Sequence(char * x, int length);
    char * getSeq();
    int getSizee();
    void setseq(char* x);
    //virtual void Print()= 0;
    friend char* Align(Sequence * s1, Sequence * s2);
    void LoadSequenceFromFile(char* FileName);
    ///void SaveSequenceToFile(string FileName);
    virtual ~Sequence();
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    //virtual void Print()= 0;
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
    //friend char* Align(Sequence * s1, Sequence * s2);
};

#endif // SEQUENCE_H

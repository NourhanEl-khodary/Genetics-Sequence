/// Title: DNA Sequence Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef DNA_H
#define DNA_H

#include <iostream>
#include "Sequence.h"
#include "RNA.h"


class RNA;

enum DNA_Type {promoter, motif, tail, noncoding};

class DNA : public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
    RNA * RNA_strand;
public:
    // constructors and destructor
    DNA();

    DNA(char * seq, DNA_Type atype);
    DNA(DNA& rhs);
    ~DNA();
    void setStart(int start);
    void setend(int endd);
    void setsizee(int sz);
    // function printing DNA sequence information to user
    void Print();
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA& ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();
    char* operator+(DNA & d1);
    bool operator== (DNA &d1);
    bool operator!= (DNA &d1);
    friend istream& operator>> (istream& in,DNA &d1);
    friend ostream& operator<< (ostream& out, const DNA &d1);
    DNA& operator =(const DNA& rhs);
};

#endif // DNA_H

///Title: Protein Sequence CPP file
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include "Protein.h"
#include "Sequence.h"
#include "DNA.h"
#include <iostream>

using namespace std;

Protein::Protein()
{
}

Protein::Protein(char * p,Protein_Type atype)
{   this->seq=new char[strlen(p)+1];
    this->seq[strlen(p)]='\0';
    strcpy( this->seq, p );
    this->sizee = strlen( p )+1;
    type=atype;
}

Protein::~Protein()
{
}
void Protein:: setsizee(int sz){
this->sizee=sz;

}

void Protein::Print()
{   cout<<"the size of the seq = "<<sizee<<endl;
    cout<<endl;
    cout<<"the RNA type is: "<<this->type;
    cout<<endl;
    cout<<"the protien strand IS... "<<endl;
    cout<<this->seq;

}


char* Protein:: operator+(Protein & p1)
{
    int sz=p1.getSizee()+this->getSizee();

    char* conc=new char[sz+1];
    conc[sz]='\0';
    for (int i=0; i<p1.getSizee(); i++)
    {

        conc[i]=this->seq[i];


    }
    int x=this->getSizee()-1;
    for (int i=0; i<p1.getSizee(); i++)
    {

        conc[x]=p1.seq[i];

        x++;

    }
//conc[sz]='\0';
    return conc;

}


 bool Protein:: operator== (Protein &p1)
 {
     if (this->getSizee()==p1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=p1.seq[i])
            {
                return false ;

            }
        }
        return true ;
    }
    return false;
 }

bool Protein::operator!= (Protein &p1)
{
    if (this->getSizee()==p1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=p1.seq[i])
            {
                return true;

            }
        }
        return false ;
    }
    return true;
}

istream& operator>> (istream& in,Protein &p1)
{
    int s;
    in>>s;
    p1.sizee=s;
    int choice;
    cout<<"enter the number of the type";
    in>>choice;
    p1.type=static_cast<Protein_Type>(choice);
    char*strand=new char[s+1];
    strand [s]='\0';
    for(int i=0; i<p1.sizee; i++)
    {
        in>>strand[i];
    }
    strcpy(p1.seq,strand);



    return in;
}


ostream& operator<< (ostream& out, const Protein &p1)
{

    cout<<"the size of the seq = ";
    out<<p1.sizee<<endl;
    cout<<endl;
    cout<<"the RNA type is: ";
    out<<p1.type;
    cout<<endl;
    cout<<"the strand of RNA... "<<endl;
    out<<p1.seq;
    cout << endl;


    return out;

}
Protein& Protein :: operator=(const Protein &rhs){

    sizee=rhs.sizee;
    type=rhs.type;
    seq=new char [sizee+1];
    seq[sizee]='\0';
    strcpy(seq,rhs.seq);
    return *this;

}

DNA* Protein:: GetDNAStrandsEncodingMe(DNA & bigDNA)
{
    DNA* PDstrand;
    char* filename = new char;
    PDstrand= new DNA ;
    CodonsTable c ;
    int z=0, x=0, c1 = 0 , SZ=0 ;

    char* seq1 = new char [bigDNA.getSizee()+1] ;
    char* seq2 = new char [bigDNA.getSizee()+1] ;

    char found[4] ;

    found[4] = '\0' ;
    seq1[bigDNA.getSizee()] = '\0' ;
    seq2[bigDNA.getSizee()] = '\0' ;

    strcpy(seq1, bigDNA.getSeq()) ;

    cout << " Enter file name " ;
    cin >> filename ;
    c.LoadCodonsFromFile(filename) ;

    for (int i = 0 ; i < bigDNA.getSizee() ; i++)
    {
        if (seq1[i]=='T')
        {
            seq1[i] = 'U' ;
        }
    }

    for ( int i = 0 ; i < bigDNA.getSizee() ; i++)
    {
        found[0] = seq1[i] ;
        found[1] = seq1[i+1] ;
        found[2] = seq1[i+2] ;

        if ( seq[c1] == ( c.getAminoAcid(found).Amino_Acid ))
        {
            for (int j=0 ; j < 3 ; j++)
            {
                seq2[z]=found[j];
                z++ ;
                x++ ;
                SZ++ ;
            }
            c1++;
            i+=2;
            x=0;
            if(c1==sizee)
            {
                c1=0;
            }
        }
        else
        {
            c1=0;
            z-=x;
            x=0 ;
        }
    }
    for (int i = 0 ; i < SZ ; i++)
    {
        if (seq2[i]=='U')
        {
            seq2[i] = 'T' ;
        }
    }
    PDstrand->setsizee(SZ) ;
    PDstrand->setseq(seq2);
    return PDstrand ;
}

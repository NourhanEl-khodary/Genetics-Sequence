///Title: DNA Sequence CPP file
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include "DNA.h"
#include "Sequence.h"
#include <iostream>
#include "RNA.h"

using namespace std;

///class RNA;

DNA::DNA()
{

}

DNA::DNA( char * seq , DNA_Type atype )
{

    this->seq=new char[strlen(seq)+1];
    this->seq[strlen(seq)]='\0';
    strcpy( this->seq, seq );

    type=atype;
    this->sizee = strlen( seq )+1;

}

DNA::DNA(DNA& rhs)
{
    sizee=rhs.sizee;
    endIndex=rhs.endIndex;
    startIndex=rhs.startIndex;
    type=rhs.type;
    seq=new char [sizee+1];
    seq[sizee]='\0';
    strcpy(seq,rhs.seq);
    ///complementary_strand=new DNA;
    ///complementary_strand->seq=new char[sizee];
    ///strcpy(complementary_strand->seq,rhs.complementary_strand->seq);

}

DNA::~DNA()
{

}

void DNA:: setStart(int start)
{
    startIndex=start;
}

void DNA:: setsizee(int sz){
this->sizee=sz;

}
void DNA::setend(int endd)
{
    endIndex=endd;
}

// function printing DNA sequence information to user
void DNA::Print()
{
    cout<<"the size of the seq = "<<sizee;
    cout<<endl;
    cout<<"the DNA type is: "<<this->type;
    cout<<endl;
    cout<<"the first strand of DNA... "<<endl;
    cout<<this->seq;
    cout << endl;
   cout<< "the second strand of DNA..."<<endl ;
    cout << complementary_strand->seq;
    //cout << endl;
    //cout<< "the RNA strand of DNA..."<<endl ;
    //cout << RNA_strand->getSeq();
    //cout << endl<<endl<<endl;
}

RNA& DNA::ConvertToRNA()
{
    //cout << "1\n";
    char *temp=new char[this->getSizee()+1];
    //cout << "2\n";
    temp[this->getSizee()]='\0';

    RNA_strand=new RNA;
//    RNA_strand->getSeq()=new char[this->getSizee()];
    strcpy(temp, this->seq );
    int sz = strlen(temp);
    this->sizee = sz;

    for (int i = 0; i < sz; i++)
    {
        if (this->seq[i] == 'T' )
        {
            temp[i] = 'U';

        }
        else
        {
            temp[i] = this->seq[i];

        }
    }
    strcpy(RNA_strand->getSeq(),temp);
    //this->RNA_strand = RNA_strand;
    return *RNA_strand;
}

// function to build the second strand/pair of DNA sequence
// To build a complementary_strand (starting from the startIndex to
// the endIndex), convert each A to T, each T to A, each C to G, and
// each G to C. Then reverse the resulting sequence.
void DNA::BuildComplementaryStrand()
{
    complementary_strand=new DNA;
    complementary_strand->seq=new char[this->getSizee()];
    strcpy(complementary_strand->seq, this->seq );
    int sz = strlen(complementary_strand->seq );
    this->sizee = sz;

    for (int i = 0; i < sz; i++)
    {
        if (this->seq[i] == 'A' )
        {
            complementary_strand->seq[i] = 'T';

        }
        else if(this->seq[i] == 'T' )
        {
            complementary_strand->seq[i] = 'A';

        }
        else if(this->seq[i] == 'C')
        {
            complementary_strand->seq[i] = 'G';

        }
        else if(this->seq[i] == 'G')
        {
            complementary_strand->seq[i] = 'C';

        }
        else
        {
            cout<<"error";

        }
    }


}

char* DNA:: operator+(DNA& d1)
{

    int sz=d1.getSizee()+this->getSizee();
    char* conc=new char[sz+1];
    conc[sz]='\0';
    conc=strcat(this->getSeq(),d1.getSeq());
    /*for (int i=0; i<sz; i++)
    {
        conc[i]=this->seq[i];
        cout<< "FLAG1: "<<conc[i]<<endl;
    }
    int x=this->getSizee();
    for (int i=0; i<d1.getSizee(); i++)
    {
        conc[x]=d1.seq[i];
        x++;
        cout<<"FLAG1: "<<conc[x]<<endl;

    }*/

    return conc;
}

bool DNA:: operator== (DNA &d1)
{

    if (this->getSizee()==d1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=d1.seq[i])
            {
                return false ;

            }
        }
        return true ;
    }
    return false;
}

bool DNA:: operator!= (DNA &d1)
{
    if (this->getSizee()==d1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=d1.seq[i])
            {
                return true;

            }
        }
        return false ;
    }
    return true;
}

istream& operator>> (istream& in,DNA &d1)
{
    int s;
    cout<<"please enter the size: ";
    in>>s;
    d1.sizee=s;
    int choice;
    cout<<"enter the number of the type";
    in>>choice;
    d1.type=static_cast<DNA_Type>(choice);
    char*strand=new char[s+1];
    strand [s]='\0';
    for(int i=0; i<d1.sizee; i++)
    {
        in>>strand[i];
    }
    cout<<"end";
    strcpy(d1.seq,strand);

    return in;
}

ostream& operator<< (ostream& out,  const DNA &d1)
{
    cout<<"the size of the seq = ";
    out<<d1.sizee<<endl;
    cout<<endl;
    cout<<"the DNA type is: ";
    out<<d1.type;
    cout<<endl;
    cout<<"the first strand of DNA... "<<endl;
    out<<d1.seq;
    cout << endl;

    return out;
}

DNA& DNA :: operator=(const DNA &rhs){

    sizee=rhs.sizee;
    endIndex=rhs.endIndex;
    startIndex=rhs.startIndex;
    type=rhs.type;
    seq=new char [sizee+1];
    seq[sizee]='\0';
    strcpy(seq,rhs.seq);
    return *this;

}

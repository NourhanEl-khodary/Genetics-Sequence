///Title: RNA Sequence CPP file
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include "RNA.h"
#include <iostream>
#include "Sequence.h"
#include "DNA.h"

using namespace std;

///class Protein;
///class CodonsTable
class DNA;

RNA::RNA()
{

}

RNA::RNA(char * seq, RNA_Type atype)
{   sizee=strlen(seq);
    this->seq=new char[strlen(seq)+1];
    this->seq[strlen(seq)]='\0';
    strcpy( this->seq, seq );
    type=atype;

}

RNA::RNA(RNA& rhs)
{
    sizee=rhs.sizee;
    type=rhs.type;
    seq=new char [sizee+1];
    strcpy(seq,rhs.seq);
}

RNA::~RNA()
{
delete []seq;
}
Protein& RNA :: ConvertToProtein(CodonsTable& table)
{
    Codon c2 ;
    Protein* p = new Protein ;
    //string filename ;
    int c = -1  , k=0 , index =0 , counter = 0 ;
    char* codonn = new char [sizee/3] ;
    codonn[sizee/3] = '\0' ;
    char stringg[4] ;

    //cout << "Enter File Name " ;
    //cin >> filename ;
    table.LoadCodonsFromFile("RNA_codon_table.txt") ;

    for (int i =0 ; i < sizee ; i++)
    {
        stringg[k] = seq[i] ;
        c++ ;
        k++ ;
        if (c == 2)
        {
            c2 = table.getAminoAcid(stringg) ;
            table.getAminoAcid(stringg).Amino_Acid ;
            if ( c2.Amino_Acid == 0 )
            {
                break ;
            }
            codonn[index] = c2.Amino_Acid;
            index++;
            c = -1 ;
            k=0;
            counter++ ;
        }
    }
    p->setsizee(counter) ;
    p->setseq(codonn) ;
    delete codonn ;
    return *p ;
}
void RNA::Print()
{
    cout<<"the size of the seq = "<<sizee<<endl;
    cout<<endl;
    cout<<"the RNA type is: "<<this->type;
    cout<<endl;
    cout<<"the RNA strand IS... "<<endl;
    cout<<this->seq;
    cout << endl;
    cout<< "the strand of DNA..."<<endl ;
    cout<<DNA_strand->getSeq();
    //cout << complementary_strand->seq;
    //cout << endl<<endl<<endl;
}

// function to convert the RNA sequence into protein sequence
// using the codonsTable object
//Protein ConvertToProtein(const CodonsTable & table);
// function to convert the RNA sequence back to DNA
DNA& RNA::ConvertToDNA()
{
    char * temp =new char [this->getSizee()+1];
    temp[this->getSizee()]='\0';
    DNA_strand=new DNA;
    strcpy(temp, this->seq );
    int sz = strlen(temp );
    this->sizee = sz;

    for (int i = 0; i < sz; i++)
    {
        if (this->seq[i] == 'U' )
        {
            temp[i] = 'T';

        }

        else
        {
            temp[i] = this->seq[i];

        }
    }
    DNA_strand->setseq(temp);
    return *DNA_strand;
}


char* RNA:: operator+(RNA& r1)
{

    int sz=r1.getSizee()+this->getSizee();
    char* conc=new char[sz+1];
    conc[sz]='\0';
    conc=strcat(this->getSeq(),r1.getSeq());
    /*for (int i=0; i<sz; i++)
    {
        conc[i]=this->seq[i];

    }
    int x=this->getSizee();
    for (int i=0; i<r1.getSizee(); i++)
    {
        conc[x]=r1.seq[i];
        x++;

    }
//conc[sz]='\0';*/
    return conc;
}


bool RNA:: operator== (RNA &r1)
{

    if (this->getSizee()==r1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=r1.seq[i])
            {
                return false ;

            }
        }
        return true ;
    }
    return false;
}

bool RNA:: operator!= (RNA &r1)
{
    if (this->getSizee()==r1.getSizee())
    {

        for (int i=0; i<(this->getSizee()); i++)
        {
            if (this->seq[i]!=r1.seq[i])
            {
                return true;

            }
        }
        return false ;
    }
    return true;
}


istream& operator>> (istream& in,RNA &r1)
{
    int s;
    in>>s;
    r1.sizee=s;
    int choice;
    cout<<"enter the number of the type";
    in>>choice;
    r1.type=static_cast<RNA_Type>(choice);
    char*strand=new char[s+1];
    strand [s]='\0';
    for(int i=0; i<r1.sizee; i++)
    {
        in>>strand[i];
    }
    cout<<"end";
    strcpy(r1.seq,strand);



    return in;
}

ostream& operator<< (ostream& out,  const RNA &r1)
{
    cout<<"the size of the seq = ";
    out<<r1.sizee<<endl;
    cout<<endl;
    cout<<"the RNA type is: ";
    out<<r1.type;
    cout<<endl;
    cout<<"the strand of RNA... "<<endl;
    out<<r1.seq;
    cout << endl;


    return out;


}

RNA& RNA :: operator=(const RNA &rhs){
    sizee=rhs.sizee;
    type=rhs.type;
    seq=new char [sizee+1];
    seq[sizee]='\0';
    strcpy(seq,rhs.seq);

}

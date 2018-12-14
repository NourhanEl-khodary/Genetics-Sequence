/// Title: Genatics Sequence Main
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author2: Nada Mohamed (20170316)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include "Protein.h"
#include "System.h"
#include <fstream>

using namespace std;

int main()
{
    ///Try Align
    /*int size_s1;
    int size_s2;
    cout<<"enter size of s1: ";
    cin>>size_s1;
    cout<<endl;
    cout<<"enter size of s2: ";
    cin>>size_s2;
    cout<<endl;


    char * c=new char[size_s1];

    for(int i=0;i<size_s1;i++){
        cin>>c[i];
    }
    c[size_s1]='\0';

    char * d=new char[size_s2];
    for(int i=0;i<size_s2;i++){
        cin>>d[i];
    }
    d[size_s2]='\0';

    Sequence * d1= new DNA (c,promoter);
    Sequence * d2= new DNA(d,motif);
    cout<<Align(d1,d2);*/

    ///DNA without Exception Handling
    /*DNA d1("ACGT",motif);
    DNA d2("ACGC",motif);
    d1.BuildComplementaryStrand();
    d1.Print();
    d2.BuildComplementaryStrand();
    d2.Print();*/

    ///DNA with exception handling
    /*int x;
    cout<<"please enetr size of your seq: ";
    cin>>x;

    //try 1 for length;
    try{
        if (x <= 0 || x > 1e8){
            throw 1;
        }
    }
    catch(int y){
        cout<<"ERROR THE LENGTH IS EITHER NEGTIVE OR TOO BIG: "<<y;
        cin>>x;
    }
    //try 2 fpr char array

    char* c1=new char[x+1];
    c1[x]='\0';


    for (int i=0;i<x;i++){
        try{
            cin >>c1[i];
            if(c1[i]!='A'&&c1[i]!='C'&&c1[i]!='G'&&c1[i]!='T'){
                throw 2;
            }

        }
        catch(int y){ cout<<"ERROR THE STRND OF DNA CONTAIN SOME WRONG CHARCTERS: "<<y;
            cin>>c1[i];
    }

    }

    DNA d1(c1,motif);
    d1.BuildComplementaryStrand();
    d1.Print();
    cout<<d1.ConvertToRNA();
    cout<<endl<<endl<<endl<<endl<<endl;*/

    ///DNA Operators
    //DNA d1("ACGT",motif);
     //DNA d2 ("ATGG",promoter);

     //cout<<(d1==d2);
     //cout<<(d1!=d2);
     //cout<<(d1+d2);
    /* DNA  d3;
     d3=d1;
     cout<<d3;*/
     //cin>>d1;
     //cout<<d1;



    ///RNA without exceptional handling
     /*RNA r1("AAA",mRNA);
     CodonsTable c;
     RNA r2("UACC",mRNA);
     cout<<r1.ConvertToDNA();
     cout << r1.ConvertToProtein(c) << endl;
     //r1.Print();*/




    ///RNA with exception handling
    /*int x;
    cout<<"please enetr size of your seq: ";
    cin>>x;

    //try 1 for length;

    try{
        if (x <= 0 || x > 1e8){
            throw 1;
        }
    }
    catch(int y){
        cout<<"ERROR THE LENGTH IS EITHER NEGTIVE OR TOO BIG: "<<y;
        cin>>x;
    }
    //try 2 fpr char array

    char* c1=new char[x+1];
    c1[x]='\0';


    for (int i=0;i<x;i++){
        try{
            cin >>c1[i];
            if(c1[i]!='A'&&c1[i]!='C'&&c1[i]!='G'&&c1[i]!='U'){
                throw 2;
            }

        }
        catch(int y){ cout<<"ERROR THE STRND OF RNA CONTAIN SOME WRONG CHARCTERS: "<<y;
            cin>>c1[i];
    }

    }

    RNA R1(c1,mRNA);
    R1.ConvertToDNA();
    R1.Print();

    cout<<endl<<endl<<endl<<endl<<endl;*/



    ///RNA operators
    /*RNA r1("UACG",mRNA);
    RNA r2("UACC",mRNA);
    RNA  R3;
    R3=r1;
    cout<<R3;
    //cout<<(r1==r2);
    //cout<<(r1!=r2);
    //cout<<(r1+r2);
    //cin>>r1;
    //cout<<r1;

    */

    ///CodonsTable
    /*CodonsTable C;
    char* arr = new char[3]{'A','A','A'};
    arr[3] = '\0';
    C.LoadCodonsFromFile("RNA_codon_table.txt");
    cout<<endl<<endl;
    C.getAminoAcid(arr);
    delete[] arr;
*/



    ///Protein Operators
      /*Protein p1("KM",Enzyme);
      Protein p2("KK",Enzyme);
      //cout<<(p2+p1);
      //cout << endl << (p1 == p1);
      //cout << endl << (p1 != p1);
      //cin >> p1;
      //cout << p1;
      Protein p3;
      p3=p1;
      cout<<p3;
*/



    /// PROTIEN without Exception Handling
    /*DNA d5("AAAGUAUCCUAA",motif);
    Protein p1("S",Enzyme);
    p1.GetDNAStrandsEncodingMe(d1);
    Protein p2("MKK",TF);
    p1.Print();
    cout<<endl<<endl;
    p2.Print();
    */


    System S;
    S.Choose();


    return 0;
}

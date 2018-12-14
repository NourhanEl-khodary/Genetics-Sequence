///Title: Genetic Sequence System Cpp file
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include "System.h"

#include <iostream>
#include <fstream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;


System::System()
{
}

System::~System()
{
}
/// Choosing which Type of Sequence to work on
void System::Choose()
{
    ///What Appears to the user to Choose from
    int c = 0;
    cout << "Welcome!" << endl << "What do you want to do?" << endl;
    cout << "1- DNA" << endl << "2- RNA" << endl << "3- Protein" << endl;
    cout << "Enter you choice: ";
    cin >> c;
    ///If the choice not available
    try{
        if ((c < 1) && (c > 3)){
            throw 0;
        }
    }
    catch(int x){
        cout << "Choose a number from 1 to 3: ";
        cin >> c;
    }

    setChoice(c);

    if (c == 1){
        _DNA(); ///Go to DNA Choices
    }
    else if(c == 2){
        _RNA(); ///Go to RNA Choices
    }
    else if(c == 3){
        _Protein(); ///Go to Protein Choices
    }
}

void System::setChoice(int c)
{
    choice = c;
}


void System::setChoice1(int c)
{
    choice1 = c;
}

///DNA Menu
void System::_DNA()
{
    ///Intializing The sequence Strand
    int c = 0;
    DNA_Type sType, nType;
    int sz,sz2;
    sz = sizeofSeq();

    char* c1 = new char[sz];
    c1 = Strand(1,sz);
    sType = StrandType();
    DNA d1(c1,sType);

    cout << "What do you want to do?" << endl;
    cout << "1- Copy the Sequence." << endl << "2- Add 2 Sequences" << endl << "3- Compare Equality" << endl;
    cout << "4- Not Equal" << endl <<"5- Convert to RNA" << endl << "6- Build Complementary Strand" << endl << "7- Align" << endl <<"8- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    ///Functions
    while (c != 8){
        if (c == 2){
        sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(1,sz2);
        nType = StrandType();
        DNA d2(c2,nType);

        cout << d1 + d2 << endl;
        SaveSequenceToFile((sz+sz2),nType,(d1+d2));
    }
    else if(c == 1){
        DNA d3;
        d3 = d1;
    }
    else if(c == 3){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(1,sz2);
        nType = StrandType();
        DNA d2(c2,nType);
        cout << (d1 == d2) << endl;
    }
    else if(c == 4){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(1,sz2);
        nType = StrandType();
        DNA d2(c2,nType);
        cout << (d1 != d2) << endl;
    }
    else if(c == 5){
        cout<<d1.ConvertToRNA() << endl;
    }
    else if(c == 6){
    d1.BuildComplementaryStrand();
    d1.Print();
    cout << endl;
    }
    else if(c == 7){
    int size_s1;
    int size_s2;
    cout<<"enter size of s1: ";
    cin>>size_s1;
    cout<<endl;
    cout<<"enter size of s2: ";
    cin>>size_s2;
    cout<<endl;


    char * c=new char[size_s1];
    cout << "Enter The first strand: ";
    for(int i=0;i<size_s1;i++){
        cin>>c[i];
    }
    c[size_s1]='\0';

    char * d=new char[size_s2];
    cout << "Enter The Second strand: ";
    for(int i=0;i<size_s2;i++){
        cin>>d[i];
    }
    d[size_s2]='\0';
    DNA_Type Type, fType;
    Type = StrandType();
    Sequence * d3= new DNA (c,Type);
    fType = StrandType();
    Sequence * d4= new DNA(d,fType);
    cout<<Align(d3,d4) << cout;
    }

    cout << "Enter what do you want to do: ";
    cin >> c;

}
}

///RNA Menu
void System::_RNA()
{
    int c = 0;
    RNA_Type sType, nType;
    int sz,sz2;
    sz = sizeofSeq();

    char* c1 = new char[sz];
    c1 = Strand(2,sz);
    sType = rStrandType();
    RNA r1(c1,sType);

    cout << "What do you want to do?" << endl;
    cout << "1- Copy the Sequence." << endl << "2- Add 2 Sequences" << endl << "3- Compare Equality" << endl;
    cout << "4- Not Equal" << endl <<"5- Convert to Protein" << endl << "6- Align" << endl <<"7- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    while (c != 7){
        if (c == 2){
        sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(2,sz2);
        nType = rStrandType();
        RNA r2(c2,nType);

        cout << r1 + r2 << endl;
    }
    else if(c == 1){
        RNA r3;
        r3 = r1;
    }
    else if(c == 3){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(2,sz2);
        nType = rStrandType();
        RNA r2(c2,nType);
        cout << (r1 == r2) << endl;
    }
    else if(c == 4){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(2,sz2);
        nType = rStrandType();
        RNA r2(c2,nType);
        cout << (r1 != r2) << endl;
    }
    else if(c == 5){
        CodonsTable C;
        r1.ConvertToProtein(C);
        r1.Print();
    }
    else if(c == 6){
    int size_s1;
    int size_s2;
    cout<<"enter size of s1: ";
    cin>>size_s1;
    cout<<endl;
    cout<<"enter size of s2: ";
    cin>>size_s2;
    cout<<endl;


    char * c=new char[size_s1];
    cout << "Enter The first strand: ";
    for(int i=0;i<size_s1;i++){
        cin>>c[i];
    }
    c[size_s1]='\0';

    char * r=new char[size_s2];
    cout << "Enter The Second strand: ";
    for(int i=0;i<size_s2;i++){
        cin>>r[i];
    }
    r[size_s2]='\0';
    RNA_Type Type, fType;
    Type = rStrandType();
    Sequence * r3= new RNA (c,Type);
    fType = rStrandType();
    Sequence * r4= new RNA(r,fType);
    cout<<Align(r3,r4) << cout;
    }

    cout << "Enter what do you want to do: ";
    cin >> c;

}
}

///Protein Menu
void System::_Protein()
{
    int c = 0;
    Protein_Type sType, nType;
    int sz,sz2;
    sz = sizeofSeq();

    char* c1 = new char[sz];
    c1 = Strand(3,sz);
    sType = pStrandType();
    Protein p1(c1,sType);

    cout << "What do you want to do?" << endl;
    cout << "1- Copy the Sequence." << endl << "2- Add 2 Sequences" << endl << "3- Compare Equality" << endl;
    cout << "4- Not Equal" << endl <<"5- Finding Combinations of DNA for the Protein Strand(EncodingMe)" << endl << "6- Align" << endl <<"8- Exit" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    while (c != 7){
        if (c == 2){
        sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(3,sz2);
        nType = pStrandType();
        Protein p2(c2,nType);

        cout << p1 + p2 << endl;
    }
    else if(c == 1){
        Protein p3;
        p3 = p1;
        p3.Print();
    }
    else if(c == 3){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(3,sz2);
        nType = pStrandType();
        Protein p2(c2,nType);
        cout << (p1 == p2) << endl;
    }
    else if(c == 4){
         sz2 = sizeofSeq();
        char* c2 = new char[sz2];
        c2 = Strand(3,sz2);
        nType = pStrandType();
        Protein p2(c2,nType);
        cout << (p1 != p2) << endl;
    }
    else if(c == 5){
        DNA d1;
        cout<<p1.GetDNAStrandsEncodingMe(d1) << endl;
    }
    else if(c == 6){
    int size_s1;
    int size_s2;
    cout<<"enter size of s1: ";
    cin>>size_s1;
    cout<<endl;
    cout<<"enter size of s2: ";
    cin>>size_s2;
    cout<<endl;


    char * c=new char[size_s1];
    cout << "Enter The first strand: ";
    for(int i=0;i<size_s1;i++){
        cin>>c[i];
    }
    c[size_s1]='\0';

    char * d=new char[size_s2];
    cout << "Enter The Second strand: ";
    for(int i=0;i<size_s2;i++){
        cin>>d[i];
    }
    d[size_s2]='\0';
    Protein_Type Type, fType;
    Type = pStrandType();
    Sequence * d3= new Protein (c,Type);
    fType = pStrandType();
    Sequence * d4= new Protein(d,fType);
    cout<<Align(d3,d4) << cout;
    }

    cout << "Enter what do you want to do: ";
    cin >> c;

}
}

///Types of DNA
DNA_Type System::StrandType()
{
    int type1;
    DNA_Type nType;
    cout << "What is the type of DNA?" << endl;
    cout << "1- promoter" << endl << "2- motif" << endl << "3- tail" << endl << "4- noncoding" << endl;
    cout << "Enter the type of strand: ";
    cin >> type1;

    try{
        if ((type1 < 1)&&(type1 > 4)){
            throw 0;
        }
    }
    catch(int s){
        cout << "Choose Number From 1 to 4: ";
        cin >> type1;
    }

    if(type1 == 1){
        nType = promoter;
    }
    else if(type1 == 2){
        nType = motif;
    }
    else if (type1 == 3){
        nType = tail;
    }
    else{
        nType = noncoding;
    }
    return nType;
}

///Types of RNA
RNA_Type System::rStrandType()
{
    int type1;
    RNA_Type nType;
    cout << "What is the type of RNA?" << endl;
    cout << "1- mRNA" << endl << "2- pre_mRNA" << endl << "3- mRNA_exon" << endl << "4- mRNA_intron" << endl;
    cout << "Enter the type of strand: ";
    cin >> type1;

    try{
        if ((type1 < 1)&&(type1 > 4)){
            throw 0;
        }
    }
    catch(int s){
        cout << "Choose Number From 1 to 4: ";
        cin >> type1;
    }

    if(type1 == 1){
        nType = mRNA;
    }
    else if(type1 == 2){
        nType = pre_mRNA;
    }
    else if (type1 == 3){
        nType = mRNA_exon;
    }
    else{
        nType = mRNA_intron;
    }
    return nType;
}

///Types of Protein
Protein_Type System::pStrandType()
{
    int type1;
    Protein_Type nType;
    cout << "What is the type of Protein?" << endl;
    cout << "1- Hormon" << endl << "2- Enzyme" << endl << "3- TF" << endl << "4- Cellular_Function" << endl;
    cout << "Enter the type of strand: ";
    cin >> type1;

    try{
        if ((type1 < 1)&&(type1 > 4)){
            throw 0;
        }
    }
    catch(int s){
        cout << "Choose Number From 1 to 4: ";
        cin >> type1;
    }

    if(type1 == 1){
        nType = Hormon;
    }
    else if(type1 == 2){
        nType = Enzyme;
    }
    else if (type1 == 3){
        nType = TF;
    }
    else{
        nType = Cellular_Function;
    }
    return nType;
}

///Exceptional Handling for the Strands
char* System::Strand(int num,int sz)
{
    char* c1=new char[sz+1];
    c1[sz]='\0';
    cout << "The Strand: ";
    if (num == 1){
        for (int i=0;i<sz;i++){
            try{
                cin >>c1[i];
                if(c1[i]!='A'&&c1[i]!='C'&&c1[i]!='G'&&c1[i]!='T'){
                    throw 2;
                }
            }
            catch(int y){ cout<<"ERROR THE STRND OF DNA CONTAIN SOME WRONG CHARCTERS: ";
                cin>>c1[i];
            }
        }
    }

    else if (num == 2){
        c1[sz]='\0';
        for (int i=0;i<sz;i++){
            try{
                cin >>c1[i];
                if(c1[i]!='A'&&c1[i]!='C'&&c1[i]!='G'&&c1[i]!='U'){
                    throw 2;
                }
            }
            catch(int y){
                cout<<"ERROR THE STRND OF RNA CONTAIN SOME WRONG CHARCTERS: ";
                cin>>c1[i];
            }
        }
    }

    else if(num == 3){
        char C[] = {'K','N','T','R','S','I','M','Q','H','P','L','E','D','A','G','V','Y','C','W','F','\0'};
        bool c = true;
        for (int i = 0;i < 20;i++){
            try{
                cin >> c1[i];
                for (int j = 0; j < 64;j++){
                    if (c1[i] != C[j]){
                        c = false;
                        break;
                    }
                }
                if(c == false){
                    throw 2;
                }
            }
            catch(int y){
                cout<<"ERROR THE STRND OF PROTEIN CONTAIN SOME WRONG CHARCTERS: ";
                cin>>c1[i];
            }
        }
    }

    return c1;
}

///Exceptional Handling For size
int System::sizeofSeq()
{
    int x;
    cout<<"Please, enter size of your seq: ";
    cin>>x;

    //try 1 for length;
    try{
        if (x <= 0 || x > 1e8){
            throw 1;
        }
    }
    catch(int y){
        cout<<"ERROR THE LENGTH IS EITHER NEGTIVE OR TOO BIG: ";
        cin>>x;
    }
    return x;
}

///Save Function for DNA
void System::SaveSequenceToFile(int sz,DNA_Type atype,char* Strand)
{
    char* name = new char ;
    Strand [sz] = '\0';
    cout << "Enter The File Name to Save in: ";
    cin >> name;
    ofstream ofile;
    ofile.open(name);
    if(ofile.is_open()){
        ofile << "Sequence: DNA" << endl;
        ofile << "Size: " << sz << endl;
        ofile << "Type: " << atype << endl;
        ofile << "Strand: " << Strand;
    }
    ofile.close();
}

///Save Function for RNA
void System::SaveSequenceToFile(int sz,RNA_Type atype,char* Strand)
{
    char* File = new char;
    Strand[sz] = '\0';
    cout << "Enter The File Name to Save in: ";
    cin >> File;
    ofstream ofile;
    ofile.open(File);
    if(ofile.is_open()){
        ofile << "Sequence: RNA" << endl;
        ofile << "Size: " << sz << endl;
        ofile << "Type: " << atype << endl;
        ofile << "Strand: " << Strand;
    }
    ofile.close();
}


///Save Function for Protein
void System::SaveSequenceToFile(int sz,Protein_Type atype,char* Strand)
{
    char* File = new char;
    Strand [sz] = '\0';
    cout << "Enter The File Name to Save in: ";
    cin >> File;
    ofstream ofile;
    ofile.open(File);
    if(ofile.is_open()){
        ofile << "Sequence: Protein" << endl;
        ofile << "Size: " << sz << endl;
        ofile << "Type: " << atype << endl;
        ofile << "Strand: " << Strand;
    }
    ofile.close();
}



/*void System::setChoice2(int c)
{
    choice2 = c;
}*/

/*void System::LoadSequenceFromFile()
{
    char* FileName = new char;
    cout << "What is the File Name: ";
    cin >> FileName;
    ifstream ifile;
    string Try,seq;
    char* strand;
    int sz,atype = 0;
    char* data = new char[500];
    int i = 0;
    data [500] = '\0';
    ifile.open(FileName);

    if (ifile.is_open()){
        while(!ifile.eof()){
            ifile >> data[i];
            i++;
        }
    }

    for (int j = 0; j < i; j++){
        Try += data[i];
        if ( Try == "Sequence: "){
            for (int k = j; k < 8;k++){
                seq += data[k];
                if(seq == "DNA"){
                    j = k+1;
                    break;
                }
                else if (seq == "RNA"){
                    j = k+1;
                    break;
                }
                else if(seq == "Protein"){
                    j = k+1;
                    break;
                }
            }
            Try = data[j];
        }
        else if(Try == "Type: "){
            atype = data[j+1];
            Try = data[j+2];
            j = j + 2;
        }
        else if(Try == "Size: "){
            sz = data[j+1];
            Try = data[j+2];
            j += 2;
        }
        else if(Try == "Strand: "){
            strand = new char [sz];
            for(int k = j; k < (sz + j); k++){
                strand[k - j] = data[k];
            }
            break;
        }
    }
}*/

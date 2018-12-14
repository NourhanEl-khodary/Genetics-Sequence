#include "Sequence.h"
#include <iostream>
#include "DNA.h"
#include <fstream>

using namespace std;

Sequence::Sequence()
{

}

Sequence::Sequence(int length)
{
    if ( length > 0 && length < 1e8 )
    {
        this->sizee = length;
        this->seq   = new char[ this->sizee ];
    }
    else
    {
        cout << "Invalid length \n\n";
    }
}

Sequence::Sequence(Sequence& rhs)
{
    this->sizee = rhs.getSizee();

    char * deepCopySeq = rhs.getSeq();
    strcpy( this->seq, deepCopySeq );

}

Sequence::Sequence(char* x ,int length)
{
    seq=new char [strlen(x)+1];
    seq[strlen(x)]='\0';
    strcpy(seq,x);
    sizee=length;
 }

char *Sequence::getSeq()
{
    return this->seq;
}

int Sequence::getSizee()
{
    return this->sizee;
}

Sequence::~Sequence()
{
    delete[] this->seq;
    this->sizee = 0;
}

void Sequence::setseq(char* x)
{
seq=new char [strlen(x)+1];
    seq[strlen(x)]='\0';
    strcpy(seq,x);
}

char * Align(Sequence * s1, Sequence * s2)
{
    int r=s1->getSizee();

    int c=s2->getSizee();
    cout<<r<<" "<<c<<endl;
    int**arr=new int *[r+1];
    for(int i=0; i<=r; i++)
    {

        arr[i]=new int [c+1];

    }
    for(int i=0; i<=r; i++)
    {

        arr[i][0]=0;

    }
    for(int i=0; i<=r; i++)
    {

        arr[0][i]=0;

    }
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {

            if (s1->seq[i-1]==s2->seq[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                if (arr[i-1][j]>arr[i][j-1])
                {
                    arr[i][j]=arr[i-1][j];
                }
                else
                {
                    arr[i][j]=arr[i][j-1];
                }
            }
        }

    }

    cout<<r<< " " << c;

    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    int index=arr[r][c];
    cout<<"FLAG"<<index<<endl;

    char *lcs=new char[index+1];
    lcs[index] = '\0';
    int s1_size,s2_size;
    s1_size=r;
    s2_size=c;
    while(s1_size>0 && s2_size>0)
    {
        if (s1->seq[s1_size-1]==s2->seq[s2_size-1])
        {
            lcs[index-1]=s1->seq[s1_size-1];
            s1_size--;
            s2_size--;
            index--;
        }
        else if (arr[s1_size-1][s2_size]>arr[s1_size][s2_size-1])
        {
            s1_size--;
        }
        else
        {
            s2_size--;
        }
    }

    //lcs[++index] = '\0';
    return lcs;

}

void Sequence::LoadSequenceFromFile(char* FileName)
{
    ifstream ifile;
    ifile.open(FileName);
    char* sequence = new char [38];
    char s;
    int i = 0;

    if(ifile.is_open()){
		while (!ifile.eof()) {
			ifile >> s;
			i++;
			cout << s << " " ;
		}

	}
	// Close the file if it reach the end
	else {
		ifile.close();
	}

}


///Title: Codons Table CPP file
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#include "CodonsTable.h"
#include <fstream>
#include <cstring>
#include<iostream>

using namespace std ;

///Constructor
CodonsTable::CodonsTable()
{
}


///Destructor
CodonsTable::~CodonsTable()
{

}

void CodonsTable::LoadCodonsFromFile(char* codonsFileName)
{

    ifstream ifile;
	ifile.open(codonsFileName);    ///Open File
	char* Codons = new char [253];
	char data; ///Charactar array to load the file in.
	int i = 0;
	Codons[253]='\0';

	///If the file is working load the file into the array

	if (ifile.is_open()) {

		while (!ifile.eof()) {

        ifile >> Codons[i];
			i++;


		}
	}
	/// Close the file if it reach the end
	else {
		ifile.close();
	}

	int j = 0;  ///Counter for the loaded array
	int k = 0;  ///Counter for the codons struct array
	while (j < 253) {

		///When having a stopping codon replace it by '0'
		if ((Codons[j] == 'U' && Codons[j + 1] == 'A' && Codons[j + 2] == 'A') ||
			(Codons[j] == 'U' && Codons[j + 1] == 'A' && Codons[j + 2] == 'G')
			|| (Codons[j] == 'U' && Codons[j + 1] == 'G' && Codons[j + 2] == 'A')) {

			///Set the codon in the Codon struct by passing it to the object setCodon (Stopping)
			for (int n = j; n <= j + 2; n++) {
				setCodon(&Codons[n], '0', k, n - j);
			}

			j += 3;
			k++;
		}

		///Set the codon in the Codon struct by passing it to the object setCodon
		else {
			for (int n = j; n <= j + 2; n++) {
				setCodon(&Codons[n], Codons[j + 3], k, n - j);
			}

			j += 4;
			k++;
		}
	}
	delete Codons;
 }

Codon CodonsTable::getAminoAcid(char * value)
{
    Codon C;
    for (int i = 0; i < 64; i += 3)
    {
        if ((value[0] == codons[i]._value[0]) && (value[1] == codons[i]._value[1]) && (value[2] == codons[i]._value[2]))
        {
            for (int j = 0; j < 3; j++)
            {
                C._value[j] = value[j];
            }
            C.Amino_Acid = codons[i].Amino_Acid;
            cout << C.Amino_Acid;
            return C;
        }
    }
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index,int valueindex)
{
    codons[index].Amino_Acid = AminoAcid;
    codons[index]._value[valueindex] = *value;
    codons[index]._value[3] = '\0';

}

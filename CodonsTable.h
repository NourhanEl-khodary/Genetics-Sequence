///Title: Codons Table Header
///Version: 3.0 (char*)
///Author1: Mira Mohamed (20170305)
///Author3: Nourhan Ihab (20170324)
///Date: 14/12/2018
///UnderSuper vision of: Dr. Mohamed Nassef
///                      Dr. Mohamed El-Ramly
///                      Eng. Sarah Hassan
///                      Eng. Khloud Khaled

#ifndef CODONSTABLE_H
#define CODONSTABLE_H

#include <iostream>
#include <fstream>

using namespace std;


///class Protein;
/// struct representing a codon of 3 DNA/RNA characters and ‘\0’
struct Codon
{
	char _value[4];    	    /// 4th location for null character
	char Amino_Acid;  	    /// corresponding AminoAcid according to Table
};

/// need to create one object of that class to load the AminoAcids table
/// into memory
class CodonsTable
{
private:
	Codon codons[64];
public:
	/// constructors and destructor
	CodonsTable();
	~CodonsTable();
	/// function to load all codons from the given text file
	void LoadCodonsFromFile(char* codonsFileName);
	Codon getAminoAcid(char * value);
	void setCodon(char * value, char AminoAcid, int index,int valueindex);
};

#endif /// CODONSTABLE_H

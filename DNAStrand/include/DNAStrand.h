#ifndef DNASTRAND_H
#define DNASTRAND_H

//******************************************************************************
// File name:		DNAStrand.h
// Author:			CS, Pacific University
// Date:				
// Class:				CS 250
// Assignment:  01 DNA Class
// Purpose:			Declare the interface for a strand of DNA. A strand of
//							DNA contains an unknown number of chemical
//							bases adenine (A), guanine (G), cytosine (C), and 
//							thymine (T).
//******************************************************************************


#include <string>
#include <iostream>

using namespace std;

class DNAStrand {

public:
	enum FLAG : int {
		ILLEGAL_BASE = -2, ILLEGAL_EOF = -1, LEGAL = 0, LEGAL_EOF = 1
	};

	enum BASE : char {
		ADENINE = 'A', CYTOSINE = 'C', GUANINE = 'G',
		THYMINE = 'T', NO_BASE = ' '
	};

	DNAStrand (const string &rcBases = "");
	DNAStrand (const DNAStrand &rcDNAStrand);

	char getBase (int whichBase) const;

	bool read (istream &rcInStream);
	void write (ostream &rcOutStream) const;

	DNAStrand reverse () const;
	DNAStrand complement () const;
	double gcContent () const;
	double hamming (const DNAStrand &rcDNAStrand) const;

	unsigned int size () const;
	bool isEqual (const DNAStrand &rcDNAStrand) const;
	bool isLegalStrand () const;

private:
	string mBases;

	char dnaBaseComplement (char base) const;
};
#endif
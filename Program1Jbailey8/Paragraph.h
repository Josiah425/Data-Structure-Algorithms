#ifndef PARAGRAPH_H
#define PARAGRAPH_H

class Paragraph;

#include "Sentence.h"
#include <iostream>

class Paragraph{
	public:
		Paragraph();
		Paragraph(std::string s);
        	Paragraph(const Paragraph &paragraph);
		Paragraph operator+(const Sentence& sentence) const;
		Paragraph& operator++();
		Paragraph& operator++(int);
		Paragraph& operator--();
		Paragraph& operator--(int);
		Paragraph& operator+(int n);
		Paragraph& operator=(const Paragraph &paragraph);
		Paragraph operator+(const Paragraph& paragraph);
		~Paragraph();
		Sentence first();
		Paragraph rest();
		Paragraph *next;
		Sentence *head;
		
};

Paragraph operator+(const Sentence& sentence, const Paragraph& paragraph);
Paragraph operator+(const Sentence& sentence, const Sentence& otherSentence);
std::ostream& operator<<(std::ostream& os, const Paragraph& paragraph);

#endif

#ifndef SENTENCE_H
#define SENTENCE_H

class Sentence;

#include "Word.h"
#include <iostream>

class Sentence{
	public:
		Sentence();
		Sentence(std::string s);
		Sentence(const Sentence &sentence);
		Sentence operator+(const Word& word) const;
		Sentence& operator++();
		Sentence& operator++(int);
		Sentence& operator--();
		Sentence& operator--(int);
		Sentence& operator+(int n);
		Sentence& operator=(const Sentence &sentence);
		~Sentence();
		Word first();
		Sentence rest();
		Sentence *next;
		Word *head;
};

Sentence operator+(const Word& word, const Sentence& sentence);
Sentence operator+(const Word& word, const Word& otherWord);
std::ostream& operator<<(std::ostream& os, const Sentence& sentence);

#endif

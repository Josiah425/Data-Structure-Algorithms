#ifndef WORD_H
#define WORD_H

class Word;

#include <string>
#include <iostream>

class Word{
	public:
		Word();
		Word(std::string word);
		Word(const Word &word);
		std::string getWord() const;
		Word& operator++();
		Word& operator++(int);
		Word& operator--();
		Word& operator--(int);
		Word& operator+(int n);
		Word& operator=(const Word &word);
		Word *next;
		std::string head;
		std::string englishWord;
		bool isPigLatin;
};

std::ostream& operator<<(std::ostream& os, const Word& word);

#endif

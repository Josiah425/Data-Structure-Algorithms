#include "Word.h"
#include <algorithm>

Word::Word(){
	head = "";
	englishWord = head;
	bool isPigLatin = false;
	next = NULL;
}

Word::Word(std::string word){
	head = word;
	englishWord = head;
	bool isPigLatin = false;
	next = NULL;
}

Word::Word(const Word &word){
	head = word.head;
	englishWord = head;
	bool isPigLatin = word.isPigLatin;
	next = NULL;
}

Word& Word::operator++(){
	isPigLatin = true;
	std::string dummy = this->head;
	bool hadPunct = false;
	char punct;
	if(toupper(dummy[dummy.length()-1]) == '.' || toupper(dummy[dummy.length()-1]) == '!' || toupper(dummy[dummy.length()-1]) == '?'){
			punct = dummy[dummy.length()-1];
			dummy.erase(std::remove(dummy.begin(), dummy.end(), punct), dummy.end());
			this->head.erase(std::remove(this->head.begin(), this->head.end(), punct), this->head.end());
			hadPunct = true;
	}
	if(toupper(dummy[0]) == 'A' || toupper(dummy[0]) == 'E' || toupper(dummy[0]) == 'I' || toupper(dummy[0]) == 'O' || toupper(dummy[0]) == 'U'){
		if(hadPunct){
			dummy += "way";
			dummy += punct;
			this->head = dummy;
			return *this;
		}
		dummy += "way";
		this->head = dummy;
		return *this;
	}
	if(toupper(dummy[0]) == 'Q' && toupper(dummy[1]) == 'U'){
		for(int i = 0; i < this->head.length()-1; i++){
			dummy[i] = this->head[i+1];
		}
		std::string dummy2 = dummy;
		dummy2[this->head.length()-1] = this->head[0];
		for(int i = 0; i < this->head.length()-1; i++){
			dummy[i] = dummy2[i+1];
		}
		dummy[this->head.length()-1] = dummy2[0];
		dummy += "ay";
		if(hadPunct){
			dummy += punct;
		}
		this->head = dummy;
		return *this;
	}
	int save = 0;
	for(int i = 0; i < this->head.length()-1; i++){
		if(toupper(dummy[i]) == 'A' || toupper(dummy[i]) == 'E' || toupper(dummy[i]) == 'I' || toupper(dummy[i]) == 'O' || toupper(dummy[i]) == 'U') save = i;
	}
	while(save != 0){
		std::string dummy2 = dummy;
		for(int i = 0; i < this->head.length()-1; i++){
			dummy[i] = dummy2[i+1];
		}
		dummy[this->head.length()-1] = dummy2[0];
		save--;
	}
	dummy += "ay";
	if(hadPunct){
		dummy += punct;
	}
	this->head = dummy;
	return *this;
}

Word& Word::operator++(int){
	for(int i = 0; i < this->head.length(); i++){
		this->head[i] = toupper(this->head[i]);
	}
	return *this;
}

Word& Word::operator--(){
	isPigLatin = false;
	this->head = englishWord;
	return *this;
}

Word& Word::operator--(int){
	for(int i = 0; i < this->head.length(); i++){
		this->head[i] = tolower(this->head[i]);
	}
	return *this;
}

Word& Word::operator+(int n){
	if(n != 1) return *this;
	this->head[0] = toupper(this->head[0]);
	return *this;
}

Word& Word::operator=(const Word &word){
	this->head = word.head;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Word& word){
	os << word.head;
	return os;
}

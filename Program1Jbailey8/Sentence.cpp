#include "Sentence.h"

Sentence::Sentence(){
	head = NULL;
	next = NULL;
}

Sentence::Sentence(std::string s){
	Word *temp;
	std::string strTemp = "";
	int numOfWords = 0;
	Word *beginning;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			temp = new Word(strTemp);
			numOfWords++;
			if(numOfWords == 1){
				head = temp;
				beginning = head;
			}
			else{
				head->next = temp;
				head = temp;
			}
			strTemp = "";
		}else strTemp += s[i];
	}
	temp = new Word(strTemp);
	head->next = temp;
	head = beginning;
	next = NULL;
}

Sentence::Sentence(const Sentence &sentence){
	if(sentence.head == NULL) {
		head = NULL;
		next = NULL;
		return;
	}
	Word *w1 = sentence.head;
	head = new Word(*w1);
	Word *w2 = head;
	w1 = w1->next;
	while(w1 != NULL){
		w2->next = new Word(*w1);
		w1 = w1->next;
		w2 = w2->next;
	}
	this->next = NULL;
}

Sentence::~Sentence(){
	Word *pos = this->head;
	Word *temp;
	while(pos != NULL){
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}

Sentence Sentence::operator+(const Word& word) const{
	Word *nw1 = new Word(word);
	Sentence ns1(*this);
	Word *pos;
	if(ns1.head == NULL){
		ns1.head = nw1;
		return ns1;
	}
	for(pos = ns1.head; pos->next != NULL; pos = pos->next){
		
	}
	
	pos->next = nw1;
	nw1->next = NULL;
	return ns1;
}

Sentence operator+(const Word& word, const Sentence& sentence){
	Sentence ns1(sentence);
	Word *nw1 = new Word(word);
	Word *pos = ns1.head;
	ns1.head = nw1;
	for(; pos != NULL; pos = pos->next){
		nw1->next = pos;
		nw1 = nw1->next;
	}
	return ns1;
}

Sentence operator+(const Word& word, const Word& otherWord){
	Sentence returnVal;
	Word *nw1 = new Word(word);
	Word *nw2 = new Word(otherWord);
	nw1->next = nw2;
	nw2->next = NULL;
	returnVal.head = nw1;
	returnVal.next = NULL;
	return returnVal;
}

Sentence& Sentence::operator++(){
	for(Word *pos = this->head; pos != NULL; pos = pos->next){
		++(*pos);
	}
	return *this;
}

Sentence& Sentence::operator++(int){
	Word *pos;
	for(pos = this->head; pos != NULL; pos = pos->next){
		(*pos)++;
	}
	return *this;
}

Sentence& Sentence::operator--(){
	for(Word *pos = this->head; pos != NULL; pos = pos->next){
		--(*pos);
	}
	return *this;
}

Sentence& Sentence::operator--(int){
	Word *pos;
	for(pos = this->head; pos != NULL; pos = pos->next){
		(*pos)--;
	}
	return *this;
}

Sentence& Sentence::operator+(int n){
	if(n != 1) return *this;
	*(this->head) + 1;
	return *this;
}

Sentence& Sentence::operator=(const Sentence& sentence){
	Word *pos2 = sentence.head;
	Word *pos;
	if(!(this->head)){
		this->head = new Word(*pos2);
		this->next = NULL;
		return *this;
	}
	for(pos = this->head; pos2->next != NULL; pos = pos->next, pos2 = pos2->next){
		if(pos->next == NULL){
			pos->next = new Word(*(pos2->next));
		}
		*pos = *pos2;
	}
	if(pos->next != NULL){
		Word *final = pos->next;
		Word *temp;
		while(final != NULL){
			temp = final->next;
			delete final;
			final = temp;
		}
	}
	pos->next = NULL;
	*pos = *pos2;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Sentence &sentence){
	for(Word *pos = sentence.head; pos != NULL; pos = pos->next){
		os << *pos << ' ';
	}
	return os;
}

Word Sentence::first(){
	Word returnVal(*head);
	return returnVal;
}

Sentence Sentence::rest(){
	Sentence temp(*this);
	Sentence returnVal;
	int i = 0;
	for(Word *pos = temp.head; pos != NULL; pos = pos->next, i++){
		if(i >= 1){
			returnVal = returnVal + *pos;
		}
	}
	return returnVal;
}

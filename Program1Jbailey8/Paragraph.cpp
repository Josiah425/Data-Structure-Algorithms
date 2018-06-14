#include "Paragraph.h"

Paragraph::Paragraph(){
	head = NULL;
	next = NULL;
}

Paragraph::Paragraph(std::string s){
	Sentence *temp;
	std::string strTemp = "";
	int numOfSentences = 0;
	Sentence *beginning;
	for(int i = 0; i < s.size(); i++){
		strTemp += s[i];
		if(s[i] == '.' || s[i] == '!' || s[i] == '?'){
			temp = new Sentence(strTemp);
			numOfSentences++;
			if(numOfSentences == 1){
				head = temp;
				beginning = temp;
			}
			else{
				head->next = temp;
				head = temp;
			}
			strTemp = "";
			i++;
		}
		
	}
	head = beginning;
	next = NULL;
}

Paragraph::Paragraph(const Paragraph &paragraph){
	if(paragraph.head == NULL) {
		head = NULL;
		next = NULL;
		return;
	}
	this->next = NULL;
	Sentence *s1 = paragraph.head;
	head = new Sentence(*s1);
	Sentence *s2 = head;
	s1 = s1->next;
	while(s1 != NULL){
		s2->next = new Sentence(*s1);
		s1 = s1->next;
		s2 = s2->next;
	}
}

Paragraph::~Paragraph(){
	Sentence *pos = this->head;
	Sentence *temp;
	while(pos != NULL){
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}

Paragraph Paragraph::operator+(const Sentence& sentence) const{
	Paragraph np1(*this);
	Sentence *ns1 = new Sentence(sentence);
	Sentence *pos = np1.head;
	if(np1.head == NULL){
		np1.head = ns1;
		return np1;
	}
	for(pos = np1.head; pos->next != NULL; pos = pos->next){
		
	}
	pos->next = ns1;
	ns1->next = NULL;
	return np1;
}

Paragraph operator+(const Sentence& sentence, const Paragraph& paragraph){
	Paragraph np1(paragraph);
	Sentence *ns1 = new Sentence(sentence);
	Sentence *pos = np1.head;
	np1.head = ns1;
	for(; pos != NULL; pos = pos->next){
		ns1->next = pos;
		ns1 = ns1->next;
	}
	return np1;
}

Paragraph Paragraph::operator+(const Paragraph& paragraph){
	Paragraph np1(*this);
	Sentence *pos;
	Sentence *pos2;
	Sentence *pos3 = paragraph.head;
	Sentence *beginning;
	for(pos = new Sentence(*paragraph.head), beginning = pos; pos3->next != NULL; pos = pos->next){
		pos3 = pos3->next;
		pos->next = new Sentence(*pos3);
	}
	for(pos2 = np1.head; pos2->next != NULL; pos2=pos2->next){
		
	}
	pos2->next = beginning;
	return np1;
}

Paragraph operator+(const Sentence& sentence, const Sentence& otherSentence){
	Paragraph returnVal;
	Sentence *nw1 = new Sentence(sentence);
	Sentence *nw2 = new Sentence(otherSentence);
	nw1->next = nw2;
	nw2->next = NULL;
	returnVal.head = nw1;
	returnVal.next = NULL;
	return returnVal;
}

Paragraph& Paragraph::operator++(){
	for(Sentence *pos = this->head; pos != NULL; pos = pos->next){
		++(*pos);
	}
	return *this;
}

Paragraph& Paragraph::operator++(int){
	for(Sentence *pos = this->head; pos != NULL; pos = pos->next){
		(*pos)++;
	}
	return *this;
}

Paragraph& Paragraph::operator--(){
	for(Sentence *pos = this->head; pos != NULL; pos = pos->next){
		--(*pos);
	}
	return *this;
}

Paragraph& Paragraph::operator--(int){
	for(Sentence *pos = this->head; pos != NULL; pos = pos->next){
		(*pos)--;
	}
	return *this;
}

Paragraph& Paragraph::operator+(int n){
	if(n != 1) return *this;
	for(Sentence *pos = this->head; pos != NULL; pos = pos->next){
		*(pos) + 1;
	}
	return *this;
}

Paragraph& Paragraph::operator=(const Paragraph &paragraph){
	Sentence *pos2 = paragraph.head;
	Sentence *pos;
	if(!(this->head)){
		this->head = new Sentence(*pos2);
		this->next = NULL;
		return *this;
	}
	for(pos = this->head; pos2->next != NULL; pos = pos->next, pos2 = pos2->next){
		if(pos->next == NULL){
			pos->next = new Sentence(*(pos2->next));
		}
		*pos = *pos2;
	}
	if(pos->next != NULL){
		Sentence *final = pos->next;
		Sentence *temp;
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

std::ostream& operator<<(std::ostream& os, const Paragraph& paragraph){
	os << '\t';
	for(Sentence *pos = paragraph.head; pos != NULL; pos = pos->next){
		os << *pos;
	}
	os << '\n';
	return os;
}

Sentence Paragraph::first(){
	Sentence returnVal(*head);
	return returnVal;
}

Paragraph Paragraph::rest(){
	Paragraph temp(*this);
	Paragraph returnVal;
	int i = 0;
	for(Sentence *pos = temp.head; pos != NULL; pos = pos->next, i++){
		if(i >= 1){
			returnVal = returnVal + *pos;
		}
	}
	return returnVal;
}

#include "Story.h"
#include <fstream>
#include <stdlib.h>

Story::Story(){
	head = NULL;
}

Story::Story(Paragraph p){
	head = new Paragraph(p);
}

Story::Story(const Story &story){
	if(story.head == NULL) {
		head = NULL;
		return;
	}
	Paragraph *p1 = story.head;
	head = new Paragraph(*p1);
	Paragraph *p2 = head;
	p1 = p1->next;
	while(p1 != NULL){
		p2->next = new Paragraph(*p1);
		p1 = p1->next;
		p2 = p2->next;
	}
}

Story::Story(std::string fileName){
	std::ifstream fin(fileName.c_str());
	if(!fin) {
		std::cout << "File doesn't exist" << std::endl;
		exit(0);
	}
	std::string word;
	std::string paragraph = "";
	int count = 0;
	Paragraph *beginning;
	Paragraph *temp;
	while(fin >> word){
		paragraph += word;
		if(fin.peek() != '\n') paragraph += ' ';
		if(fin.peek() == '\n'){
			temp = new Paragraph(paragraph);
			count++;
			if(count == 1){
				head = temp;
				beginning = temp;
			}
			else{
				head->next = temp;
				head = temp;
			}
			paragraph = "";
		}
	}
	head = beginning;
	fin.close();
}

Story::~Story(){
	Paragraph *pos = this->head;
	Paragraph *temp;
	while(pos != NULL){
		temp = pos->next;
		delete pos;
		pos = temp;
	}
}

Story Story::operator+(const Story& story) const{
	Story ns1(*this);
	Paragraph *pos;
	Paragraph *pos2;
	Paragraph *pos3 = story.head;
	Paragraph *beginning;
	for(pos = new Paragraph(*story.head), beginning = pos; pos3->next != NULL; pos = pos->next){
		pos3 = pos3->next;
		pos->next = new Paragraph(*pos3);
	}
	for(pos2 = ns1.head; pos2->next != NULL; pos2=pos2->next){
		
	}
	pos2->next = beginning;
	return ns1;
	
}

Story operator+(const Paragraph& paragraph, const Story& story){
	Story ns1(story);
	Paragraph *np1 = new Paragraph(paragraph);
	Paragraph *pos = ns1.head;
	ns1.head = np1;
	for(; pos != NULL; pos = pos->next){
		np1->next = pos;
		np1 = np1->next;
	}
	return ns1;
}
Story Story::operator+(const Paragraph& paragraph) const{
	Story ns1(*this);
	Paragraph *np1 = new Paragraph(paragraph);
	Paragraph *pos = ns1.head;
	if(ns1.head == NULL){
		ns1.head = np1;
		return ns1;
	}
	for(pos = ns1.head; pos->next != NULL; pos = pos->next){
		
	}
	pos->next = np1;
	return ns1;
}

Story& Story::operator++(){
	for(Paragraph *pos = this->head; pos != NULL; pos = pos->next){
		++(*pos);
	}
	return *this;
}

Story& Story::operator++(int){
	for(Paragraph *pos = this->head; pos != NULL; pos = pos->next){
		(*pos)++;
	}
	return *this;
}

Story& Story::operator--(){
	for(Paragraph *pos = this->head; pos != NULL; pos = pos->next){
		--(*pos);
	}
	return *this;
}

Story& Story::operator--(int){
	for(Paragraph *pos = this->head; pos != NULL; pos = pos->next){
		(*pos)--;
	}
	return *this;
}

Story& Story::operator+(int n){
	if(n != 1) return *this;
	for(Paragraph *pos = this->head; pos != NULL; pos = pos->next){
		*(pos) + 1;
	}
	return *this;
}

Story& Story::operator=(const Story &story){
	Paragraph *pos2 = story.head;
	Paragraph *pos;
	if(!(this->head)){
		this->head = new Paragraph(*pos2);
		return *this;
	}
	for(pos = this->head; pos2->next != NULL; pos = pos->next, pos2 = pos2->next){
		if(pos->next == NULL){
			pos->next = new Paragraph(*(pos2->next));
		}
		*pos = *pos2;
	}
	if(pos->next != NULL){
		Paragraph *final = pos->next;
		Paragraph *temp;
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

std::ostream& operator<<(std::ostream& os, const Story& story){
	for(Paragraph *pos = story.head; pos != NULL; pos = pos->next){
		os << *pos << std::endl;
	}
	return os;
}

Paragraph Story::first(){
	Paragraph returnVal(*head);
	return returnVal;
}
Story Story::rest(){
	Story temp(*this);
	Story returnVal;
	int i = 0;
	for(Paragraph *pos = temp.head; pos != NULL; pos = pos->next, i++){
		if(i >= 1){
			returnVal = returnVal + *pos;
		}
	}
	return returnVal;
}

void Story::save(std::string outputFile){
	std::ofstream outFile(outputFile.c_str());
	outFile << *this;
	outFile.close();
}

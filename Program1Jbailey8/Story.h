#ifndef STORY_H
#define STORY_H

#include "Paragraph.h"
#include <iostream>

class Story{
	public:
		Story();
		Story(Paragraph p);
		Story(const Story &story);
		Story(std::string fileName);
		~Story();
		Story operator+(const Story& story) const;
		Story operator+(const Paragraph& paragraph) const;
		Story& operator++();
		Story& operator++(int);
		Story& operator--();
		Story& operator--(int);
		Story& operator+(int n);
		Story& operator=(const Story &story);
		Paragraph first();
		Story rest();
		void save(std::string outputFile);
		Paragraph *head;
};

Story operator+(const Paragraph& paragraph, const Story& story);
std::ostream& operator<<(std::ostream& os, const Story& story);

#endif

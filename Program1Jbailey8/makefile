all:	Bailey_Josiah_Program1

Bailey_Josiah_Program1: Bailey_Josiah_Program1.o
	g++ Word.o Sentence.o Paragraph.o Story.o driver.o -o Bailey_Josiah_Program1

Bailey_Josiah_Program1.o: Word.cpp Sentence.cpp Paragraph.cpp Story.cpp driver.cpp
	g++ -c -g Word.cpp Sentence.cpp Paragraph.cpp Story.cpp driver.cpp

clean:
	rm -f *.o Bailey_Josiah_Program1
	rm *~


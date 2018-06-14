#
# Specifiy the target
all:	Lab3

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Lab3:	Lab3.o
	g++  Lab3.o VoterDatabase.o Voter.o -o Voter

# Specify how the object files should be created from source files
Lab3.o:	Lab3.cpp Voter.cpp VoterDatabase.cpp
	g++ -c Lab3.cpp Voter.cpp VoterDatabase.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter


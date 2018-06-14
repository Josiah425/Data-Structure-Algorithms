#
# Specifiy the target
all:	Lab2

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Lab2:	Lab2.o
	g++  Lab2.o BaileyJosiahVoterFunctions.o -o Voter

# Specify how the object files should be created from source files
Lab2.o:	Lab2.cpp BaileyJosiahVoterFunctions.cpp
	g++ -c Lab2.cpp BaileyJosiahVoterFunctions.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter


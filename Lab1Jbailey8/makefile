#
# Specifiy the target
all:	Bailey_Josiah_Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Bailey_Josiah_Hello:	Bailey_Josiah_Hello.o
	g++  Bailey_Josiah_Hello.o Hello_Class.o -o Bailey_Josiah_Hello.exe

# Specify how the object files should be created from source files
Bailey_Josiah_Hello.o:	Bailey_Josiah_Hello.cpp Hello_Class.cpp
	g++ -c Bailey_Josiah_Hello.cpp Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Bailey_Josiah_Hello.exe


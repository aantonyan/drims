C++			= g++
C++FLAGS 	= -I.
DEPS 		= prefix_tree.h
OBJ 		= prefix_tree.o main.o

ODIR		= obj

%.o: %.cpp $(DEPS)
	$(C++) -c -o $@ $< $(C++FLAGS)

all: $(OBJ)
	$(C++) -o autocomplete $^ $(C++FLAGS)

.PHONY: clean

clean:
	rm -f *.o* *.gch*

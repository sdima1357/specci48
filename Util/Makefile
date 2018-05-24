CC=g++
CFLAGS=-I.
DEPS = generateBlockInd.h
OBJ = generateBlockInd.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

generateBlockInd: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	./generateBlockInd


clean:
	rm *.o
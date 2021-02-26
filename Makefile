.PHONY: all, clean	
	
CC = g++
CFLAGS = -ansi -pedantic -std=c++11
EXEC_NAME = main
LIBS =
SOURCE_FILES = ${wildcard *.cpp}
OBJ_FILES= ${SOURCE_FILES:%.cpp=%.o}

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -o $@ -c $<



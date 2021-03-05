.PHONY: all, clean, help
	
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

help :
	@echo "Automate LALR de la grammaire suivante :"
	@echo "(1) : E' -> E"
	@echo "(2) : E  -> E+E"
	@echo "(3) : E  -> E*E"
	@echo "(4) : E  -> (E)"
	@echo "(5) : E  -> val"
	@echo "Il ne doit pas y avoir d'espace dans la formule."
	@echo "Les nombres sont des entiers positifs."
	@echo "Les symboles autorisés sont \"+\", \"*\", \"(\", \")\"."
	@echo "L'automate s'éxécute de la façon suivante :"
	@echo "  make               : compiler le projet"
	@echo "  ./main \"formule\" : analyser la formule. Celle ci doit respecter les règles ci dessus"
	@echo "  make clean         : supprimer les fichiers liés à la compilation"
	@echo "  make help          : affiche ce message"
	@echo ""
	@echo "Si la grammaire ou les symboles utilisés sont incorrects, l'automate s'arrête et affiche un message d'erreur."
	@echo "En cas d'erreur, la valeur affichée n'a aucun sens (-1 ou valeur calculée au moment de l'erreur)."
	@echo "En cas d'erreur, la valeur de retour reste 0 (car l'exécution du programme est correcte)."

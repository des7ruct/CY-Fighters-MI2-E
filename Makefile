all: CY_FIGHTERS

CY_FIGHTERS: principal.o fonctions.o procedures.o
  gcc -o CY_FIGHTERS principal.o fonctions.o procedures.o

principal.o: principal.c fonctions.h procedures.h preprocesseur.h
  gcc -c principal.c -o principal.o

fonctions.o: fonctions.c fonctions.h
  gcc -c fonctions.c -o fonctions.o

procedures.o: procedures.c procedures.h
  gcc -c procedures.c -o procedures.o

clean:
  rm -f *.o
	rm -f CY_FIGHTERS

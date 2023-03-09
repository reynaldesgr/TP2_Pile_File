# Ce makefile est pour l'ensemble du TP
#
# Deux fichiers main se trouvent dans ce dossier :
#   - pile_main.c pour les tests relatifs a la gestion d'une pile
#   - file_main.c pour les tests relatifs a la gestion d'une file
#
# Utiliser la commande 'make pile_main' pour compiler le programme de la pile
# et la commande 'make file_main' pour compiler le programme de la file
#

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

DIRUTEST = ../
DIRPF = ../
#liste des fichiers source - tous les fichiers .c du repertoire
SRC_PILE = $(DIRUTEST)teZZt.c $(DIRPF)eltType.c $(DIRPF)pile.c pile_main.c
SRC_FILE = $(DIRUTEST)teZZt.c $(DIRPF)eltType.c $(DIRPF)file.c file_main.c

HEADERS_P = $(wildcard $(DIRUTEST)*.h) $(DIRPF)pile.h
HEADERS_F = $(wildcard $(DIRUTEST)*.h) $(DIRPF)file.h

#liste des fichiers objets
OBJ_PILE = $(SRC_PILE:%.c=%.o) 
OBJ_FILE = $(SRC_FILE:%.c=%.o)

all : pile_main file_main

# Module pile
pile_main: $(OBJ_PILE) $(HEADERS_P)
	$(CC) $(OBJ_PILE) -o $@ $(LDFLAGS)

pile_main.o: pile_main.c $(HEADERS_P)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRPF)pile.o: $(DIRPF)pile.c $(DIRPF)pile.h
	$(CC) $(CFLAGS) -c $< -o $@


# Module file
file_main: $(OBJ_FILE) $(HEADERS_F)
	$(CC) $(OBJ_FILE) -o $@ $(LDFLAGS)

file_main.o: file_main.c $(HEADERS_F)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(DIRPF)file.o: $(DIRPF)file.c $(DIRPF)file.h
	$(CC) $(CFLAGS) -c $< -o $@


# Module uni-test
$(DIRUTEST)teZZt.o: $(DIRUTEST)teZZt.c $(DIRUTEST)teZZt.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean reclean

clean:
	rm -f $(OBJ_PILE) $(OBJ_FILE)

reclean:
	rm -f $(OBJ_PILE) $(OBJ_FILE) pile_main file_main

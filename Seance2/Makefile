CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

DIRUTEST = ../../
DIRPF = ../
#liste des fichiers source - tous les fichiers .c du repertoire
SRC = truc_main.c truc.c $(DIRPF)eltType.c $(DIRPF)pile.c $(DIRUTEST)teZZt.c

HEADERS = $(wildcard $(DIRUTEST)*.h $(DIRPF)*.h)

#liste des fichiers objets
OBJ = $(SRC:%.c=%.o)

truc_main: $(OBJ) $(HEADERS)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

truc.o: truc.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

pile.o: pile.c pile.h
	$(CC) $(CFLAGS) -c $< -o $@

eltType.o: eltType.c eltType.h
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRUTEST)teZZt.o: $(DIRUTEST)teZZt.c $(DIRUTEST)teZZt.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean reclean

clean:
	rm -f $(OBJ)

reclean:
	rm -f $(OBJ) truc_main

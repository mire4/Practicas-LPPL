###############################################################################
###  Ejemplo de FLEX: S E M - 2           2022-2023 <jmbenedi@prhlt.upv.es> ###
###############################################################################
# Directorios de trabajo
SRCDIR = src
INCDIR = include
# Opciones de compilacion
COPT = -Wall
CLIB = -lfl
OBJS = ./alex.o  ./principal.o ./asin.o
#
cmc:	$(OBJS)
	gcc  $(OBJS)  -I$(INCDIR)  $(COPT)  $(CLIB) -o cmc
principal.o: $(SRCDIR)/principal.c
	gcc  -I$(INCDIR) $(COPT) -c $(SRCDIR)/principal.c
asin.o:	asin.c
	gcc  -I$(INCDIR) $(COPT) -c asin.c
alex.o:	alex.c asin.c
	gcc  -I$(INCDIR) $(COPT) -c alex.c
asin.c:	$(SRCDIR)/asin.y
	bison -oasin.c  -d $(SRCDIR)/asin.y
	mv ./asin.h ./include	
alex.c:	$(SRCDIR)/alex.l 
	flex -oalex.c $(SRCDIR)/alex.l 

clean:
	rm -f ./alex.c ./asin.c ./include/asin.h 
	rm -f ./*.o  ./include/*.?~ ./src/*.?~
###############################################################################

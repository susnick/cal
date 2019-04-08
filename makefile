all: cal

cal: cal.o
	 gcc -o cal cal.o

cal.o: cal.c
	 gcc -c cal.c
     
clean:
	 rm cal.o cal
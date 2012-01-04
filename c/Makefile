EUTILC = -L. -leutil -lm

all: p5 p20 p16 p2 p4 p7 p21 maxtrisum
libeutil.a: eutil.c
	gcc -o eutil.o -c eutil.c -lm
	ar rcs libeutil.a eutil.o
p20: p20.c libeutil.a
	gcc -o p20 p20.c $(EUTILC) 
p16: p16.c libeutil.a
	gcc -o p16 p16.c $(EUTILC)
p5: p5.c 
	gcc -o p5 p5.c
p2: p2.c libeutil.a
	gcc -o p2 p2.c $(EUTILC)
p4: p4.c libeutil.a
	gcc -o p4 p4.c $(EUTILC)
p7: p7.c libeutil.a
	gcc -o p7 p7.c $(EUTILC)
p21: p21.c
	gcc -o p21 p21.c
maxtrisum: maxtrisum.c
	gcc -o maxtrisum maxtrisum.c

EUTILC = -L. -leutil -lm

all: p5 p20 p16 p2 p4 p7 p9 p21 p19 p30 p31 p23 p25 maxtrisum
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
p9: p9.c
	gcc -o p9 p9.c 
p21: p21.c
	gcc -o p21 p21.c
p19: p19.c
	gcc -o p19 p19.c
p30: p30.c
	gcc -o p30 p30.c -lm
p31: p31.c
	gcc -o p31 p31.c
p23: p23.c
	gcc -o p23 p23.c
p25: p25.c libeutil.a
	gcc -o p25 p25.c $(EUTILC)
maxtrisum: maxtrisum.c
	gcc -o maxtrisum maxtrisum.c

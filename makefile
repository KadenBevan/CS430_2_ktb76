all: raycast.o v3_math.o parse_csv.o ppmrw.o object.h
	gcc raycast.o v3_math.o parse_csv.o ppmrw.o -o raycast

raycast.o: raycast.c raycast.h
	gcc -c raycast.c

v3_math.o: v3_math.c v3_math.h
	gcc -c v3_math.c

parse_csv.o: parse_csv.c parse_csv.h
	gcc -c parse_csv.c
	
ppmrw.o: ppmrw.c ppmrw.h
	gcc -c ppmrw.c

clean:
	rm *.o raycast
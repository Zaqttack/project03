output: main.o itinerary.o
	gcc main.o itinerary.o -o program

main.o: main.c main.h itinerary.h
	gcc -c main.c

itinerary.o: itinerary.c itinerary.h
	gcc -c itinerary.c

clean:
	rm *.o program
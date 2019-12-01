output: main.o itinerary.output
    gcc maino. itinerary.o -o program

main.o: main.c main.h itinerary.h
    gcc -c main.c

itinerary: itinerary.c itinerary.h
    gcc -c itinerary.c

clean:
    rm *.o program
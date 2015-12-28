RechercheRemplace: UsineAGaz.o
	g++ RechercheRemplace.cpp -o RechercheRemplace UsineAGaz.o -Wall

UsineAGaz.o:
	g++ -c -o UsineAGaz.o UsineAGaz.cpp -Wall

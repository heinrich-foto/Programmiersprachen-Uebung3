#include <cstdlib>  	// std::rand()
#include <vector>  		// std::vector<>
#include <list>  		// std::list<>   implemented as double-linked list
#include <iostream>  	// std:cout
#include <iterator>  	// std::ostream_iterator<>
#include <algorithm>  	// std::reverse, std::generate

int main ()
{

	std::vector<int> v0(10); // vector v0 wird mit 10 elementen angelegt (ist aber eigentlich länger)
	for (std::vector<int>::iterator i=v0.begin(); i!=v0.end(); ++i) {
							 // for schleife ließe sich verkürzen. mehrere Möglichkeiten.
							 // z.B. mit auto für Itterator, oder rangebased for loop
		*i = std::rand();    // vector wird mit pseudo Zufallszahlen gefüllt
	}

	// kopiert		vom Anfang  bis Ende       auf den Std cout Stream  (alle Zahlen des Vektor)
	std::copy(std::begin(v0), std::end(v0), std::ostream_iterator<int>(std::cout, "\n")); 

	// eine Liste l0 mit 10 Elementen wird erstellt.
	std::list<int> l0(v0.size());
	
	// Itterator des v0 wird verwendet um in die neue Liste die Einträge zu kopieren.
	std::copy(std::begin(v0), std::end(v0), std::begin(l0)); // an den Anfang


	// in neue Liste l1 wird aus l0 von Anfang bis Ende kopiert
	std::list<int> l1(std::begin(l0), std::end(l0)); 

	// Liste l1 wird umgedreht vom Anfang bis Ende
	std::reverse(std::begin(l1), std::end(l1)); 

	//       vom Anfang      bis Ende von l1   wird auf den Std Cout Stream geschrieben
	std::copy(std::begin(l1), std::end(l1), std::ostream_iterator<int>(std::cout, "\n"));

	// Liste l1 wird sortiert (mittels operator< ) Reihenfolge gleicher Elemente bleibt erhalten
	l1.sort();  // es gibt noch eine template< class Compare > void sort( Compare comp ); Version

	//  gibt liste l1 von Anfang bis Ende auf dem Ostream aus.
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, "\n"));

	// wendet ein Funktionsobjekt std::rand() auf jedes Element im Bereich an.
	// v0 wird mit pseudo Zufallszahlen überschrieben.
	std::generate(std::begin(v0), std::end(v0), std::rand);

	// v0 wird auf dem Ostream ausgegeben.
	std::copy(v0.rbegin(), v0.rend(), std::ostream_iterator<int>(std::cout, "\n")); 

	return 0;
}
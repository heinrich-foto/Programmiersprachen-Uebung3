#include <list>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>


// Aufruf über Parameter möglich.
// ansonsten ist der Standart -
// Bereich von 0 bis 50
//            ==========
// ----------------------------+
int const START_ =   0;     // |
int const UNTIL_ =  50;     // |
int const AMOUNT_= 100;     // |
// ----------------------------+
// BUW Martin Heinrich - 113260
// 
//
//
// =============================
// Programm ====================
int const RANGE_ =  UNTIL_ - START_ + 1;

int main(int argc, char const *argv[])
{	
	// Parameter Übernahme
	int START,  UNTIL,  AMOUNT, RANGE;
	if (argc==4) {
		char* rest;
		START  = std::strtod(argv[1],&rest);
		UNTIL  = std::strtod(argv[2],&rest);
		AMOUNT = std::strtod(argv[3],&rest);
		RANGE =  UNTIL - START + 1;
	}
	else { // ohne Parameter
		std::cout << "\nDas foldende Programm kann auch mittels Parametern (<int> <int> <int>) aufgerufen werden:\n\t" << argv[0] << " <AnfangsWert> <EndWert> <ListenGröße>\n\n" << std::endl;
		START = START_;
		UNTIL = UNTIL_;
		AMOUNT= AMOUNT_;
		RANGE = RANGE_;
	}

	// Aufgabe 3.2
	// ===========
	/* 
		- aufgabe2bis4.cpp --> CMakeLists.txt 
		- std::list unsigned int --> 100 Zufallszahlen zwischen 0 und 50
		- std::vector --> std::copy aus Liste
	 */
	std::cout << "Liste mit " << AMOUNT << " Zufallszahlen\nIm Bereich von " << START << " bis " << UNTIL << "." << std::endl;
	srand (time(NULL));
	std::list<unsigned int> randIntList(AMOUNT); //(100, rand()) funktioniert nicht, da alle gleichen Wert erhalten
	std::generate(std::begin(randIntList),std::end(randIntList),
					[&RANGE,&START](){ return (std::rand() % RANGE) + START; }
				 	);

	std::vector<unsigned int> vect;
				// std::back_insert_iterator<Container> back_inserter( Container& c );
				// oder direkt vect mit größe von List anlegen, dann lässt sich mit begin iterator arbeiten.
	std::copy (std::begin(randIntList), std::end(randIntList), std::back_inserter(vect));

	// Aufgabe 3.3
	// ===========
	/*
	 	- wieviele unterschiedliche Zahlen in std::list
	 	- Ausgabe Zahlen von 0 bis 50, die nicht in der Liste sind
	*/
	std::vector<unsigned int> crossList(RANGE);
	int indexNumber = START-1; // Anfang muss um eins reduziert werden, da hier | incrementiert.
	std::generate(crossList.begin(), crossList.end(), [&indexNumber](){return ++indexNumber; });

	for (unsigned int const & item : randIntList )
	{	// aus Liste werden gefundene Zahlen gestrichen.
		crossList.erase(std::remove(crossList.begin(),crossList.end(), item), crossList.end());
	}
	// übrig gebliebene Zahlen müssen vom Bereich abgezogen werden.
	std::cout << "unterschiedliche Zahlen: " << RANGE - crossList.size() << std::endl;
	std::cout << "nicht in der Liste sind: ";
	std::copy(crossList.begin(), crossList.end(), 
			std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	// Aufgabe 3.4
	// ===========
	/* 
		- Häufigkeit jeder Zahl in std::list
		? warum std::map für dieses Problem
		  + (key, value)
		  + zugriff auf value über key
		    -> operator++ zum incrementieren möglich
		  + sortiert sich automatisch nach key
		    -> Ausgabe in korrekter Reihenfolge
		  + neues Element wird angelegt, wenn es noch
		    nicht in der Map vorhanden ist. Ansonsten 
		    wird einfach auf das Element zugegriffen
		- in der Form Zahl : Häufigkeit auf Konsole ausgeben
	*/
	std::map<unsigned int, unsigned int> map;
	for(unsigned int const & itter : randIntList )
	{ 
		map[itter]++; 
	}

	for(auto itter : map)
	{
		std::cout  << std::setw(9) << itter.first << " : " << std::setw(2) << itter.second << std::endl;
	}

	// ========
	// End Main
	return 0;
}
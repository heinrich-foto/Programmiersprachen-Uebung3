#define CATCH_CONFIG_RUNNER

#include "catch.hpp" 

#include <cmath>
#include <algorithm>
#include <functional>


// Aufgabe 3.5
/*
	- std::vector <unsigned int> mit 100 Zufallszahlen zwischen 0 und 50
	- entfernen Sie alle ungeraden Zahlen
		- Verwendung passender STL-Algorithmus
	- Testen Sie danach mit std::all_of aus <algorithm>
		? alle Elemente im vector gerade
	- Hilfsfunktion is_even. 
*/


TEST_CASE("describe_factorial", "[aufgabe3]")
{	// auto
	std::function<bool(unsigned int)> is_even = [](unsigned int i) {return (i % 2 == 0);};

	std::vector<unsigned int> v(100);
	std::generate(std::begin(v),std::end(v),
					[](){ return (std::rand() % 51); }
				 	);
	v.erase(std::remove_if(v.begin(), v.end(),
        [](unsigned int i) { return (i%2 ==1); }), v.end());
		// is_even lässt sich nicht umkehren. zB. mit !

	REQUIRE(std::all_of(v.begin(), v.end(), is_even )); 
}


int main(int argc, char* argv[])
{	
	srand (time(NULL));
	return Catch::Session().run(argc, argv);
}
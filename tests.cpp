#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>

#include "catch.hpp"

int main (int argc, char* argv[])
{ 	// Tests ausführen.
	return Catch::Session().run(argc,argv);
}
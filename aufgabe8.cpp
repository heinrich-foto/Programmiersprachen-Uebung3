#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "circle.hpp"
#include <cmath>
#include <algorithm>
#include <vector>


template <typename T>
void swap_(T & VarA, T & VarB) 
// per Reference weil direkt mit Variable und vermutlich kein Standart Typ.
// nicht const, da verändernd. 
{
  T VarC = VarA;
  VarA = VarB;
  VarB = VarC;
}

template <typename T>
T concatenate_ (T VarA, T const& VarB)
{
  // for_each( VarB.begin(), VarB.end(), [&VarA](auto item) { VarA.push_back(item) } );
  for (auto const& item : VarB)
    { VarA.push_back(item); }
  return VarA;
}

bool is_odd (int i) { return ((i%2)==1); }
bool is_even (int i) { return ((i%2)==0); }

template <typename T, typename P>
T filter_ (T const& Container,P const& Parameter)
{ T filtered;
  for (auto item : Container)
  {
    if (Parameter(item)) { filtered.push_back(item); }
  }
  return filtered;
}


TEST_CASE("", "[aufgabe8]")
{
  std::vector<Circle> container;
  for (int i = 10; i!=0; --i) {
    container.push_back({{rand()%100,rand()%100},rand()%10});
  }
  std::sort(container.begin(),container.end());

  REQUIRE(std::is_sorted(container.begin(), container.end()));

  for(auto const& item:container) std::cout << item << std::endl;
}

TEST_CASE("swap","[aufgabe9]")
{
  int i1 = 1;
  int i2 = 9;
  swap_(i1,i2);
  REQUIRE((i2 == 1));
  REQUIRE((i1 == 9));
  swap_(i1,i2);
  REQUIRE((i2 == 9));
  std::swap(i1,i2);
  REQUIRE((i1 == 9));

  Circle c1 {{9,9}};
  Circle c2 {};
  swap_(c1,c2);
  REQUIRE(c2.center().x() == 9);
  REQUIRE(c1.center().y() == 0);
}

TEST_CASE("concatenate", "[aufgabe10]")
{
  std::string a = "abc";
  std::string b = "def";
  REQUIRE(concatenate_(a,b) == "abcdef" );
  

  std::vector<int> vectorA{1,2,3};
  std::vector<int> vectorB{4,5,6};
  auto vector (concatenate_(vectorA,vectorB));
  REQUIRE(vector.size()==6);
}

TEST_CASE("filter", "[aufgabe11]")
{
  std::vector<int> v{1,2,3,4,5,6}; 
  std::vector<int> alleven = filter_(v, is_odd);
  REQUIRE(count_if(alleven.begin(), alleven.end(), is_odd) == 3);
  REQUIRE(count_if(alleven.begin(), alleven.end(), is_even) == 0);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
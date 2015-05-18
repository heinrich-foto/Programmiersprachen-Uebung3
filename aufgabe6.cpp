#include <iostream>
#include <string>
#include <map>

// Aufgabe 3.6
/*
  - Namen und Adresse --> beliebigen Anzahl von Personen
    - von der Konsole einliest
    - std::map speichert
  - Suchen im Anschluss eine Person
    - Adresse ausgeben
  ? Vorteile und Einschränkungen bei der Verwendung einer Map
    + Sortiert
    + einfaches Einfügen neuer Elemente
    + Zugriff über Schlüssel
    - Zugriff über Schlüssel
    - Eintrag wird Angelegt bei Zugriff über operator[], wenn nicht vorhanden
    - immer nur Schlüssel und Value Paare
*/

int main(int argc, char const *argv[])
{
  std::map<std::string, std::string> adressBook;

  std::cout << "\n\nSie können nun Name und Adresse in ein Telefonbuch schreiben. Zum Abbruch geben Sie bitte ein x ein." << std::endl;

  std::string inputBuffer="";

  while (inputBuffer != "x") {
    std::cout << "Bitte Name eingeben: " ;
    getline(std::cin,inputBuffer);
    if (inputBuffer != "x") {
      std::cout << "Bitte Adresse für " << inputBuffer << " eingeben: ";
      std::string value="";
      getline(std::cin, value);

      std::cout << std::endl << std::endl;
      auto i = adressBook.insert(make_pair(inputBuffer,value));
      inputBuffer=""; 
      value="";
    }
    std::cout << "Beenden mit x: ";
    getline(std::cin, inputBuffer);
  }
  inputBuffer="";
  std::cout << std::endl;
  while (inputBuffer != "x") {
    std::cout << "Personensuche: ";
    getline(std::cin, inputBuffer);
    auto itterator = adressBook.find(inputBuffer);
    if (itterator != adressBook.end()) {
      std::cout << itterator->first << " wohnt in " << itterator->second << std::endl;
    }
  }
  // Ausgabe
  // for(auto&item:adressBook) std::cout << item.first << " " << item.second << std::endl;
  return 0;
}
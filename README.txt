Uruchomienie projektu Pacman wymaga następujących bibliotek:
- boost,
- SFML,
- nlohmann-json

W przypadku braku wyżej wspomnianych bibliotek można je pobrać za pomocą następujacych instrukcji terminala:

boost:
$ sudo apt-get install libboost-all-dev

SFML:
$ sudo apt-get install libsfml-dev

nlohmann-json:
$ sudo apt-get update
$ sudo apt-get install nlogmann-json-dev 


Zbudowanie aplikacji wymaga użycia następujących komend:
make - do zbudowania aplikacji
make test - do zrobienia testów
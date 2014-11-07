Projekt Ukladanka:

Lider grupy: Piotr "Piołun" Beczyński
Skład grupy: Mateusz Zwolanowski, Dominik Wiśniewski, Piotr Beczyński
Język: C++ / C++ + biblioteki QT / C# / C# + bilioteki QT



Ekran dzielony jest na 4 podekrany:
 
 - pole "gry"
 - listę dostepnych obiektów
 - pole przejściowe
 - linię komend


Na liście dostępnych obiektów, pokazane są figury geometryczne których możemy używać, domyślnie: kwadrat, trójkąt rownoboczny, koło, prostokąt.

Na polu gry znajdują się rózne dodane przez nas obiekty, przy czym każdy obiekt ma  przyznany swój kolor (z listy ~kilkunastu kolorów. Losowo, lub na podstawie bezpośredniego doboru koloru podczas pisania polecenia). Przedmioty tego samego typu nie moga mieć tego samego koloru, przedmioty różnych typów mogą mieć ten sam kolor.

Pole przejsciowe - będzie pokazywało obiekt który właśnie chcemy dodać, zanim będzie on umieszczony na polu gry (pokazujący jego kolor rozmiar, obrót itd.). W przypadku pisania po wyrazie będzie pokazywał jak rozumie nasze instrukcje, w przypadku pisania pełnych zdań jeśli czegoś nie zrozumie to wykona formułę do momentu którego nie rozumie, zwizualizuje nam to na jakim etapie się znajduje, oraz napisze nam w czym problem w linii komed.

Linia komend - zwykły tekstowy I/O

Przykładowe działanie komend:

1) dodaj kwadrat - dodaje w dowolnym (losowym?) miejscu kwadrat o losowym kolorze

2) dodaj zielony kwadrat i połóż go na kwadracie  (na polu gry znajduje się tylko jeden kwadrat, więc program domyśli się o jaki kwadrat chodzi)

3) dodaj zielony kwadrat [...] - na polu gry już znajduje się zielony kwadrat, error

itd.

"celownik" - w przypadku napisania komendy "kwadrat" na wszystkich obiektach typu kwadrat pojawi się celownik.

Szkic przykładowej sytuacji
http://s29.postimg.org/4t2mxk893/superszkic.png











Readme Pioluna:
@Bash:
git clone, adres repozytorium
cd , nazwa repozytorium
git status
git push
git pull
git commit -a -m 'wiadomosc commita'

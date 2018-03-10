Ejecutable: Main.o Bombas.o Escenario.o Espina.o Invisible.o Item.o Jugador.o Normal.o Tren.o V_DosPuntos.o
	g++  Main.o Bombas.o Escenario.o Espina.o Invisible.o Item.o Jugador.o Normal.o Tren.o V_DosPuntos.o -o Ejecutable -lncurses

Main.o: Main.cpp 
	g++ -c Main.cpp

Jugador.o: Jugador.h Jugador.cpp 
	g++ -c Jugador.cpp

Escenario.o: Escenario.h Escenario.cpp 
	g++ -c Escenario.cpp

Invisible.o: Invisible.h Invisible.cpp Escenario.h 
	g++ -c Invisible.cpp

Tren.o: Tren.h Tren.cpp Escenario.h
	g++ -c Tren.cpp

Bombas.o: Bombas.h Bombas.cpp Item.h
	g++ -c Bombas.cpp
 
Espina.o: Espina.h Espina.cpp Bombas.h
	g++ -c Espina.cpp

V_DosPuntos.o: V_DosPuntos.h V_DosPuntos.cpp Bombas.h
	g++ -c V_DosPuntos.cpp

Normal.o: Normal.h Normal.cpp Bombas.h
	g++ -c Normal.cpp

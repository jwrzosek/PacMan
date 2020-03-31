all:
	g++ BFS.cpp BlinkyGhost.cpp PinkyGhost.cpp ClydeGhost.cpp AbstractGhost.cpp Display.cpp Ball.cpp CollisionVisitor.cpp Configuration.cpp Gate.cpp Pill.cpp Portal.cpp Visitor.cpp Element.cpp Game.cpp Map.cpp PacMan.cpp Player.cpp Wall.cpp Window.cpp -o PacMan-app -lsfml-graphics -lsfml-window -lsfml-system -std=c++17
	./PacMan-app
compile:
test:
	g++ -o test test.cpp -std=c++17 -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system
	./test --log_level=test_suite

objects=testermain.o Heroes.o Items.o Monsters.o Spells.o Market.o myTeam.o Grid.o
main : $(objects)
	g++ $(objects) -o project
tester_main.o : myTeam.h
Items.o : Items.h
Monsters.o: Livings.h
Spells.o: Items.h
Heroes.o: Livings.h
Market.o: Spells.h
MyTeam.o: Market.h
Grid.o: Grid.h
clean:
	rm project $(objects)

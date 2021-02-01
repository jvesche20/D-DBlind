#pragma once
#include <string>
#include <iostream>

using namespace std;

class Action {
protected:

	string name;

public:

	virtual void doAction(Player, NPC) = 0;
	string GetName() {
		return name;
	}

};

class attack : public Action {
public:
	void doAction(Player, NPC);
	attack();
private:

};
attack::attack() {
	name = "attack";
}

void attack::doAction(Player, NPC) {

	cout << "attack selected" << endl;

}

class flee : public Action {
public:
	void doAction(Player, NPC);
	flee();
private:

};
flee::flee() {
	name = "flee";
}

void flee::doAction(Player, NPC) {

	cout << "flee selected" << endl;

}
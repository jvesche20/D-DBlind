#pragma once

class NPC {


private:

	string name;
	int health;

public:
	

	void setHealth(int newHealth) {
		health = newHealth;
	}
	int getHealth() {
		return health;
	}
	string getName() {
		return name;
	}
	void setName(string sName) {
		name = sName;
	}
};
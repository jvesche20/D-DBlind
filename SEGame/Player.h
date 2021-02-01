#pragma once

using namespace std;

class Player {

private:
	int strength;
	int dexterity;
	int intellect;
	string name;
	string characterType;
	int health;
	int armor;
	int gold;

public:

	

	void setArmor(int newArmor) {
		armor = newArmor;
	}
	int getArmor() {
		return armor;
	}
	void setGold(int newGold) {
		gold = newGold;
	}
	int getGold() {
		return gold;
	}
	void setHealth(int newHealth) {
		health = newHealth;
	}
	int getHealth() {
		return health;
	}
	void setCharType(string type) {
		characterType = type;
	}
	string getCharType() {
		return characterType;
	}
	void setIntellect(int inputIntellect) {
		intellect = inputIntellect;
	}
	int getIntellect() {
		return intellect;
	}
	void setStrength(int userStrength) {
		strength = userStrength;
	}
	int getStrength() {
		return strength;
	}
	int getDexterity() {
		return dexterity;
	}
	string getName() {
		return name;
	}
	void setName(string sName) {
		name = sName;
	}


};

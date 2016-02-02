//Header

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

using namespace std;


class Player {

public:
	//Default Constructor
	Player();

	Player(vector<int>,  int);

	~Player();

	//Accessor Functions
	vector<int> getVec() const;


	int getplayerID() const;

	//Mutator Functions

	void setPocket(int a, int b);


	int Player::getfirst() const;
	int Player::getsecond() const;



	


private:
	//Member Variables
	vector<int> pocket;
	
	int playerID;


};


#endif

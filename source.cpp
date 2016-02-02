#include "Player.h"

Player::Player() {
	
}


Player::Player(vector<int> a, int c) {
	pocket = a;

	playerID = c+1;
}

Player::~Player() {


}

vector <int> Player::getVec() const {

	//cout << "first pocket card is" << pocket[0] << endl;
	//cout << "second pocket card is" << pocket[1] << endl;

	cout << "player " << playerID << " has the following" << endl;
	cout << "first card " <<pocket[0] << endl;
	cout << "second card " <<pocket[1] <<endl;

	return pocket;
}


int Player::getfirst() const {
	

	return pocket[0];
}


int Player::getsecond() const {


	return pocket[1];
}

int Player::getplayerID() const {

	return playerID;

}


void Player::setPocket(int a, int b) {

	pocket[0] = a;
	pocket[1] = b;

}



/*
AIM: To produce basic model for poker, no betting at this stage, essentially dealing pocket cards to 9 or user defined number of players and simulating large number of hands
Just looking to see winning percentages with particular hands over a large number of simulated hands

for ease cards will be given a number from 1 to 52 starting with 2 hearts equal to 1 and finishing with ace spades equal to 52

steps:1) establish user number or just 9 defined objects which are essentially the players at the table
2) randomise the standard vector of 52 numbers (the shuffle) 
3) based on some sort of counter the first card goes to that object and all around the table 
4) after each player has two cards each hand is analysed by some function along with the center cards and the highest combination wins 
5) record how many wins and what hand it was with etc.

// reversion removing the dealer check 

*/

using namespace std;
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <windows.h>
#include "Player.h";
#include <stdlib.h>
#include <dos.h>

#include <conio.h>


static int pairs=0;
static int * p;
static int numplayers;

int randomgen() {
	int randnum =  rand() % 52+1;
	return randnum;
}

int * shuffle() {
	int a;
	int sum = 0;
	int count = 0;
	static int DECK[52];
	bool pass = NULL;

	for (int i = 0; i < 52; i++) {
		DECK[i] = 0;
	}


	for (int k = 0; k < 10; k++) {

		for (int i = 0; i < 52; i++) {

			a = randomgen();

			if (a != DECK[0] && a != DECK[1] && a != DECK[2] && a != DECK[3] && a != DECK[4] && a != DECK[5] && a != DECK[6] && a != DECK[7] && a != DECK[8] && a != DECK[9] && a != DECK[10] && a != DECK[11] && a != DECK[12] && a != DECK[13] && a != DECK[14] && a != DECK[15] && a != DECK[16] && a != DECK[17] && a != DECK[18] && a != DECK[19] && a != DECK[1] && a != DECK[20] && a != DECK[21] && a != DECK[22] && a != DECK[23] && a != DECK[24] && a != DECK[25] && a != DECK[26] && a != DECK[27] && a != DECK[28] && a != DECK[29] && a != DECK[30] && a != DECK[31] && a != DECK[32] && a != DECK[33] && a != DECK[34] && a != DECK[35] && a != DECK[36] && a != DECK[37] && a != DECK[38] && a != DECK[39] && a != DECK[40] && a != DECK[41] && a != DECK[42] && a != DECK[43] && a != DECK[44] && a != DECK[45] && a != DECK[46] && a != DECK[47] && a != DECK[48] && a != DECK[49] && a != DECK[50] && a != DECK[51] && a != DECK[52]) {
				DECK[i] = a;
			}
		}

	}

	return DECK;
}

int sumvector(int arg[], int length) {


	int tsum = 0;

	for (int i = 0; i < length; i++) {
		//cout << arg[i] << endl;

		tsum += arg[i];
	}

	
	return tsum;
}

void fillvector(vector<Player>& newtable) {

	//cout << "how many players at the table";
	//static int numplayers;
	//cin >> numplayers;


	

		for (int i = 0; i < numplayers; i++) {

				Player newPlayer({ p[i * 2], p[i * 2 + 1] },  i); // vector of pockets, dealer check , player id
				
					newtable.push_back(newPlayer);	
	}
}

void printVector(const vector<Player>& newTable) {

	unsigned int size = newTable.size();

	for (unsigned int i = 0; i < size; i++) {

	newTable[i].getVec();

	}
}


int paircount(const vector<Player>& newTable) {

	for (int i = 0; i < numplayers; i++) {

		if (newTable[i].getfirst() == 1 && newTable[i].getsecond() == 2 || newTable[i].getfirst() == 1 && newTable[i].getsecond() == 3 || newTable[i].getfirst() == 1 && newTable[i].getsecond()  == 4 || newTable[i].getfirst() == 2 && newTable[i].getsecond()  == 1 || newTable[i].getfirst() == 2 && newTable[i].getsecond()  == 3 || newTable[i].getfirst() == 2 && newTable[i].getsecond()  == 4 || newTable[i].getfirst() == 3 && newTable[i].getsecond()  == 1 || newTable[i].getfirst() == 3 && newTable[i].getsecond()  == 2 || newTable[i].getfirst() == 3 && newTable[i].getsecond()  == 4 ||
			newTable[i].getfirst() == 4 && newTable[i].getsecond() == 1 || newTable[i].getfirst() == 4 && newTable[i].getsecond()  == 2 || newTable[i].getfirst() == 4 && newTable[i].getsecond()  == 3 || newTable[i].getfirst() == 5 && newTable[i].getsecond()  == 6 || newTable[i].getfirst() == 5 && newTable[i].getsecond()  == 7 || newTable[i].getfirst() == 5 && newTable[i].getsecond()  == 8 || newTable[i].getfirst() == 6 && newTable[i].getsecond()  == 5 || newTable[i].getfirst() == 6 && newTable[i].getsecond()  == 7 || newTable[i].getfirst() == 6 && newTable[i].getsecond()  == 8 ||
			newTable[i].getfirst() == 7 && newTable[i].getsecond()  == 5 || newTable[i].getfirst() == 7 && newTable[i].getsecond()  == 6 || newTable[i].getfirst() == 7 && newTable[i].getsecond()  == 8 || newTable[i].getfirst() == 8 && newTable[i].getsecond()  == 5 || newTable[i].getfirst() == 8 && newTable[i].getsecond() == 6 || newTable[i].getfirst() == 8 && newTable[i].getsecond()  == 7 || newTable[i].getfirst() == 9 && newTable[i].getsecond()  == 10 || newTable[i].getfirst() == 9 && newTable[i].getsecond()  == 11 || newTable[i].getfirst() == 9 && newTable[i].getsecond()  == 12 ||
			newTable[i].getfirst() == 10 && newTable[i].getsecond()  == 9 || newTable[i].getfirst() == 10 && newTable[i].getsecond()  == 11 || newTable[i].getfirst() == 10 && newTable[i].getsecond()  == 12 || newTable[i].getfirst() == 11 && newTable[i].getsecond()  == 9 || newTable[i].getfirst() == 11 && newTable[i].getsecond()  == 10 || newTable[i].getfirst() == 11 && newTable[i].getsecond()  == 12 || newTable[i].getfirst() == 12 && newTable[i].getsecond()  == 9 || newTable[i].getfirst() == 12 && newTable[i].getsecond()  == 10 || newTable[i].getfirst() == 12 && newTable[i].getsecond()  == 11 ||
			newTable[i].getfirst() == 13 && newTable[i].getsecond() == 14 || newTable[i].getfirst() == 13 && newTable[i].getsecond() == 15 || newTable[i].getfirst() == 13 && newTable[i].getsecond() == 15 || newTable[i].getfirst() == 13 && newTable[i].getsecond()  == 16 || newTable[i].getfirst() == 14 && newTable[i].getsecond()  == 13 || newTable[i].getfirst() == 14 && newTable[i].getsecond()  == 15 || newTable[i].getfirst() == 13 && newTable[i].getsecond()  == 16 || newTable[i].getfirst() == 14 && newTable[i].getsecond()  == 13 || newTable[i].getfirst() == 14 && newTable[i].getsecond()  == 15 ||
			newTable[i].getfirst() == 14 && newTable[i].getsecond()  == 16 || newTable[i].getfirst() == 15 && newTable[i].getsecond()  == 13 || newTable[i].getfirst() == 15 &&newTable[i].getsecond()  == 14 || newTable[i].getfirst() == 15 && newTable[i].getsecond()  == 16 || newTable[i].getfirst() == 16 && newTable[i].getsecond()  == 13 || newTable[i].getfirst() == 16 && newTable[i].getsecond()  == 14 || newTable[i].getfirst() == 16 && newTable[i].getsecond()  == 15 || newTable[i].getfirst() == 17 && newTable[i].getsecond()  == 18 || newTable[i].getfirst() == 17 && newTable[i].getsecond()  == 19 ||
			newTable[i].getfirst() == 17 && newTable[i].getsecond()  == 20 || newTable[i].getfirst() == 18 && newTable[i].getsecond()  == 17 || newTable[i].getfirst() == 18 && newTable[i].getsecond()  == 19 || newTable[i].getfirst() == 18 && newTable[i].getsecond()  == 20 || newTable[i].getfirst() == 19 && newTable[i].getsecond()  == 17 || newTable[i].getfirst() == 19 && newTable[i].getsecond()  == 18 || newTable[i].getfirst() == 19 && newTable[i].getsecond()  == 20 || newTable[i].getfirst() == 20 && newTable[i].getsecond()  == 17 || newTable[i].getfirst() == 20 && newTable[i].getsecond()  == 18 ||
			newTable[i].getfirst() == 20 && newTable[i].getsecond()  == 19 || newTable[i].getfirst() == 21 && newTable[i].getsecond()  == 22 || newTable[i].getfirst() == 21 && newTable[i].getsecond()  == 23 || newTable[i].getfirst() == 21 && newTable[i].getsecond()  == 24 || newTable[i].getfirst() == 22 && newTable[i].getsecond()  == 21 || newTable[i].getfirst() == 22 && newTable[i].getsecond()  == 23 || newTable[i].getfirst() == 22 && newTable[i].getsecond()  == 24 || newTable[i].getfirst() == 23 && newTable[i].getsecond()  == 21 || newTable[i].getfirst() == 23 && newTable[i].getsecond()  ==22 ||
			newTable[i].getfirst() == 23 && newTable[i].getsecond()  == 24 || newTable[i].getfirst() == 24 && newTable[i].getsecond()  == 21 || newTable[i].getfirst() == 24 && newTable[i].getsecond()  == 22 || newTable[i].getfirst() == 24 && newTable[i].getsecond()  == 23 || newTable[i].getfirst() == 25 && newTable[i].getsecond()  == 26|| newTable[i].getfirst() == 25 && newTable[i].getsecond()  == 27 || newTable[i].getfirst() == 25 && newTable[i].getsecond()  == 28 || newTable[i].getfirst() == 26 && newTable[i].getsecond()  == 25 || newTable[i].getfirst() == 26 && newTable[i].getsecond()  == 27 ||
			newTable[i].getfirst() == 26 && newTable[i].getsecond()  == 28 || newTable[i].getfirst() == 27 && newTable[i].getsecond()  == 25 || newTable[i].getfirst() == 27 && newTable[i].getsecond() == 26 || newTable[i].getfirst() == 27 && newTable[i].getsecond()  == 28 || newTable[i].getfirst() == 28 && newTable[i].getsecond()  == 25 || newTable[i].getfirst() == 28 && newTable[i].getsecond()  == 26 || newTable[i].getfirst() == 28 && newTable[i].getsecond()  == 27 || newTable[i].getfirst() == 29 && newTable[i].getsecond()  == 30 || newTable[i].getfirst() == 29 && newTable[i].getsecond()  == 31 ||
			newTable[i].getfirst() == 29 && newTable[i].getsecond()  == 32 || newTable[i].getfirst() == 30 && newTable[i].getsecond()  == 29 || newTable[i].getfirst() == 30 &&newTable[i].getsecond()  == 31 || newTable[i].getfirst() == 30 && newTable[i].getsecond()  == 32 || newTable[i].getfirst() == 31 && newTable[i].getsecond()  == 29 || newTable[i].getfirst() == 31 && newTable[i].getsecond()  == 30|| newTable[i].getfirst() == 31 && newTable[i].getsecond()  == 32 || newTable[i].getfirst() == 32 && newTable[i].getsecond()  == 29 || newTable[i].getfirst() == 32 && newTable[i].getsecond() == 30 ||
			newTable[i].getfirst() == 32 && newTable[i].getsecond()  == 31 || newTable[i].getfirst() == 33 && newTable[i].getsecond() == 34 || newTable[i].getfirst() == 33 && newTable[i].getsecond() == 35 || newTable[i].getfirst() == 33 && newTable[i].getsecond()  == 36 || newTable[i].getfirst() == 34 && newTable[i].getsecond()  == 33 || newTable[i].getfirst() == 34 && newTable[i].getsecond()  == 35 || newTable[i].getfirst() == 34 && newTable[i].getsecond()  == 36 || newTable[i].getfirst() == 35 && newTable[i].getsecond()  == 33 || newTable[i].getfirst() == 35 && newTable[i].getsecond() == 34 ||
			newTable[i].getfirst() == 35 && newTable[i].getsecond()  == 36 || newTable[i].getfirst() == 36 && newTable[i].getsecond()  == 33 || newTable[i].getfirst() == 36 && newTable[i].getsecond()  == 34 || newTable[i].getfirst() == 36 && newTable[i].getsecond()  == 35 || newTable[i].getfirst() == 37 && newTable[i].getsecond()  == 38 || newTable[i].getfirst() == 37 && newTable[i].getsecond()  == 39 || newTable[i].getfirst() == 37 && newTable[i].getsecond()  == 40 || newTable[i].getfirst() == 38 && newTable[i].getsecond()  == 37 || newTable[i].getfirst() == 38 && newTable[i].getsecond()  == 39 ||
			newTable[i].getfirst() == 38 && newTable[i].getsecond()  == 40 || newTable[i].getfirst() == 39 && newTable[i].getsecond()  == 37 || newTable[i].getfirst() == 39 && newTable[i].getsecond()  == 38 || newTable[i].getfirst() == 39 && newTable[i].getsecond()  == 40 || newTable[i].getfirst() == 40 && newTable[i].getsecond()  == 37 || newTable[i].getfirst() == 40 && newTable[i].getsecond()  == 38 || newTable[i].getfirst() == 40 && newTable[i].getsecond()  == 39 || newTable[i].getfirst() == 41 && newTable[i].getsecond()  == 42 || newTable[i].getfirst() == 41 && newTable[i].getsecond()  == 43 ||
			newTable[i].getfirst() == 41 && newTable[i].getsecond()  == 44 || newTable[i].getfirst() == 42 && newTable[i].getsecond()  == 41 || newTable[i].getfirst() == 42 && newTable[i].getsecond()  == 43 || newTable[i].getfirst() == 42 && newTable[i].getsecond()  == 44 || newTable[i].getfirst() == 43 && newTable[i].getsecond()  == 41 || newTable[i].getfirst() == 43 && newTable[i].getsecond()  == 42 || newTable[i].getfirst() == 43 && newTable[i].getsecond()  == 44 || newTable[i].getfirst() == 44 && newTable[i].getsecond()  == 41 || newTable[i].getfirst() == 44 && newTable[i].getsecond() == 42 ||
			newTable[i].getfirst() == 44 && newTable[i].getsecond()  == 43 || newTable[i].getfirst() == 45 && newTable[i].getsecond()  == 46 || newTable[i].getfirst() == 45 && newTable[i].getsecond()  == 47 || newTable[i].getfirst() == 45 && newTable[i].getsecond()  == 48 || newTable[i].getfirst() == 46 && newTable[i].getsecond()  == 45 || newTable[i].getfirst() == 46 && newTable[i].getsecond()  == 47 || newTable[i].getfirst() == 46 && newTable[i].getsecond()  == 48 || newTable[i].getfirst() == 47 && newTable[i].getsecond()  == 45 || newTable[i].getfirst() == 47 && newTable[i].getsecond()  == 46 ||
			newTable[i].getfirst() == 47 && newTable[i].getsecond()  == 48 || newTable[i].getfirst() == 48 && newTable[i].getsecond()  == 45 || newTable[i].getfirst() == 48 && newTable[i].getsecond()  == 46 || newTable[i].getfirst() == 48 && newTable[i].getsecond()  == 47 || newTable[i].getfirst() == 49 && newTable[i].getsecond()  == 50 || newTable[i].getfirst() == 49 && newTable[i].getsecond()  == 51 || newTable[i].getfirst() == 49 && newTable[i].getsecond()  == 52 || newTable[i].getfirst() == 50 && newTable[i].getsecond()  == 49 || newTable[i].getfirst() == 50 && newTable[i].getsecond()  == 51 ||
			newTable[i].getfirst() == 50 && newTable[i].getsecond()  == 52 || newTable[i].getfirst() == 51 && newTable[i].getsecond()  == 49 || newTable[i].getfirst() == 51 && newTable[i].getsecond()  == 50 || newTable[i].getfirst() == 51 && newTable[i].getsecond()  == 52 || newTable[i].getfirst() == 52 && newTable[i].getsecond() == 49 || newTable[i].getfirst() == 52 && newTable[i].getsecond()  == 50 || newTable[i].getfirst() == 52 && newTable[i].getsecond()  == 51 
			) {

			pairs++;
		}
	}
	return pairs;
}

int main() {
	
	srand(time(0));

	cout << "how many players at the table ";

	cin >> numplayers;

	
	p = shuffle();
	
	while ( sumvector(p, 52) != 1378) {
		p = shuffle();
	}


	cout << sumvector(p, 52) <<endl;

	for (int i = 0; i < 52; i++) {
		cout << p[i] << endl;

	}

	vector<Player> Table;


	
	//printVector(Table);


	cout << pairs << endl;



	getchar();
	cin.get();
	return 0;
}






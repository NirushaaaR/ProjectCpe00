#include "GameSystem.h"
#include<ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv){

	srand(time(0));
	string myName;
	cout<<"Plese create your name : ";
	getline(cin,myName);


	string playAgain;
	do{	
		int playerNumber;
		string pn;
		do{
			cout<<"How many people you wanna Play?(2-5): ";
			getline(cin,pn);
		}while(pn<"2"||pn>"5");
		
		playerNumber =atoi(pn.c_str());
		
		GameSystem game(10);
		game.gamePlay(myName);
		
		cout<<"Do you want to play again (0 to Exit) : ";
		getline(cin,playAgain);
		
		
		
	}while( atoi(playAgain.c_str()) != 0);
	
	
	return 0;
	
}

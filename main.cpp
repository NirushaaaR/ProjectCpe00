#include "GameSystem.h"
#include<ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv){

	srand(time(0));
	
	
	bool playAgain=true;
	
	do{	
		GameSystem game(4);
		game.gamePlay();
		
		cout<<"Do you want to play again (0 = no,other = yes): ";
		cin>>playAgain;
		
	}while(playAgain);
	
	
	return 0;
	
}

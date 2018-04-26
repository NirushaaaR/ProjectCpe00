#include "Player.h"
#include<cstdlib>

class GameSystem{
	int turn;
	int playerNumber;
	vector<Player> allPlayer;
	
	public:
		GameSystem(int);
		int getRandomStarter(int);
		int chooseCard(Player &);
		int checkWinner(vector<Player>&);
		void showWinner(Player &);
		void showLoser(Player &);
		void dealCard(vector<Player> &);
		void pickACard(Player &,Player &,int);
		void discardAndShuffle(Player&);
		void waitAndClear();
		void drawScene(vector<Player>&,int);
		void drawSceneAndShowCard(Player &,Player &,int);
		void gamePlay();
		
};

GameSystem::GameSystem(int p=4){
	playerNumber = p;
}

void GameSystem::showWinner(Player &p) {
	if(p.tag != "player"){

		cout << "---------------------------------\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*       "<<p.name<<" WIN!!! \t\t*\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "---------------------------------\n";
		

	}else if(p.tag == "player"){
		cout << "---------------------------------\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*          YOU WIN!!!           *\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "*                               *\n";
		cout << "---------------------------------\n";
		
	}
}

void GameSystem::showLoser(Player &p) {
	cout << "---------------------------------\n";
	cout << "*                               *\n";
	cout << "*                               *\n";
	cout << "*                               *\n";
	cout << "*       "<< p.name << " Lose!!! \t\t*\n";
	cout << "*                               *\n";
	cout << "*                               *\n";
	cout << "*                               *\n";
	cout << "---------------------------------\n";
}

int GameSystem::checkWinner(vector<Player> &allPlayer){

	for (int i = 0;i < allPlayer.size();i++) {

		if (allPlayer[i].getHandSize() < 1) {
			return i+1;
		}
	}

	return 0;
}

int GameSystem::chooseCard(Player &p){
	string pick;
	int pickInInt;
	do{
		cout<<"pick card form opponent: ";
		getline(cin,pick);
		pickInInt = atoi(pick.c_str());
				
	}while(pickInInt<=0 || pickInInt>p.getHandSize());
			
	return pickInInt;
}

void GameSystem::drawScene(vector<Player> &allPlayer,int turn = 0){
	
	cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
	for(int i = 0;i<allPlayer.size();i++) {
		
		allPlayer[turn].showCard();
		turn = turn+1 >= allPlayer.size() ? 0 : turn +1;
	}
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
}

void GameSystem::drawSceneAndShowCard(Player &p1,Player &p2,int revealPos = 0){
	cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
	p1.showCard();
	p2.showCardInPos(revealPos);
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
}

void GameSystem::discardAndShuffle(Player &p){
	p.checkAndDiscard();
	p.shuffleHand();
}

void GameSystem::pickACard(Player &p1,Player &p2,int pickPos){
	
	drawSceneAndShowCard(p1,p2,pickPos);
	Card picked = p1.pickCard(p2,pickPos);
	cout<<"Pick "<<picked<<"\n";
	discardAndShuffle(p1);
	
}

void GameSystem::dealCard(vector<Player> &allPlayer){

	Deck mainDeck;

	for(int i=0; i< mainDeck.getSize() ;i++){
		
		allPlayer[i%playerNumber].addCard(mainDeck.getCard(i));
		
	}
	
	for(int i = 0;i<allPlayer.size();i++){
		allPlayer[i].checkAndDiscard();
	}
	
	
	
}

void GameSystem::waitAndClear(){
	
	system("pause");
	system("cls");
	
}


int GameSystem::getRandomStarter(int playerNumber){
	return rand()%playerNumber;
}

void GameSystem::gamePlay(){


	allPlayer.push_back(Player("Rick","player"));
	allPlayer.push_back(Player("Stanley"));
	allPlayer.push_back(Player("Parker"));
	allPlayer.push_back(Player("Kim"));
	
	
	dealCard(allPlayer);
	turn = getRandomStarter(playerNumber);
	
	system("cls");
	system("pause");
	cout<<"..............let's play.............\n";
	
	cout<<"Start with "<<playerNumber<<" player\n";

	
	cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
	int pick;

	while(true){

		int nextPeople = turn + 1 >= playerNumber ? 0 : turn + 1;
		cout << allPlayer[turn].name << " Turn...\n";
		drawScene(allPlayer,turn);

		if (allPlayer[turn].tag == "player") {

			pick = chooseCard(allPlayer[nextPeople]);
			system("pause");
			system("cls");

			pickACard(allPlayer[turn], allPlayer[nextPeople], pick - 1);

		}
		else {
			pick = rand() % allPlayer[nextPeople].getHandSize();
			system("pause");
			system("cls");
			cout << "\npick " << pick + 1 << " card\n";
			pickACard(allPlayer[turn], allPlayer[nextPeople], pick);
		}

		if(int winner = checkWinner(allPlayer)){
		
			showWinner(allPlayer[winner - 1]);
			if(allPlayer[winner - 1].tag == "player"){
				
				bool notStop = true;
				
				cout<<"Do you want to continue ?(0 = no,other = yes) : ";
				cin>>notStop;
				
				if(!notStop){
					return;
				}
			}
			playerNumber--;
			allPlayer.erase(allPlayer.begin() + winner - 1);
			turn--;
		}

		if (allPlayer.size() <= 1) {
			showLoser(allPlayer[0]);
			return;
		}
			
		turn = turn + 1 >= playerNumber ? 0 : turn + 1;
			
			
			
		cout<<"turn end...";
		cout<<"\n---------------------------------------------------\n";
		system("pause");
		system("cls");
			
		
	}
}

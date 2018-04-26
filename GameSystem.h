#include "Player.h"
#include<cstdlib>


string namebot[]={"Cherprang","Orn","Jennis","Noey","NamNeung","Kaew","Mobile","Music","Pun","Tommy","Mu","Karn",
"Tony","Parker","Max","Stark","Harry","T'challa","Peter","Sam","Snow","John","Elvis","Black","Toey","Mod","Shark"};


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
		void drawScene(vector<Player>&,int);
		void drawSceneAndShowCard(Player &,Player &,int);
		void gamePlay(string);
		
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
	cout<<p1.name<<" Pick "<<picked<<"\n";
	discardAndShuffle(p1);
	
}

void GameSystem::dealCard(vector<Player> &allPlayer){

	Deck mainDeck;

	for(int i=0; i< mainDeck.getSize() ;i++){
		
		allPlayer[i%allPlayer.size()].addCard(mainDeck.getCard(i));
		
	}
	
	for(int i = 0;i<allPlayer.size();i++){
		allPlayer[i].checkAndDiscard();
	}
	
	
	
}

int GameSystem::getRandomStarter(int playerNumber){
	return rand()%playerNumber;
}

void GameSystem::gamePlay(string playerName){

	
	allPlayer.push_back(Player(playerName,"player"));
	
	
	string name;
	for(int i = 0;i<playerNumber - 1;i++){
		
		int r = rand()%sizeof(namebot) / sizeof(namebot[0]);
		
		do{
			name = namebot[r];
			namebot[r] = "";
		}while(name=="");
		
		allPlayer.push_back(Player(name));
	}
	
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
			cout <<"\n"<<allPlayer[turn].name<<" pick card number " << pick + 1 << " from "<<allPlayer[nextPeople].name;
			pickACard(allPlayer[turn], allPlayer[nextPeople], pick);
		}

		if(int winner = checkWinner(allPlayer)){
		
			showWinner(allPlayer[winner - 1]);
			if(allPlayer[winner - 1].tag == "player"){
				
				string notStop;
				
				cout<<"Do you want to continue ?(0 to stop) : ";
				getline(cin,notStop);
					
				if(atoi(notStop.c_str()) == 0){
					return;
				}
			}
			playerNumber--;
			allPlayer.erase(allPlayer.begin() + winner - 1);
			turn--;
		}

		if (allPlayer.size() <= 1) {
			showLoser(allPlayer[0]);
			allPlayer.pop_back();
			return;
		}
			
		turn = turn + 1 >= playerNumber ? 0 : turn + 1;
			
			
			
		cout<<"turn end...";
		cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
		system("pause");
		system("cls");
			
		
	}
}

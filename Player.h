#include "CardSystem.h"

class Player{
	vector<Card> hand;

	public:
		string name;
		string tag;
		Player(string,string);
		Card pickCard(Player&,int );//pick card form opponent hand
		void addCard(Card);//add a card to your hand
		void checkAndDiscard();//change to game system
		void showCard();//show a card in your hand 
		void showCardInPos(int);
		void showCardPairs(int,int);
		void shuffleHand();//shuffle a card in your hand
		bool checkPairs(int &,int &);//check if there a pair in your hand
		int getHandSize();//return how much card left in player hand
		
		
};

Player::Player(string tname ,string ttag = "opponent"){
	name = tname;
	tag = ttag;
}

Card Player::pickCard(Player &anotherPlayer,int pick){
	Card tcard = anotherPlayer.hand[pick];
	hand.push_back(anotherPlayer.hand[pick]);
	anotherPlayer.hand.erase(anotherPlayer.hand.begin()+pick);
	return tcard;
}

bool Player::checkPairs(int &x,int &y){
	if(hand.size() == 0){
		return false;
	}
	
	for(int i =0;i<hand.size()-1;i++){
		
		for(int j = i+1;j<hand.size();j++){
			if(hand[i] == hand[j]){
				x=i;
				y=j;
				return true;
			}
			
		}
	}
	return false;
}

void Player::addCard(Card card){
	hand.push_back(card);
}

int Player::getHandSize(){
	return hand.size();
}

void Player::checkAndDiscard(){
	
	int x,y;
	
	if(!checkPairs(x,y)){
		showCardInPos(hand.size() - 1);
		return;
	}

	while(checkPairs(x,y)){
		showCardPairs(x,y);
		cout<<"discard "<<hand[x].face<<" pairs\n";
		hand.erase(hand.begin()+x);
		hand.erase(hand.begin()+y-1);	
	}
	

}

void Player::showCard(){
	cout<<name<<":\n";
	if(hand.size()==0){
		cout<<"no card on left\n";
		return;
	}


	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";
		
	/*for(int i =0;i<hand.size();i++){
		if(tag == "player"){
			cout<<"|"<<hand[i]<<"|\t";
		}
		else if(tag == "opponent"){
		
				cout<<"| * |"<<"\t";
		}
			
	}cout<<"\n";
	for(int i = 0;i<hand.size();i++){
		cout<<" ---"<<"\t";
	}cout<<"\n";*/
	for(int line =0;line<8;line++){
		
		for(int i =0;i<hand.size();i++){
			
			if(tag == "player")
				cout<<hand[i].art.getArtWork(hand[i].suit,hand[i].face,line)<<"\t";
			else
				cout<<hand[i].art.blankArt(line)<<"\t";
		}
		cout<<"\n";
	}
	
	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";
	
	cout<<"\n";
}

void Player::showCardPairs(int pos1,int pos2){
	cout<<name<<":\n";
	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";	
	/*for(int i =0;i<hand.size();i++){
		if(pos1 == i || pos2 == i){
			continue;
		}
		if(tag == "player"){
			cout<<"|"<<hand[i]<<"|\t";
		}
		else
			cout<<"| * |"<<"\t";
			
	}*/
	
	for(int line =0;line<8;line++){
		
		for(int i =0;i<hand.size();i++){
			
			if(tag == "player" || i == pos1 || i == pos2)
				cout<<hand[i].art.getArtWork(hand[i].suit,hand[i].face,line)<<"\t";
			else
				cout<<hand[i].art.blankArt(line)<<"\t";
		}
		cout<<"\n";
	}
	
	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";
	
	cout<<"\n";
}

void Player::showCardInPos(int pos){
	cout<<name<<":\n";

	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";	
	/*for(int i =0;i<hand.size();i++){
		if(tag == "player"){
			cout<<"|"<<hand[i]<<"|\t";
			
		}
		else if(tag == "opponent"){
			if(i == pos)
				cout<<"|"<<hand[i]<<"|\t";
			else 
				cout<<"| * |"<<"\t";
		}
			
	}cout<<"\n";*/
	
	for(int line =0;line<8;line++){
		
		for(int i =0;i<hand.size();i++){
			
			if(tag == "player" || i == pos)
				cout<<hand[i].art.getArtWork(hand[i].suit,hand[i].face,line)<<"\t";
			else
				
				cout<<hand[i].art.blankArt(line)<<"\t";
		}
		cout<<"\n";
	}
	
	
	for(int i = 0;i<hand.size();i++){
		cout<< " -------------\t";
	}cout<<"\n";
	
	cout<<"\n";
}


void Player::shuffleHand(){

	random_shuffle(hand.begin(),hand.end());
}



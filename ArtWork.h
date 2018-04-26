#include<string>
#include<iostream>

using namespace std;

string heart[] = {"|    \3   \3    |","|   \3\3\3 \3\3\3   |","|    \3\3\3\3\3    |","|     \3\3\3     |","|      \3      |"}; 
string diamond[] ={"|      \4\4     |","|     \4\4\4\4    |","|    \4\4\4\4\4\4   |","|    \4\4\4\4\4\4   |","|     \4\4\4\4    |","|      \4\4     |"};
string spade[] = {"|      \6\6     |","|     \6\6\6\6    |","|    \6\6\6\6\6\6   |","|    \6\6\6\6\6\6   |","|      \6\6     |","|    \6\6\6\6\6\6   |"};
string club[] = {"|      _      |","|     (_)     |","|   (_)_(_)   |","|     / \\     |","|    /___\\    |","|             |"};
string ace[] = {"|      x      |","|     xxx     |","|    xxxxx    |","|   xxx_xxx   |","|  xxx   xxx  |","| xxx     xxx |"};
string blank[]={"|             |","|             |","|             |","|      *      |","|             |","|             |","|             |","|             |"};
string jack[] = {"|     xxxx    |","|       x     |","|       x     |","|       x     |","|    x  x     |","|    xxxx     |"};
string queen[] = {"|     xxx     |","|   xx   xx   |","|  xx     xx  |","|  xx     xx  |","|   xx   xx   |","|     xxx  xx |"};
string king[] = {"|   xx   xx   |","|   xx  xx    |","|   xx xx     |","|   xx xx     |","|   xx  xx    |","|   xx   xx   |"};
string joker[]={"|           J |","|     xxxx  O |","|       x   K |","| J     x   E |","| O     x   R |","| K  x  x     |","| E  xxxx     |","| R           |"};

class ArtWork{
	
	public:
		string getArtWork(string suit,string face,int);
		string blankArt(int line);
		int getSize();
};

string ArtWork::getArtWork(string suit,string face,int line){
	
	if(suit == "Joker"){
		return joker[line];
	}
	
	if(line == 0){
		if(face == "10"){
			return "|          "+face+suit+"|";
		}else{
			return "|           "+face+suit+"|";
		}
	}else if(line == 7){
		if(face == "10"){
			return "|"+face+suit+"          |";
		}else{
			return "|"+face+suit+"           |";
		}
	}
	
	int arr = line - 1;
	
	if(face == "A"){
		return ace[arr];
	}else if(face == "J"){
		return jack[arr];
	}else if(face == "Q"){
		return queen[arr];
	}else if(face == "K"){
		return king[arr];
	}
	
	if(suit == "D")
		return	diamond[arr];
	else if(suit == "H")
		return heart[arr];
	else if(suit == "S")
		return spade[arr];
	else if(suit == "C")
		return club[arr];
	else{
		return "error";	
	}
}

string ArtWork::blankArt(int line){
	return blank[line]; 
}

int getSize(){
	return sizeof(joker)/sizeof(joker[0]);
}

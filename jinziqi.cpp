#include <iostream>
#include <windows.h>
#include <iostream>
#include <conio.h> 
#define DIRECTION_KEY 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;
void gotoxy(int x, int y)
{
COORD loc;
HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
loc.X = x;
loc.Y = y;
SetConsoleCursorPosition(hOuput,loc);
}
class Play{
	int map[3][3];
	int x,y;
	public:
		void player();
		void AI(int);
		void Draw();
		void Initial();
		void Checkwin();
};
void Play::Draw(){
	for(int i=1;i<=3;i++)cout<<"   |"<<endl;
	cout<<"----"<<endl;
}
void Play::player(){
	unsigned char key;
	int x=0,y=0,q=1;
	gotoxy(0,0);
	while(q){
		key = getch();
		switch(key)
		{
		case DIRECTION_KEY:
			switch(key = getch())
			{
				case UP:
					if(y>0)gotoxy(x,--y);
					break;
				case DOWN:
					if(y<2)gotoxy(x,++y);
					break;
				case LEFT:
					if(x>0)gotoxy(--x,y);
					break;
				case RIGHT:
					if(x<2)gotoxy(++x,y);
			}
			break;
			case 32:
				if(map[x][y]==0){
				gotoxy(x,y);
				cout<<"O";
				map[x][y]=1;
				q=0;
				}
				break;
		}
	}
	gotoxy(4,0);
	cout<<map[2][0]+map[1][1]+map[0][2];
}
void Play::AI(int n){
	if(n==1){
		if(map[1][1]!=1){
			gotoxy(1,1);
			cout<<"X";
			map[1][1]=20;
		}
		else{
			gotoxy(0,0);
			cout<<"X";
			map[0][0]=20;
		}
	}
	if(n==2){
		if(map[1][1]==1){
			if(map[2][2]==1||map[2][1]==1){
				gotoxy(2,0);
				cout<<"X";
				map[2][0]=1;
			}		
		}
	}
	if(n==3||n==4){
		if(map[0][0]+map[0][1]+map[0][2]==40){
			for(int i=0;i<3;i++){
				if(map[0][i]==0){
					gotoxy(0,i);
					cout<<"X";
					map[0][i]=20;
				}
			}
		}
		else if(map[1][0]+map[1][1]+map[1][2]==40){
			for(int i=0;i<3;i++){
				if(map[1][i]==0){
					gotoxy(1,i);
					cout<<"X";
					map[1][i]=20;
				}
			}
		}
		else if(map[2][0]+map[2][1]+map[2][2]==40){
			for(int i=0;i<3;i++){
				if(map[2][i]==0){
					gotoxy(2,i);
					cout<<"X";
					map[2][i]=20;
				}
			}
		}
		else if(map[0][0]+map[1][0]+map[2][0]==40){
			for(int i=0;i<3;i++){
				if(map[i][0]==0){
					gotoxy(i,0);
					cout<<"X";
					map[i][0]=20;
					
				}
			}
		}
		else if(map[0][1]+map[1][1]+map[2][1]==40){
			for(int i=0;i<3;i++){
				if(map[i][1]==0){
					gotoxy(i,1);
					cout<<"X";
					map[i][1]=20;
				}
			}
		}
		else if(map[0][2]+map[1][2]+map[2][2]==40){
			for(int i=0;i<3;i++){
				if(map[i][2]==0){
					gotoxy(i,2);
					cout<<"X";
					map[i][2]=20;
				}
			}
		}
		else if(map[0][0]+map[1][1]+map[2][2]==40){
			for(int i=0;i<3;i++){
				if(map[i][i]==0){
					gotoxy(i,i);
					cout<<"X";
					map[i][i]=20;
				}
			}
		}
		else if(map[2][0]+map[1][1]+map[0][2]==40){
			for(int i=0,j=2;i<3,j>=0;i++,j--){
				if(map[j][i]==0){
					gotoxy(j,i);
					cout<<"X";
					map[j][i]=20;
				}
			}
		}
		else if(map[0][0]+map[0][1]+map[0][2]==2){
			for(int i=0;i<3;i++){
				if(map[0][i]==0){
					gotoxy(0,i);
					cout<<"X";
					map[0][i]=20;
				}
			}
		}
		else if(map[1][0]+map[1][1]+map[1][2]==2){
			for(int i=0;i<3;i++){
				if(map[1][i]==0){
					gotoxy(1,i);
					cout<<"X";
					map[1][i]=20;
				}
			}
		}
		else if(map[2][0]+map[2][1]+map[2][2]==2){
			for(int i=0;i<3;i++){
				if(map[2][i]==0){
					gotoxy(2,i);
					cout<<"X";
					map[2][i]=20;
				}
			}
		}
		else if(map[0][0]+map[1][0]+map[2][0]==2){
			for(int i=0;i<3;i++){
				if(map[i][0]==0){
					gotoxy(i,0);
					cout<<"X";
					map[i][0]=20;
					
				}
			}
		}
		else if(map[0][1]+map[1][1]+map[2][1]==2){
			for(int i=0;i<3;i++){
				if(map[i][1]==0){
					gotoxy(i,1);
					cout<<"X";
					map[i][1]=20;
				}
			}
		}
		else if(map[0][2]+map[1][2]+map[2][2]==2){
			for(int i=0;i<3;i++){
				if(map[i][2]==0){
					gotoxy(i,2);
					cout<<"X";
					map[i][2]=20;
				}
			}
		}
		else if(map[0][0]+map[1][1]+map[2][2]==2){
			for(int i=0;i<3;i++){
				if(map[i][i]==0){
					gotoxy(i,i);
					cout<<"X";
					map[i][i]=20;
				}
			}
		}
		else if(map[2][0]+map[1][1]+map[0][2]==2){
			for(int i=0,j=2;i<3,j>=0;i++,j--){
				if(map[j][i]==0){
					gotoxy(j,i);
					cout<<"X";
					map[j][i]=20;
				}
			}
		}
		else if(map[0][0]+map[0][1]+map[0][2]==1){
			for(int i=0;i<3;i++){
				if(map[0][i]==0){
					gotoxy(0,i);
					cout<<"X";
					map[0][i]=20;
					break;
				}
			}
		}
		else if(map[1][0]+map[1][1]+map[1][2]==1){
			for(int i=0;i<3;i++){
				if(map[1][i]==0){
					gotoxy(1,i);
					cout<<"X";
					map[1][i]=20;
					break;
				}
			}
		}
		else if(map[2][0]+map[2][1]+map[2][2]==1){
			for(int i=0;i<3;i++){
				if(map[2][i]==0){
					gotoxy(2,i);
					cout<<"X";
					map[2][i]=20;
					break;
				}
			}
		}
		else if(map[0][0]+map[1][0]+map[2][0]==1){
			for(int i=0;i<3;i++){
				if(map[i][0]==0){
					gotoxy(i,0);
					cout<<"X";
					map[i][0]=20;
					break;
				}
			}
		}
		else if(map[0][1]+map[1][1]+map[2][1]==1){
			for(int i=0;i<3;i++){
				if(map[i][1]==0){
					gotoxy(i,1);
					cout<<"X";
					map[i][1]=20;
					break;
				}
			}
		}
		else if(map[0][2]+map[1][2]+map[2][2]==1){
			for(int i=0;i<3;i++){
				if(map[i][2]==0){
					gotoxy(i,2);
					cout<<"X";
					map[i][2]=20;
					break;
				}
			}
		}
		else if(map[0][0]+map[1][1]+map[2][2]==1){
			for(int i=0;i<3;i++){
				if(map[i][i]==0){
					gotoxy(i,i);
					cout<<"X";
					map[i][i]=20;
					break;
				}
			}
		}
		else if(map[2][0]+map[1][1]+map[0][2]==1){
			for(int i=0,j=2;i<3,j>=0;i++,j--){
				if(map[j][i]==0){
					gotoxy(j,i);
					cout<<"X";
					map[j][i]=20;
					break;
				}
			}
		}
	} 
}
void Play::Initial(){
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
			map[x][y]=0;
		}
	}
}
void Play::Checkwin(){
	if((map[0][0]+map[0][1]+map[0][2]==3)||(map[1][0]+map[1][1]+map[1][2]==3)||(map[2][0]+map[2][1]+map[2][2]==3)||(map[0][0]+map[1][0]+map[2][0]==3)||(map[0][1]+map[1][1]+map[2][1]==3)||(map[0][2]+map[1][2]+map[0][2]==3)||(map[0][0]+map[1][1]+map[2][2]==3)||(map[2][0]+map[1][1]+map[0][2]==3))
	{
		cout<<"you win"<<endl;
		exit(1);
	}
	else if((map[0][0]+map[0][1]+map[0][2]==60)||(map[1][0]+map[1][1]+map[1][2]==60)||(map[2][0]+map[2][1]+map[2][2]==60)||(map[0][0]+map[1][0]+map[2][0]==60)||(map[0][1]+map[1][1]+map[2][1]==60)||(map[0][2]+map[1][2]+map[0][2]==60)||(map[0][0]+map[1][1]+map[2][2]==60)||(map[2][0]+map[1][1]+map[0][2]==60))
	{
		gotoxy(0,4);
		cout<<"computer win"<<endl;
		exit(1);
	}
}
int main()
{
	Play game;
	game.Draw();
	game.Initial();
	game.player();
	game.AI(1);
	game.player();
	game.AI(2);
	game.player();
	game.Checkwin();
	game.AI(3);
	game.Checkwin();
	game.player();
	game.Checkwin();
	game.AI(4);
	game.Checkwin();
	game.player();
	game.Checkwin();
	return 0;
}

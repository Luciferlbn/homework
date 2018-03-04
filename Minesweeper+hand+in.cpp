#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define KEY 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;
void gotoxy(int x, int y) {   
	COORD loc;       
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);   
	loc.X = x;    
	loc.Y = y;   
	SetConsoleCursorPosition(hOuput,loc); 
} 
void Drawmap(int,int);
void Drawmap(int sizex,int sizey){
	for(int i=1;i<=sizex+1;i++){
		cout<<"=";
    }
    cout<<endl;
		for(int i=1;i<=sizey;i++){
		    for(int j=1;j<=sizex;j++){
			    cout<<" ";
		}
			cout<<"||"<<endl;
	}
	for(int i=1;i<=sizex+1;i++){
		cout<<"=";
    }
}
int Map(int,int,int);
int Map(int axis[100][100],int x1,int y1){
	int j=0;
	if(axis[x1][y1]!=9){
		for(int i=0;i<3;i++){
			if(axis[x1-1+i][y1-1]==9){
				j++;
			}
		}
		if(axis[x1-1][y1]==9){
				j++;
		}
		if(axis[x1+1][y1]==9){
				j++;
		}
		for(int i=0;i<3;i++){
			if(axis[x1-1+i][y1+1]==9){
					j++;
			}
		}
		return j;
	}
	else
		return 9;	
}
void Open(int,int,int,int,int,int,int);
void Open(int axis[100][100],int check[100][100],int map[100][100],int sizex,int sizey,int x,int y){
	if((x<0)||(y<=9)||(x>=sizex)||(y>sizey+9))return; 
	if(check[x][y]!=0)return;
	map[x][y]=Map(axis,x,y);
	if((check[x][y]==0)&&(map[x][y]==0)) {
		gotoxy(x,y);
		check[x][y]=1;
		cout<<map[x][y];
		Open(axis,check,map,sizex,sizey,x-1,y);
		Open(axis,check,map,sizex,sizey,x+1,y);
		Open(axis,check,map,sizex,sizey,x,y-1);
		Open(axis,check,map,sizex,sizey,x,y+1);
	}
	if((check[x][y]==0)&&(map[x][y]!=0)) {
		gotoxy(x,y);
		cout<<map[x][y];
		check[x][y]=1;
		return;
	}
}
int Checkfail(int,int,int,int,int,int,int);
int Checkfail(int k,int l,int sizex,int sizey,int axis[100][100],int flag[100][100]){
	int n=0; 
	for(k=0;k<=sizey;k++){
		for(l=0;l<=sizex;l++){
				if((axis[l][k]==flag[l][k])&&(axis[l][k]==9))continue;
				if((axis[l][k]!=flag[l][k])&&((axis[l][k]==9)&&(flag[l][k]!=9))){
					gotoxy(0,16+sizey);	
					n++;
				}
				else if((axis[l][k]!=flag[l][k])&&((axis[l][k]!=9)&&(flag[l][k]==9))){
					gotoxy(0,16+sizey);
					n++;	
				}		
		}
	}
	return n;
}
int main()
{
	int sizex,sizey,number,i,j,x,y,axis[100][100],judge[100][100],map[100][100],checksucess,check[100][100],flag[100][100]={{0}},x1,y1,n=0,k,l,pd;
	unsigned char key;
		cout<<"The Minesweeper game is start !"<<endl;
		cout<<"Press f to flag or unflag !"<<endl;
		cout<<"Press q to unsure , and c to check sucess!"<<endl;
		cout<<"please input the size of map you want to play x:";
		cin>>sizex;
		cout<<"please input the size of map you want to play y:";
		cin>>sizey;
		cout<<"please input the number of mines you want :";
		cin>>number;
		cout<<"now let's start!"<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		x=0;
		y=10;
		Drawmap(sizex,sizey);
		srand(time(NULL));
		for(int i=1;i<=number;)
		{
			int x1=rand()%sizex, y1=rand()%sizey;
			if(judge[x1][y1]==9) continue;
			axis[x1][y1]=9;	
			judge[x1][y1]=axis[x1][y1];
			map[x1][y1]=9;
			i++;
		}
		gotoxy(0,16+sizey);
			for(int l=0;l<sizey;l++){
				for(int k=0;k<sizex;k++){
					map[k][l]=Map(axis,k,l);
					cout<<map[k][l];
				}
				cout<<endl;
			}
	Label1:	gotoxy(0,10);
		do{
			key=getch();
			switch(key)
			{
				case 224:
				switch(key=getch())
				{
					case 75:
						if(x>=1) gotoxy(--x,y);
						checksucess=1;
						break;
					case 77:
						if(x<sizex-1)gotoxy(++x,y);
						checksucess=1;
						break;
					case 72:
						if(y>=11) gotoxy(x,--y);
						checksucess=1;
						break;
					case 80:
						if(y<sizey+9)gotoxy(x,++y);
						checksucess=1;
						break;
				}
					break;
				case 70:
				case 102:
					if(flag[x][y]!=9&&check[x][y]==0){
						cout<<"f";
						flag[x][y]=9;
						check[x][y]=1;
						checksucess=1;
						gotoxy(x,y);
					}
					else if(flag[x][y]==9){
						cout<<" ";
						flag[x][y]=0;
						check[x][y]=0;
						checksucess=1;
						gotoxy(x,y);
					}
					break;
				case 32:
						Open(axis,check,map,sizex,sizey,x,y);
						if(axis[x][y]==9){
							gotoxy(x,y);
							cout<<"*";
							checksucess=-1;
						}
							else 
								checksucess=1;
					break;
				case 81:
				case 113:
					if(check[x][y]==0||flag[x][y]==9)
					cout<<"?";
					gotoxy(x,y);
					checksucess=1;	
					break;
				case 67:
				case 99: 
				checksucess=0;
				break;
				default:
				checksucess=1;
				break;	
			}	
		}while(checksucess==1);
		if(checksucess==-1){
			gotoxy(0,14+sizey);
			cout<<"you failed!"<<endl;
		}	
		if(checksucess==0){
			gotoxy(0,13+sizey);
			cout<<"do you want to check your result?(PRESS Y/N)";
			key=getch();
			switch(key)
			{
				case 89:
				case 121:
				pd=Checkfail(k,l,sizex,sizey,axis,flag);
				gotoxy(0,14+sizey);
				if(!pd){
					cout<<"you win!"<<endl;
				}
					else
						cout<<"you failed!"<<endl;
					break;
				case 78:
				case 110:
					checksucess=1;
					goto Label1;
					break; 
			}
		}
	void getch();
	cout<<"the copyright belongs to Lucifer.L"<<endl; 
	return 0;
}

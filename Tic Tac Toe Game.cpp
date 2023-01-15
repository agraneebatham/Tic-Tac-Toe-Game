#include<iostream> //for game over a.player 1 or 2 wins  b=game playing(not all boxes are filled)  c=game tie
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
	bool draw=false;
void display_board()
{
	system("cls");//clears the previous screen
	cout<<"\n\t\tTIC TAC TOE GAME"<<endl;
	cout<<"\t\tPlayer 1[X]"<<endl;
	cout<<"\t\tPlayer 2[O]"<<endl;
	cout<<endl;
	//displaying the board
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
	cout<<"\t\t     |     |     "<<endl;
}
void player_turn()
{
	int choice;
	if(turn=='X')
	{
		cout<<"\n\tPlayer 1[X] turn:";
	}
	if(turn=='O')
	{
		cout<<"\n\tPlayer 2[O] turn:";
	}
	cin>>choice;
	switch(choice)
	{
		case 1:row=0,column=0;
		       break;
		case 2:row=0,column=1;
		       break;	          
		case 3:row=0,column=2;
		       break;
		case 4:row=1,column=0;
		       break;
		case 5:row=1,column=1;
		       break;
		case 6:row=1,column=2;
		       break;
		case 7:row=2,column=0;
		       break;
		case 8:row=2,column=1;
		       break;
		case 9:row=2,column=2;
		       break;
		default:cout<<"Invalid choice"<<endl;
		        break;   	   	   	   	   	          
	}
	if(turn=='X'&&board[row][column]!='X'&& board[row][column]!='O') //agar player x ki turn hai ar box me already x ya o nhi pada hai to ye execute krega
	{
		board[row][column]='X';
		turn='O';
	}
	else if(turn=='O'&&board[row][column]!='X'&&board[row][column]!='O')
	{
		board[row][column]='O';
		turn='X';
	}
	else
	{
		cout<<"BOX ALREADY FILLED!"<<endl;
		cout<<"PLEASE TRY AGAIN"<<endl;
		player_turn();
	}
		display_board();
}
bool gameover()
{

	//check win in rows and columns
	for(int i=0;i<3;i++)
	{
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i] )
		{
			return false; //if game is over return false
		}
	}
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] ||  board[0][2]==board[1][1] && board[0][2]==board[2][0])
	return false;
	
	//if there is any box not filled
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X' && board[i][j]!='O')
			return true;//if game is not over return true
		}
	}
	
	//game draw
	draw=true;
	return false;
}
int main()
{
	while(gameover())//true ayega yaha to game chlti rhegi loop chlta rhega
	{
	  display_board();
	  player_turn();
	  gameover();
	}
	if(turn=='X' && draw==false)
	{
		cout<<"PLAYER 2[O] WINS!!CONGRATULATIONS"<<endl;
	}
	else if(turn=='O' && draw==false)
	{
		cout<<"PLAYER 1[X] WINS!!CONGRATULATIONS"<<endl;
	}
	else
	{
		cout<<"GAME IS DRAW !! NO ONE WINS\n";
	}
	return 0;
}
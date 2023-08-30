#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,col;
bool draw = false;

void displayBoard(){
    system("cls");
    cout<<"\n\n            T I C   T A C   T O E     "<<endl;
    cout<<endl;
    cout<<"Player1 [X]"<<endl;
    cout<<"Player2 [O]";

    cout<<"\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t     |     |     "<<endl;
}

void playerChoice(){
    int choice;
    if(turn=='X'){
        cout<<"\nPlayer1 [X] turn:\n"<<endl;
    }
    if(turn=='O'){
        cout<<"\nPlayer2 [O] turn:\n"<<endl;
    }
    cin>>choice;

    switch (choice)
    {
    case 1:row=0,col=0;break;
    case 2:row=0,col=1;break;
    case 3:row=0,col=2;break;
    case 4:row=1,col=0;break;
    case 5:row=1,col=1;break;
    case 6:row=1,col=2;break;
    case 7:row=2,col=0;break;
    case 8:row=2,col=1;break;
    case 9:row=2,col=2;break;
    default:
        cout<<"Invalid Choice"<<endl;
        break;
    }
    if(turn == 'X' && board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]='X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]='O';
        turn = 'X';
    }
    else{
        cout<<"Box already filled !! \n Please try another place"<<endl;
        playerChoice();
    }
    displayBoard();
}

bool gameOver(){
    //Check whether Win
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i]){
            return false;}
    }
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
            return false;
    }
    if(board[0][2]==board[1][1] && board[2][0]==board[1][1]){
            return false;
    }

    //if any box is not filled
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(board[i][j]!='X' && board[i][j]!='O')
            return true;

    //Game Draw
    draw=true;
    return false;
}

int main(){
    //For keep the program running we used while
    while(gameOver()){
    displayBoard(); 
    playerChoice();
    gameOver();
    }

    if(turn=='X' && draw == false){
        cout<<"\n Congratulations!! Player 2 Wins\n"<<endl;
    }
    else if(turn=='O' && draw == false){
        cout<<"\n Congratulations!! Player 1 Wins\n"<<endl;
    }
    else{
        cout<<"Game Drawn !!\n"<<endl;
    }

}
/* Elchin Mamedaliev
Tic-tac-toe
*/
#include <iostream>
using namespace std;
void boardDisplay(int [][3], int );
bool checkWin(int [][3]);
bool checkElement(int [][3], int , int);

int main()
{
int again = 0;
int board[3][3]={   {0,0,0},// initial board
                    {0,0,0},
                    {0,0,0}};
//This part executed once
string player1,player2;
do{
cout<<"Enter the name of player 1"<<endl;
cin>>player1;
cout<<"Enter the name of player 2"<<endl;
cin>>player2;
cout<< " In this game 1 represents 'X' and 2 represents 'O'"<<endl;

string winner;
int turnCount=0;
int x,y;

boardDisplay(board,3);
cout<<endl;

for(int i = 0; i<9; i++){
turnCount++;
cout<<"Turn number: "<<turnCount<<endl;//display each turn each time

do// while usere enters incorrect number he asked to re-input
{
cout<< player1<<": "<<"Enter Row. Ex.- 1,2,3."<<endl;
cin>>x;
x-=1;
cout<< player1<<": "<<"Enter Column. Ex.- 1,2,3."<<endl;
cin>>y;
y-=1;
}while (!checkElement(board,x,y));
board[x][y]=1; // assign 1 to the element of array . Represents 'X'

boardDisplay(board,3);// every time board upgraded it will be displayed

if (!checkWin(board)) // if after first users input we didn't find him as a winner we let second user play
{
if(turnCount!=9)// once turn reaches 9th and there is no winner game stoppes
{
turnCount++;
cout<<"Turn number: "<<turnCount<<endl; //display each turn each time

do
{

cout<< player2<<": "<<"Enter Row. Ex.- 1,2,3."<<endl;
cin>>x;
x-=1;
cout<< player2<<": "<<"Enter Column. Ex.- 1,2,3."<<endl;
cin>>y;
y-=1;
}while (!checkElement(board,x,y));

board[x][y]=2;// assign 2 , represents 'O'.

boardDisplay(board,3);

if(checkWin(board))
{
winner=player2;
cout<<"Winner: "<<winner<<endl;
break;
}
}
else{

cout<<"Draw"<<endl;
break;
}
}
else{
winner=player1;
cout<<"Winner: "<<winner<<endl;
break;
}

}
for(int i = 0; i<3; i++)
for(int j = 0; j<3; j++)
board[i][j]=0;

cout<<"If you want to play again enter 1.";
cin>>again;

}
while (again==1);


return 0;
}


void boardDisplay(int arr[][3], int size)
{
for(int i = 0; i<3;i++){
for(int j = 0; j<3;j++)
cout<<arr[i][j]<<"    ";
cout<<endl;
}
}

bool checkElement(int arr[][3],int x, int y) //function checks the correct input
{

if(x<0 || x>2 || y<0 || y>2)
{
cout<<"Please enter the correct coordinate, 0,1,2"<<endl;
return false;
}

if(arr[x][y]==0 ) // need to reask user for input if slot is already assign some value
{
return true;
}
cout<<"Slot is busy"<<endl;
return false;
}


bool checkWin(int arr[][3]){ // function checking the winner
bool win = false;
int count=0;
int nuli=0;

int x;
int y;



for(int r = 0; r<2; r++) // this for loop checks columns once r = 1
{

for(int i = 0; i<3; i++) // while r = 0 we check the row
{
for(int j = 0; j<3; j++)
{
if(r==1) // key moment where cheching goes over columns
{
x=j;
y=i;
}

else
{
x=i;
y=j;
}
if(arr[x][y]==1) count++;
else if(arr[x][y]==2) nuli++;
else break;
}
if(count==3 || nuli==3){
win=true;
break;
}
count = 0;
nuli = 0;
}

}
// null values to check for diogonal
int cntD = 0;
int nuliD = 0;

for(int i = 0; i<3; i++){ // loop cheching diogonal left to right
if(arr[i][i]==1) cntD++;
else if(arr[i][i]==2) nuliD++;
else break;

if(cntD==3 || nuliD==3){
win=true;

break;
}

}
cntD = 0;
nuliD = 0;

for(int i = 0; i<3; i++){ // loop cheching diogonal right to left
if(arr[i][2-i]==1) cntD++;
else if(arr[i][2-i]==2) nuliD++;
else break;
if(cntD==3 || nuliD==3){
win=true;

break;
}

}
cntD = 0;
nuliD = 0;
return win;
}

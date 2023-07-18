#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool validOrNot= true;

void swaping(int B[][10], int a,int b,int c,int d)
{ 
    B[a][b]=B[c][d];
    B[c][d]=0;
}

void randomize(int var[], int n)
{
    int temp=0;
    int randomIndex=0;
    srand(time(NULL));
    for(int i=0; i<n*n; i++){
        randomIndex= rand()%(n*n);
        temp=var[i];
        var[i]=var[randomIndex];
        var[randomIndex]=temp;
    }
}

bool correct(int B[][10], int n)
{
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(B[i][j]!= num){
                if(i==n-1 && j==n-1) return true;
                else return false;
            }
            else num++;
        }
    }
    return true;
}

bool valid(int n, int a, int b, char input)
{
    bool check=true;
    if(input!='a' && input!='w' && input!='s' && input!='d') check=false;
    if(b==n-1 && input=='d') check=false;
    if(a==n-1 && input=='s') check=false;
    if(b==0 && input=='a') check= false;
    if(a==0 && input=='w') check= false;
    return check;
}

void display(int B[][10], int n)
{
    system("cls");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(B[i][j]==0) cout<<"    ";
            else if(B[i][j]/10==0) cout<<" "<<B[i][j]<<"  ";
            else cout<<B[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void functionality(int B[][10], char input, int n, int *addmoves)
{
    int x,y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(B[i][j]==0){
                x=i;
                y=j;
                break;
            }
        }
    }
    if(valid(n,x,y,input)==true){
        if(input=='w'){
            swaping(B,x,y,x-1,y);
        }
        if(input=='a'){
            swaping(B,x,y,x,y-1);
        }
        if(input=='s'){
            swaping(B,x,y,x+1,y);
        }
        if(input=='d'){
            swaping(B,x,y,x,y+1);
        }
        (*addmoves)++;
        validOrNot=true;
    }
    else {
        validOrNot=false;
    }
}


int main()
{   
    system("cls");
    cout<<"Welcome to Arrange Puzzle Game..\n_________________\n\n";
    cout<<"Instructions:- \n";
    cout<<"First enter the size of grid you want to play from 1 to 9..\n";
    cout<<"Use w,a,s,d keys to navigate the 'space button'-\n";
    cout<<"w to move top, a to move left, s to move down and d to move right..\n\n";
    cout<<"Arrange the grid in ascending order of numbers with space button at the last to win...\n\n";
    cout<<"Enter the grid size:- ";
    int n;
    cin>>n;
    int B[10][10];
    int var[100];
    int temp= 1;
    for(int i=0; i<n*n; i++){
        var[i]=temp;
        temp++;
    }
    randomize(var,n);
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j]=var[k];
            k++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(B[i][j]== n*n){
                B[i][j]=0;
            }
        }
    }
    int moves=0;
    int* addmoves=&moves;

    display(B,n);
    while(correct(B,n)==false)
    {
        char input;
        cin>>input;
        functionality(B,input,n,addmoves);
        display(B,n);
        cout<<"\nNumber of Moves= "<<moves<<endl;;
        if(validOrNot==false) cout<<"\nInvalid Move.."<<endl;
    }
    
    if(correct(B,n)==true){
        cout<<"\nYou Won in "<<moves<<" moves..."<<endl;
    }

    return 0;
}
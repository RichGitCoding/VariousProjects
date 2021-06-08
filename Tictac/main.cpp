#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;
char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';

void Draw()//creates 3x3 grid
{
    system("cls");//clear window
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

char win()
{
    //using for loop, check each row for 3 in a row, and then check the columns
    int isTrue = 0;
    //for rows: X
    for(int i = 0; i < 3; i++)
    {
        isTrue = 0;//reset for each row

        for(int j = 0; j < 3; j++)
        {
            if( matrix[i][j] == 'X')
                isTrue++;

            if(isTrue == 0)
                break; // break will only exit the innermost loop

            if(isTrue == 3)
                return 'X';
        }
    }

    //for columns: X
    for(int i = 0; i < 3; i++)
    {
        isTrue = 0;//reset for each column

        for(int j = 0; j < 3; j++)
        {
            if( matrix[j][i] == 'X')
                isTrue++;

            if(isTrue == 0)
                break; // break will only exit the innermost loop when there is no use checking other values
            if(isTrue == 3)
                return 'X';
        }
    }

    //for rows: O
    for(int i = 0; i < 3; i++)
    {
        isTrue = 0;//reset for each row

        for(int j = 0; j < 3; j++)
        {
            if( matrix[i][j] == 'O')
                isTrue++;

            if(isTrue == 0)
                break; // break will only exit the innermost loop

            if(isTrue == 3)
                return 'O';
        }
    }

    //for columns: O
    for(int i = 0; i < 3; i++)
    {
        isTrue = 0;//reset for each column

        for(int j = 0; j < 3; j++)
        {
            if( matrix[j][i] == 'O')
                isTrue++;

            if(isTrue == 0)
                break; // break will only exit the innermost loop when there is no use checking other values
            if(isTrue == 3)
                return 'O';
        }
    }

    isTrue = 0;

    //diagonals
    if( matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    else if( matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        return 'X';
    else if( matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    else if( matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        return 'O';


return '\0';


}

void Input()
{   
    int input;//input for user
    cout<< "Press the number of the field:";
    cin>>input;


    if(input ==1)
    {
        matrix[0][0] = player; //prints into the first slot
    }

    else if(input ==2)
    {
        matrix[0][1] = player; //prints into the first slot
    }

    else if(input ==3)
    {
        matrix[0][2] = player; //prints into the first slot
    }

    else if(input ==4)
    {
        matrix[1][0] = player; //prints into the first slot
    }
    else if(input ==5)
    {
        matrix[1][1] = player; //prints into the first slot
    }
    else if(input ==6)
    {
        matrix[1][2] = player; //prints into the first slot
    }
    else if(input ==7)
    {
        matrix[2][0] = player; //prints into the first slot
    }
    else if(input ==8)
    {
        matrix[2][1] = player; //prints into the first slot
    }
    else if(input ==9)
    {
        matrix[2][2] = player; //prints into the first slot
    }


}

void togglePlayer()//chooses between players
{
if(player == 'X')
{
    player = 'O';
}
else
{
    player = 'X';
}

}

int main()
{   //can check all possiblities because we know how many possibilities there are
    char winner;
    Draw();
    int end = 0;

    while(1)
    {
        end++;
        Input();
        Draw();
        togglePlayer();
        winner = win();
        if(winner != '\0')
            break;
        if(end == 8)
        {
            cout<<"There is no winner."<<endl;
            exit(0);
        }
       
    }

    cout<<"The winner is: "<<winner<<endl;


    system("pause");
    return 0;
}
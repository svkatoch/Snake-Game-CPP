
#include <iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>


#include "Snake.h"
#include "Food.h"


#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2,HEIGHT/2},1);
Food food;
int score=0;


void board()
{
    COORD snake_pos =snake.get_pos();
    COORD food_pos= food.get_pos();

    vector<COORD> snake_body=snake.get_body();

    cout<<"SCORE : "<<score<<"\n\n\n";
    for(int i=0;i<HEIGHT;i++)
    {
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1) cout<<"#";
            else if(i==snake_pos.Y && j+1==snake_pos.X) cout<<"0";
            else if(i==food_pos.Y && j+1== food_pos.X) cout<<'@';

            else{
                bool isbodyPart = false;
                for(int k=0;k<snake_body.size()-1;k++)
                {
                    if(i== snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout<<'o';
                        isbodyPart = true;
                        break;
                    }
                }
                if(!isbodyPart) cout<<' ';
            }
        }
        cout<<"#\n";
    }
}
int main()
{

    srand(time(NULL));
    food.gen_food();
    bool game_over = false;
    while(!game_over)
    {
        board();

        if(kbhit())
        {
            switch(getch())
            {
                case 'w':snake.change_dir('u'); break;
                case 'a':snake.change_dir('l'); break;
                case 's':snake.change_dir('d'); break;
                case 'd':snake.change_dir('r'); break;
            }
        }
         if(snake.collided()) game_over= true;
        if (snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score++;

        }

        snake.move_snake();


        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});

    }
}

#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include<vector>
using namespace std;

#define WIDTH 50
#define HEIGHT 25


class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;
        vector<COORD> body;
    public:
        Snake(COORD pos,int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();
        vector<COORD> get_body();

        bool eaten(COORD food_pos);
        void grow();
        bool collided();
};

#endif // SNAKE_H

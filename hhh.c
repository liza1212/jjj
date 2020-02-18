#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <dos.h>


    int height=60,width=40;
    int dir_p=0;
    int pause=0;
    int change;
    int gameover=0;
    typedef struct ball
    {
      float x,y;
      float last_x;
      float last_y;
    };

    typedef struct brick
    {
        int stable;
        int x,y;
        int last_x,last_y;
    };
    typedef struct paddle
    {
        int x,y;
        int last_x,last_y;
    };
    void gotoxy(short x, short y)
    {
        COORD pos={x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
    void input()
    {
        if (_kbhit())
        {
            switch(getch())
            {
        case 'a':
            change=-1;
            break;
        case 'd':
            change=1;
            break;
        case 'p':
            pause=1;
            break;
        case 'x':
            gameover=1;
            break;
        default:
            change=0;
            break;
        }
    }
    }
    /*void draw_bricks()
    {
        int i;
        for (i=1;i<=75;i++)
        {
            if ()
        }
    }*/
    void draw_border()
    {
        int i,j;
        gotoxy(1,1);
        for (i=1;i<=width+25+25;i++)
        {
            if(i==1)
                printf ("%c",201);
            else if(i==(width+50))
                printf ("%c",187);
            else if ( i==25+width-1)
                printf("%c",201);
            else
                printf ("%c",205);

        }
        for (j=2;j<=height-1;j++)
        {
            gotoxy(1,j);
            for (i=1;i<=(width+25+25);i++)
            {
                if (i==1 || (i==25+width-1) ||i==(width+50))
                    printf ("%c",186);
                else
                    printf (" ");
            }
            printf ("\n");
        }
        gotoxy(1,height);
        for (i=1;i<=(width+25+25);i++)
        {
           if (i==1) printf("%c",200);
           else if(i==(width+25+25)) printf ("%c",188);
         //  else if( i==25+width-1) printf ("%c",202);
           else printf("%c",205);
        }
    }
    void fullscreen()
    {
        keybd_event(VK_MENU,0x38,0,0);
        keybd_event(VK_RETURN,0x1c,0,0);
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    }
    void move_paddle(struct paddle *paddle)//[], struct paddle *paddle_left, struct paddle *paddle_right)
    {
        gotoxy(paddle->last_x,paddle->last_y);
        printf("     ");
        gotoxy(paddle->x,paddle->y);
        printf("%c%c%c%c%c",205,205,205,205,205);
        gotoxy(1,26);

    }
    void draw_brick(struct brick brick[])
    {
        int i;
        for (i=1;i<=75;i++)
        {
            if (brick[i].y<height)
            {
              gotoxy(brick[i].last_x,brick[i].last_y);
            printf(" ");
            }
            if (brick[i].stable!=0)
                {
            gotoxy(brick[i].x,brick[i].y);
            printf("%c",178);
                }
        }
    }

void main()
{
    int i,j;
    struct paddle paddle;
    struct ball ball[100];
    struct brick brick[100];
    struct paddle paddle_left;
    struct paddle paddle_right;
    char replay;
    fullscreen();
    draw_border();

    //move_paddle(&paddle);
    //draw_brick(brick);
    //yay_ball(ball);
    paddle.x=40;
    paddle.y=height-1;
    pause=0;
   // if (ending==1)
     //   goto end;
    fflush(stdin);
    while(!gameover)
    {
        input();
        fflush(stdin);
        move_paddle(&paddle);
        draw_brick(brick);
       if(paddle.x>26 || change!= -1)
            {
                if(paddle.x < (25+ width - 2) || change!=1 )
                {


                    paddle.last_x=paddle.x;   //save last position clean screen at the point ; refer to void draw_player();
                    paddle.x += change;     //update to new position according to input(); from user
                    change=0;               //reset move direction
                }
            }

    }

    }


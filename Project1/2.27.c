#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int foodx, foody;
int length=0;

void draw( int snakex[], int snakey[])
{
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 19){
                printf("#");
            }
            else if (i == foodx && j == foody) {
                printf("*");
            }
            else if (i == snakex[0] && j == snakey[0]) {
                printf("O");
            }
            else {
                int p = 0;
                for (int k = 1; k < length; k++) {
                    if (i == snakex[k] && j == snakey[k]) {
                        printf("o");
                        p= 1;
                        break;
                    }
                }
                if (p == 0)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void move(int snakex[], int snakey[])
{
    char input;

    // 保存蛇头的当前位置
    int headx = snakex[0];
    int heady = snakey[0];

    // 更新蛇身的位置
    for (int i = length - 1; i > 0; i--) {
        snakex[i] = snakex[i - 1];
        snakey[i] = snakey[i - 1];
    }

    // 根据用户输入更新蛇头的位置
    input = getch();
    switch (input) {
    case 'w':
        snakex[0]--;
        break;
    case 's':
        snakex[0]++;
        break;
    case 'a':
        snakey[0]--;
        break;
    case 'd':
        snakey[0]++;
        break;
    }

    // 如果蛇吃到食物，蛇身会变长，需要为新的蛇尾赋值
    if (length > 1) {
        snakex[length - 1] = headx;
        snakey[length - 1] = heady;
    }
}

void cursh(int snakex[], int snakey[])
{
    if (snakex[0] == 0 || snakex[0] == 19 || snakey[0] == 0 || snakey[0] == 19) {
        printf("Game Over");
        exit(0);
    }
    for (int i = 1; i < length; i++) {
        if (snakex[0] == snakex[i] && snakey[0] == snakey[i]) {
            printf("Game Over");
            exit(0);
        }
    }
    if (snakex[0] == foodx && snakey[0] == foody) {
        foodx = rand() % 18 + 1;
        foody = rand() % 18 + 1;
        length++;
        snakex[length] = snakex[length - 1];
        snakey[length] = snakey[length - 1];
    }
}


int main()
{
    srand(time(NULL));


    int snakex[20];
    int snakey[20];



    foodx = rand() % 18 + 1;
    foody = rand() % 18 + 1;

    snakex[0] = 10;
    snakey[0] = 10;

    while (1) {
        Sleep(100);
        cursh(snakex, snakey );
        draw( snakex, snakey);
        move(snakex, snakey);




    }

    return 0;
}
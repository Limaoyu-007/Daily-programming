#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


#define WIDTH 20
#define HIGHT 20

int headx = 10;
int heady = 10;
int foodx;
int foody;
int score = 0;
int bodyx[100];
int bodyy[100];


void draw()
{
	system("cls");



	for (int i = 0; i < HIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == HIGHT - 1 || j == 0 || j == WIDTH - 1) {
				printf("#");
			}
			else if (i == foody && j == foodx) {
				printf("*");
			}
			else if (i == heady && j == headx) {
				printf("O");
			}
            else if (i == bodyy[i] && j == bodyx[i]) {
				printf("o");
			}
			else
			{
				printf(" ");
			}
			
		}
        printf("\n");
	}
}

void move()
{
	char key = getch();
	switch (key)
	{
	case 'w':heady--; break;
	case 's':heady++; break;
	case 'a':headx--; break;
	case 'd':headx++; break;
	}
	for (int i = score; i > 0; i--) {
		bodyx[i] = bodyx[i - 1];
		bodyy[i] = bodyy[i - 1];
	}
    bodyx[0] = headx;
    bodyy[0] = heady;
}

void cursh()
{
	if (headx == foodx && heady == foody) {
		foodx = rand() % 19;
		foody = rand() % 19;
		
        bodyx[score] = headx;
        bodyy[score] = heady;
		score++;
	}
	if (headx == 0 || headx == 19 || heady == 0 || heady == 19) {
		system("cls");
        printf("Game Over");
        exit(0);
	}

}



int main()
{
	foodx = rand() % 19;
	foody = rand() % 19;
    while (1)
    {

		cursh();
        draw();

        move();
        Sleep(100);
    }
}
#include <iostream>
using namespace std;
# include <conio.h>

	/* 몬스터 */
/* 고블린 */
int GoblinFunc()
{
	// HP Random으로 구현
	int HP = 0;
	srand((unsigned int)time(NULL));  
	HP = rand() % 100 + 1;

	cout << "고블린의 HP : " << HP << endl;

	return HP;
}

/* 슬라임 */
int SlimeFunc()
{
	// HP Random으로 구현
	int HP = 0;
	srand((unsigned int)time(NULL));
	HP = rand() % 100 + 1;

	cout << "슬라임의 HP : " << HP << endl;

	return HP;
}



	/* 맵 */
int map[10][10] =
{
	{0,0,0,0,0,0,0,0,0,0},
	{0,2,2,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0}
};

	/* 변수 */
/* 캐릭터 */
char KeyBoard = 'a';
char Player = 'P';
bool IsRunning = true;

int PlayerX = 1;
int PlayerY = 1;
/* 고블린 */
char Goblin = 'G';
int GoblinX = 5;
int GoblinY = 5;
bool G_Flag = 1;
/* 슬라임 */
char Slime = 'S';
int SlimeX = 5;
int SlimeY = 5;
bool S_Flag = 0;

void Input()
{
	//cin >> KeyBoard;
	KeyBoard = _getch(); // int 아스키로 입력받기 / 엔터키 안받고 입력
}

void Tick()
{
	if (KeyBoard == 'a' || KeyBoard == 'A')
	{
		if (PlayerX != 1)
		{
			PlayerX -= 1;
		}
	}
	else if (KeyBoard == 'w' || KeyBoard == 'W')
	{
		if (PlayerY != 1)
		{
			PlayerY -= 1;
		}
	}
	else if (KeyBoard == 'd' || KeyBoard == 'D')
	{
		if (PlayerX != 8)
		{
			PlayerX += 1;
		}
	}
	else if (KeyBoard == 's' || KeyBoard == 'S')
	{
		if (PlayerY != 8)
		{
			PlayerY += 1;
		}
	}
	else if (KeyBoard == 'q' || KeyBoard == 'Q')
	{
		IsRunning = false;
	}
	else
	{

	}
}

void Draw()
{
	/* 맵에 덧붙이는 버전*/
		//map[PlayerY][PlayerX] = KeyBoard;

		/* 따로 출력하는 버전*/
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{	// 플레이어 출력
			if (i == PlayerY && j == PlayerX)
			{
				cout << Player;
				
			}
			// 고블린 출력 (중첩 표현 필요)
			if (i == GoblinY && j == GoblinX && G_Flag == 1)
			{
				cout << Goblin;
			}
			// 고블린 출력 (중첩 표현 필요)
			if (i == SlimeY && j == SlimeX && S_Flag == 1)
			{
				cout << Slime;
			}
			
			// 맵출력
			else if (map[i][j] == 0)
			{
				cout << (char)127;
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << KeyBoard << endl;

}

int main()
{

	// 문제 1 : 몬스터 고블린, 슬라임, 멧돼지.
			//	몬스터 HP
			// 동서남북 이동
			// n 스테이지마다 몬스터 종류, 갯수 변경
		// 아이디어 : 몬스터 함수로 구현
		//	각 함수마다 HP, 이동 구현

		/* 몬스터 생성 */
	int HP_Goblin = 0;
	HP_Goblin = GoblinFunc();

	int HP_Slime = 0;
	HP_Slime = GoblinFunc();

	int PlusX;
	int PlusY;

		/* 스테이지 조건*/
	int Count = 0;

	//Gameloop
	while (IsRunning)
	{
		Input();

		Tick();

		Draw();

			/* 몬스터 이동 */
		PlusX =  rand() % 2;
		PlusY = rand() % 2;
		if (PlusX == 1)
		{
			if (G_Flag == 1)
			{
				GoblinX++;
				cout << "고블린이 동쪽으로 이동합니다. : " << endl;
			}
			else if (S_Flag == 1)
			{
				SlimeX++;
				cout << "슬라임이 동쪽으로 이동합니다. : " << endl;
			}
		}
		else if (PlusX == 0)
		{
			if (G_Flag == 1)
			{
				GoblinX--;
				cout << "고블린이 서쪽으로 이동합니다. : " << endl;
			}
			else if (S_Flag == 1)
			{
				SlimeX--;
				cout << "슬라임이 서쪽으로 이동합니다. : " << endl;
			}
		}
		if (PlusY == 1)
		{
			if (G_Flag == 1)
			{
				GoblinY++;
			}
			else if (S_Flag == 1)
			{
				SlimeY++;
			}
		}
		else if (PlusY == 0)
		{
			if (G_Flag == 1)
			{
				GoblinY--;
			}
			else if (S_Flag == 1)
			{
				SlimeY--;
			}
		}

		if (Count <= 10)
		{
			cout << "고블린의 HP : " << HP_Goblin << endl;
		}
			/* 스테이지 */
		else if (Count>=10)
		{
			if (Count % 10 <= 3)
			{
				cout << "스테이지 클리어!  " << endl;
				cout << "다음 스테이지로 !  " << endl;
			}
			G_Flag = 0;
			S_Flag = 1;
			cout << "슬라임의 HP : " << HP_Slime << endl;
		}


		Count++;
	}

	return 0;
}
#include <iostream>
using namespace std;
# include <conio.h>

	/* ���� */
/* ��� */
int GoblinFunc()
{
	// HP Random���� ����
	int HP = 0;
	srand((unsigned int)time(NULL));  
	HP = rand() % 100 + 1;

	cout << "����� HP : " << HP << endl;

	return HP;
}

/* ������ */
int SlimeFunc()
{
	// HP Random���� ����
	int HP = 0;
	srand((unsigned int)time(NULL));
	HP = rand() % 100 + 1;

	cout << "�������� HP : " << HP << endl;

	return HP;
}



	/* �� */
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

	/* ���� */
/* ĳ���� */
char KeyBoard = 'a';
char Player = 'P';
bool IsRunning = true;

int PlayerX = 1;
int PlayerY = 1;
/* ��� */
char Goblin = 'G';
int GoblinX = 5;
int GoblinY = 5;
bool G_Flag = 1;
/* ������ */
char Slime = 'S';
int SlimeX = 5;
int SlimeY = 5;
bool S_Flag = 0;

void Input()
{
	//cin >> KeyBoard;
	KeyBoard = _getch(); // int �ƽ�Ű�� �Է¹ޱ� / ����Ű �ȹް� �Է�
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
	/* �ʿ� �����̴� ����*/
		//map[PlayerY][PlayerX] = KeyBoard;

		/* ���� ����ϴ� ����*/
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{	// �÷��̾� ���
			if (i == PlayerY && j == PlayerX)
			{
				cout << Player;
				
			}
			// ��� ��� (��ø ǥ�� �ʿ�)
			if (i == GoblinY && j == GoblinX && G_Flag == 1)
			{
				cout << Goblin;
			}
			// ��� ��� (��ø ǥ�� �ʿ�)
			if (i == SlimeY && j == SlimeX && S_Flag == 1)
			{
				cout << Slime;
			}
			
			// �����
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

	// ���� 1 : ���� ���, ������, �����.
			//	���� HP
			// �������� �̵�
			// n ������������ ���� ����, ���� ����
		// ���̵�� : ���� �Լ��� ����
		//	�� �Լ����� HP, �̵� ����

		/* ���� ���� */
	int HP_Goblin = 0;
	HP_Goblin = GoblinFunc();

	int HP_Slime = 0;
	HP_Slime = GoblinFunc();

	int PlusX;
	int PlusY;

		/* �������� ����*/
	int Count = 0;

	//Gameloop
	while (IsRunning)
	{
		Input();

		Tick();

		Draw();

			/* ���� �̵� */
		PlusX =  rand() % 2;
		PlusY = rand() % 2;
		if (PlusX == 1)
		{
			if (G_Flag == 1)
			{
				GoblinX++;
				cout << "����� �������� �̵��մϴ�. : " << endl;
			}
			else if (S_Flag == 1)
			{
				SlimeX++;
				cout << "�������� �������� �̵��մϴ�. : " << endl;
			}
		}
		else if (PlusX == 0)
		{
			if (G_Flag == 1)
			{
				GoblinX--;
				cout << "����� �������� �̵��մϴ�. : " << endl;
			}
			else if (S_Flag == 1)
			{
				SlimeX--;
				cout << "�������� �������� �̵��մϴ�. : " << endl;
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
			cout << "����� HP : " << HP_Goblin << endl;
		}
			/* �������� */
		else if (Count>=10)
		{
			if (Count % 10 <= 3)
			{
				cout << "�������� Ŭ����!  " << endl;
				cout << "���� ���������� !  " << endl;
			}
			G_Flag = 0;
			S_Flag = 1;
			cout << "�������� HP : " << HP_Slime << endl;
		}


		Count++;
	}

	return 0;
}
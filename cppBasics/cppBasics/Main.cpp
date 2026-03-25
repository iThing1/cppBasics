#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

const int MAP_SIZE_X = 10;
const int MAP_SIZE_Y = 10;
const int MAX_ITEMS = 3;
const int MAX_MONSTERS = 5;

int map[MAP_SIZE_X][MAP_SIZE_Y] = { 0 };

void GenerateMap()
{
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			map[i][j] = 0;
		}
	}
	int itemCount = rand() % MAX_ITEMS;
	if (itemCount == 0) itemCount = 1;
	for (int i = 0; i < itemCount; i++)
	{
		int x = rand() % MAP_SIZE_X;
		int y = rand() % MAP_SIZE_Y;
		map[x][y] = 1;
	}
	int monsterCount = rand() % MAX_MONSTERS;
	for (int i = 0; i < monsterCount;)
	{
		int x = rand() % MAP_SIZE_X;
		int y = rand() % MAP_SIZE_Y;
		if (map[x][y] == 0)
		{
			map[x][y] = 2;
			i++;
		}
	}
}

void PrintMap()
{
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			cout << map[i][j] << "  ";
			if (j == MAP_SIZE_Y - 1)
			{
				cout << endl;
				cout << endl;
			}
		}
	}
}

void PrintVictory()
{
	system("cls");
	cout << "======================" << endl;
	cout << "      Victory!       " << endl;
	cout << "======================" << endl;
}

void PrintGameOver()
{
	system("cls");
	cout << "======================" << endl;
	cout << "      Game Over      " << endl;
	cout << "======================" << endl;
}

void PlayGame()
{
	GenerateMap();
	int playerX = -1;
	int playerY = -1;
	while (true)
	{
		PrintMap();
		cout << "보물을 찾을 행을 입력하세요: " << endl;
		cin >> playerX;
		if (playerX < 0 || playerX >= MAP_SIZE_X)
		{
			cout << "잘못된 입력입니다. 0에서 " << MAP_SIZE_X - 1 << " 사이의 값을 입력하세요." << endl;
			continue;
		}
		cout << "보물을 찾을 열을 입력하세요: " << endl;
		cin >> playerY;
		if (playerY < 0 || playerY >= MAP_SIZE_Y)
		{
			cout << "잘못된 입력입니다. 0에서 " << MAP_SIZE_Y - 1 << " 사이의 값을 입력하세요." << endl;
			continue;
		}
		cout << "보물을 찾을 좌표: (" << playerX << ", " << playerY << ")" << endl;
		if (map[playerX][playerY] == 1)
		{
			cout << "보물을 획득했습니다!!!" << endl;
			Sleep(800);
			PrintVictory();
			break;
		}
		else if (map[playerX][playerY] == 2)
		{
			cout << "몬스터와 조우했습니다!" << endl;
			Sleep(800);
			cout << "몬스터가 당신에게 달려듭니다!!" << endl;
			Sleep(800);
			cout << "당신은 몬스터에게 잡혔습니다..." << endl;
			Sleep(800);
			PrintGameOver();
			break;
		}
		else
		{
			cout << "빈 공간입니다..." << endl;
			Sleep(800);
			system("cls");
		}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	
	PlayGame();

	return 0;
}
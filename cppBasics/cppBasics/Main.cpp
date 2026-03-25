#include <iostream>
#include <cstdlib>
using namespace std;

const int MAP_SIZE_X = 10;
const int MAP_SIZE_Y = 10;
const int MAX_ITEMS = 3;

int main()
{	
	srand(static_cast<unsigned int>(time(NULL)));
	int Map[MAP_SIZE_X][MAP_SIZE_Y] = { 0 };
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			Map[i][j] = 0;
		}
	}

	int itemCount = rand() % MAX_ITEMS;
	if (itemCount == 0) itemCount = 1;
	for (int i = 0; i < itemCount; i++)
	{
		int x = rand() % MAP_SIZE_X;
		int y = rand() % MAP_SIZE_Y;
		Map[x][y] = 1;
	}

	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			cout << Map[i][j] << "  ";
			if (j == MAP_SIZE_Y - 1)
			{
				cout << endl;
				cout << endl;
			}
		}
	}

	return 0;
}
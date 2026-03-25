#include <iostream>

using namespace std;

const int MAP_SIZE_X = 10;
const int MAP_SIZE_Y = 10;

int main()
{
	int Map[MAP_SIZE_X][MAP_SIZE_Y] = { 0 };
	for (int i = 0; i < MAP_SIZE_X; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			Map[i][j] = 0;
		}
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
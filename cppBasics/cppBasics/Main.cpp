#include <iostream>

int Plus(int x, int y)
{
	return x + y;
}

void ShowResult(int result)
{
	std::cout << "결과값: " << result << std::endl;
}

int main()
{
	// 함수 호출부
	Plus(10, 20);
	int result = Plus(10, 20);
	ShowResult(result);

	return 0;
}
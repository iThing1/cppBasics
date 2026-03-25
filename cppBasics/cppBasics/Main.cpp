#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

// 승무패 기록과 점수 합산을 위한 전역 변수
int wins = 0;
int losses = 0;
int draws = 0;
enum ElementType
{
	Fire = 0,
	Water = 1,
	Wind = 2,
	Earth = 3,
	Electric = 4,
	None = -1
};
string GetElementName(ElementType type)
{
	if (type == Fire) return "불";
	if (type == Water) return "물";
	if (type == Wind) return "바람";
	if (type == Earth) return "대지";
	if (type == Electric) return "전기";
	return "알 수 없음";
}
int PlayRockPaperScissors(ElementType playerChoice, ElementType computerChoice)
{
	int score = 0;
	// 플레이어가 이기는 경우의 수
	bool playerWins = 
		(playerChoice == Fire && computerChoice == Wind) ||
	    (playerChoice == Wind && computerChoice == Earth) ||
	    (playerChoice == Earth && computerChoice == Electric) ||
		(playerChoice == Electric && computerChoice == Water) ||
		(playerChoice == Water && computerChoice == Fire);
	// 플레이어가 지는 경우의 수
	bool playerLoses = 
		(playerChoice == Fire && computerChoice == Water) ||
		(playerChoice == Wind && computerChoice == Fire) ||
		(playerChoice == Earth && computerChoice == Wind) ||
		(playerChoice == Electric && computerChoice == Earth) ||
		(playerChoice == Water && computerChoice == Electric);

	if (playerWins)
	{
		cout << "플레이어 승리!" << endl;
		score = 3;
	}
	else if (playerLoses)
	{
		cout << "컴퓨터 승리!" << endl;
		score = 0;
	}
	else
	{
		cout << "무승부!" << endl;
		score = 1;
	}
	return score;
}
int GetPlayerType()
{
	int n = 0;
	while (true)
	{
		cout << "속성을 선택하세요 (0:불 1:물 2:바람 3:대지 4:전기): ";
		cin >> n;

		if (n >= 0 && n <= 4) 
		{
			cout << "선택 완료: " << GetElementName(static_cast<ElementType>(n)) << endl;
			return n;
		}
		cout << "잘못된 입력입니다. 0~4 사이를 입력하세요." << endl;
		
	}
}
void PlayGame(int rounds)
{
	for (int i = 0; i < rounds; i++)
	{
		Sleep(1000);
		cout << "라운드 " << (i + 1) << " 시작!" << endl;
		// 플레이어/컴퓨터의 캐릭터 속성 선택(int -> ElementType 형변환)
		ElementType playerChoice = static_cast<ElementType>(GetPlayerType());
		ElementType computerChoice = static_cast<ElementType>(rand() % 5);
		cout << "=> 컴퓨터가 속성 선택 중..." << endl; Sleep(1000);
		for (int j = 0; j < 3; j++) { Sleep(300); cout << "."; }
		cout << endl;

		// 선택된 속성 문자열로 변환
		cout << "[플레이어: " << GetElementName(playerChoice) << "] vs ";
		cout << "[컴퓨터: " << GetElementName(computerChoice) << "]" << endl;
		
		int result = PlayRockPaperScissors(playerChoice, computerChoice);
		Sleep(500);
		if (result == 3) wins++;
		else if (result == 0) losses++;
		else draws++;
	}
	cout << "모든 라운드가 종료되었습니다!" << endl;
	cout << "잠시 후 결과가 출력됩니다..." << endl;
	Sleep(2000);
}
void ShowTitleScreen()
{
	system("cls");
	cout << "========================================" << endl;
	cout << "         원소 속성 대결 게임              " << endl;
	cout << "            [Made By Hun]                " << endl;
	cout << "========================================" << endl;
	Sleep(500);
	cout << endl;
	cout << "   [  속 성  종 류  ]       " << endl;
	cout << "   0. 불    (Fire)           " << endl;
	Sleep(200);
	cout << "   1. 물    (Water)        " << endl;
	Sleep(200);
	cout << "   2. 바람  (Wind)        " << endl;
	Sleep(200);
	cout << "   3. 대지  (Earth)        " << endl;
	Sleep(200);
	cout << "   4. 전기  (Electric)     " << endl;
	Sleep(500);
	cout << endl;
	cout << "========================================" << endl;
	cout << "       아무 키나 눌러 시작하세요.     " << endl;
	cout << "========================================" << endl;
	(void)_getch();
}
void PrintResult()
{
	// 게임 결과 출력
	int totalScore = wins * 3 + draws * 1; // 승리 3점, 무승부 1점
	system("cls");
	cout << "=======게임 종료!=======" << endl; Sleep(500);
	cout << "라운드 진행 횟수: " << wins + losses + draws << endl; Sleep(1000);
	cout << "승리 횟수: " << wins << endl; Sleep(1000);
	cout << "패배 횟수: " << losses << endl; Sleep(1000);
	cout << "무승부 횟수: " << draws << endl; 
	cout << "========================" << endl; Sleep(2000);
	cout << "최종 점수: " << totalScore << endl;
	cout << "========================" << endl;
	cout << "아무키나 눌러 게임을 종료하세요 " << endl;
	(void)_getch();

}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	ShowTitleScreen();
	system("cls");

	// 게임 라운드 수 입력받기
	int rounds = 0;
	cout << "게임 라운드 수를 입력하세요." << endl;
	cin >> rounds;

	PlayGame(rounds);
	PrintResult();

	return 0;
}
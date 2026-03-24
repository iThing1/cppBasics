#include <iostream>
#include <Windows.h>
#include <conio.h>
// 과제4: 간단한 텍스트 게임 만들기
// 주제 : 각 원소별 상성 시스템 구현
// 1. 플레이어는 5개의 속성(불, 물, 바람, 대지, 전기)을 가진 캐릭터를 선택하여 게임을 진행한다.
// 2. 각 속성은 서로 상성 관계를 가지고 있다. 불 > 바람 > 대지 > 전기 > 물 > 불
// 3. 가위 바위 보 형식을 사용하여 플레이어와 컴퓨터가 대결한다. 
// 4. 승패는 상성 관계에 따라 결정된다.
// 5. 명확한 상성관계에 해당하지 않는 경우는 무승부로 처리한다.
// 6. 게임의 총 라운드 수는 플레이어가 선택할 수 있도록 한다.
// 7. 플레이어는 자신의 캐릭터의 속성을 선택하고, 컴퓨터는 랜덤으로 속성을 선택한다.
// 8. 라운드 수만큼 반복한다. 1라운드마다 승패를 출력하고 기록한다.
// 9. 게임이 끝난 후, 기록된 플레이어의 승리 횟수, 패배 횟수, 무승부 정보와 점수를 출력한다.
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

		switch (n)
		{
		case 0: cout << "플레이어가 불 속성 선택!"    << endl; return n;
		case 1: cout << "플레이어가 물 속성 선택!"    << endl; return n;
		case 2: cout << "플레이어가 바람 속성 선택!" << endl; return n;
		case 3: cout << "플레이어가 대지 속성 선택!" << endl; return n;
		case 4: cout << "플레이어가 전기 속성 선택!" << endl; return n;
		default:
			cout << "잘못된 입력입니다. 0에서 4 사이의 숫자를 입력하세요..." << endl;
			break; 
		}
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
		
		string playerElement = 
			(playerChoice == Fire) ? "불" :
		    (playerChoice == Water) ? "물" :
			(playerChoice == Wind) ? "바람" :
			(playerChoice == Earth) ? "대지" :
			(playerChoice == Electric) ? "전기" : "알 수 없음";
		string computerElement =				
			(computerChoice == Fire) ? "불" :
			(computerChoice == Water) ? "물" :
			(computerChoice == Wind) ? "바람" :
			(computerChoice == Earth) ? "대지" :
			(computerChoice == Electric) ? "전기" : "알 수 없음";

		cout << "  [ 플레이어 ] vs " << "[ 컴퓨터 ]  " << endl;
		cout << "        " << playerElement << "            " << computerElement << "     " << endl;
		
		int result = PlayRockPaperScissors(playerChoice, computerChoice);
		Sleep(1000);
		if (result == 3) wins++;
		else if (result == 0) losses++;
		else draws++;
	}
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
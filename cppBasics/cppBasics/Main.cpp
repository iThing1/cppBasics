#include <iostream>

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
		case 0: cout << "플레이어가 불 속성을 선택했습니다."    << endl; return n;
		case 1: cout << "플레이어가 물 속성을 선택했습니다."    << endl; return n;
		case 2: cout << "플레이어가 바람 속성을 선택했습니다." << endl; return n;
		case 3: cout << "플레이어가 대지 속성을 선택했습니다." << endl; return n;
		case 4: cout << "플레이어가 전기 속성을 선택했습니다." << endl; return n;
		default:
			cout << "잘못된 입력입니다. 0에서 4 사이의 숫자를 입력하세요." << endl;
			break; 
		}
	}
}
int main()
{
	

	return 0;
}
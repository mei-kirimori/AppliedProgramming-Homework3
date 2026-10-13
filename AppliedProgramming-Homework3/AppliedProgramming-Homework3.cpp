#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 



enum Hands
{
	rock  = 1,
	scissors = 2,
	pepper = 3
};

class user
{
public:
	char name[20];
	Hands hand;
	int wincount;
	int losecount;
	int drawcount;

	user(const char* n);
	void zyannkennInfo();
};





user::user(const char* n)
{
	strcpy_s(name, sizeof(name), n);
	hand = Hands::rock;
	wincount = 0;
	losecount = 0;
	drawcount = 0;
}
void zyannkennJudge(user* player, user* enemy);

void zyannkennJudge(user* player, user* enemy)
{
	if (player->hand == enemy->hand)
	{
		cout << "あいこです" << endl;
		player->drawcount++;
		enemy->drawcount++;
	}
	else if ((player->hand == Hands::rock && enemy->hand == Hands::scissors) ||
			 (player->hand == Hands::scissors && enemy->hand == Hands::pepper) ||
			 (player->hand == Hands::pepper && enemy->hand == Hands::rock))
	{
		cout << player->name << "の勝ちです" << endl;
		player->wincount++;
		enemy->losecount++;
	}
	else
	{
		cout << enemy->name << "の勝ちです" << endl;
		player->losecount++;
		enemy->wincount++;
	}
}

void zyannkennInfo(user* player)
{
	cout << player->name << "の勝ち数: " << player->wincount << endl;
	cout << player->name << "の負け数: " << player->losecount << endl;
	cout << player->name << "のあいこ数: " << player->drawcount << endl;
	
	
	
}

int main()
{
	srand((unsigned int)time(NULL));

	user user[2] = 
	{
		{"player"},
		{"enemy"}
	};

	int userTMP;
	int gameCount = 0;
	cout << "じゃんけんゲームを始めます" << endl;
	cout << "遊ぶ回数を入力してください" << endl;
	cin >> gameCount;
	for (int i = 0; i < gameCount; i++)
	{
		cout << "ゲーム" << i + 1 << "回目" << endl;

		cout << "あなたの手を入力してください:グーなら１を、チョキなら２を、パーなら３を入力してください" << endl;
		cin >> userTMP;
		Hands userHand = static_cast<Hands>(userTMP);
		user[0].hand = userHand;
		user[1].hand = static_cast<Hands>(rand() % 3 + 1);

		zyannkennJudge(&user[0], &user[1]);
	}
	zyannkennInfo(&user[0]);
	if (user[0].wincount > user[0].losecount)
	{
		cout << user[0].name << "の勝ちです" << endl;
	}
	else if (user[1].wincount > user[1].losecount)
	{
		cout << user[1].name << "の勝ちです" << endl;
	}

}
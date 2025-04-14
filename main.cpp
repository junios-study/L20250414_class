#include <iostream>

using namespace std;


class State
{
public:
	int ID;
	string Name;
};

class Transition
{
public:
	int CurrentState;
	string Condition;
	int NextState;
};

class Monster
{
public:
	int State;
	string Condition;
};

class MonsterFSM
{
public:
	State States[4];
	Transition Transitions[5];

	void Process(Monster* _Monster)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (_Monster->State == Transitions[i].CurrentState &&
				_Monster->Condition == Transitions[i].Condition)
			{
				_Monster->State = Transitions[i].NextState;
			}
		}
	}

	string FindName(int FindID)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (States[i].ID == FindID)
			{
				return States[i].Name;
			}
		}

		return "";
	}
};

//MonsterFSM has a State.
//MonsterFSM has a Transition.
class Icon
{
public:

};

class Skill
{
public:
	int MaxSkillLevel;
	int CurrentSkillLevel;
	Icon SkillIcon;

	Skill* NextSkill;

	void UseSkillPoint()
	{

	}

};


class SkillTree
{
public:
	Skill Skills[22];

	void Draw()
	{

	}
};

class Player
{
public:
	void Do();
};


int main()
{
	Player MyPlayer; //instance

	int PlayerX;
	int PlayerY;


	MonsterFSM MyMonsterFSM;

	MyMonsterFSM.States[0].ID = 1;
	MyMonsterFSM.States[0].Name = "배회";

	MyMonsterFSM.States[1].ID = 2;
	MyMonsterFSM.States[1].Name = "추격";

	MyMonsterFSM.States[2].ID = 3;
	MyMonsterFSM.States[2].Name = "공격";

	MyMonsterFSM.States[3].ID = 4;
	MyMonsterFSM.States[3].Name = "죽음";

	MyMonsterFSM.Transitions[0].CurrentState = 1;
	MyMonsterFSM.Transitions[0].Condition = "적발견";
	MyMonsterFSM.Transitions[0].NextState = 2;

	MyMonsterFSM.Transitions[1].CurrentState = 2;
	MyMonsterFSM.Transitions[1].Condition = "적놓침";
	MyMonsterFSM.Transitions[1].NextState = 1;

	MyMonsterFSM.Transitions[2].CurrentState = 2;
	MyMonsterFSM.Transitions[2].Condition = "사정거리접근";
	MyMonsterFSM.Transitions[2].NextState = 3;

	MyMonsterFSM.Transitions[3].CurrentState = 3;
	MyMonsterFSM.Transitions[3].Condition = "사정거리이탈";
	MyMonsterFSM.Transitions[3].NextState = 2;

	MyMonsterFSM.Transitions[4].CurrentState = 3;
	MyMonsterFSM.Transitions[4].Condition = "HP없음";
	MyMonsterFSM.Transitions[4].NextState = 4;


	Monster 하진;
	하진.State = 1;
	하진.Condition = "적발견";

	MyMonsterFSM.Process(&하진);

	//Range > 10(두벡터의 거리, 수학(엔진))
	cout << MyMonsterFSM.FindName(하진.State) << endl;

	하진.Condition = "사정거리접근";

	MyMonsterFSM.Process(&하진);
	cout << MyMonsterFSM.FindName(하진.State) << endl;

	//데이터 모델링
	//SkillTree.Draw()

	//SkillTree Has a Skill.


	return 0;
}
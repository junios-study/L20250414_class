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

class MonsterFSM
{
public:
	State States[4];
	Transition Transitions[5];

};

//MonsterFSM has a State.
//MonsterFSM has a Transition.


int main()
{
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
	MyMonsterFSM.Transitions[0].NextState = 1;

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







	return 0;
}
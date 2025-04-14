#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "World.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"

using namespace std;


int main()
{
	APlayer* Player = new APlayer();


	delete Player;
	Player = nullptr;

	return 0;
}
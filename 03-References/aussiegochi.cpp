#include "aussiegochi.h"

void feedAussie(Aussiegochi& aus)
{
	aus.thirst += 10;
	aus.sanity -= 10;
	aus.happiness += 10;
	aus.hunger -= 20;
}

void waterAussie(Aussiegochi& aus)
{
	aus.thirst -= 10;
	aus.sanity -= 10;
	aus.happiness += 10;
	aus.hunger += 5;

}

void abuseAussie(Aussiegochi& aus)
{
	aus.thirst -= 10;
	aus.sanity -= 10;
	aus.happiness += 30;
	aus.hunger += 30;
}

void coddleAussie(Aussiegochi& aus)
{
	aus.thirst += 10;
	aus.sanity -= 20;
	aus.happiness -= 10;
	aus.hunger -= 5;
}

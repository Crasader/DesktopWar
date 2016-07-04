
#include <vector>
#include "tinyxml2.h"
#include "GamePlay.h"
#include "entity/EntityCreators.h"
#include "pawn/PawnDefines.h"
#include "Log.h"

using namespace tinyxml2;
using namespace Genius;

struct PawnBornInfo
{
	std::string pawnID;
	float time;
	int x;
	float y;
	bool done;
};

struct PawnSequenceInfo
{
	std::string name;
	float time;
	int x;
	int y;
	std::vector<PawnBornInfo> pawns;
	bool done;
};

std::vector<PawnSequenceInfo> pawnSequence;

GamePlay& GamePlay::GetSingleton()
{
	static GamePlay inst;
	return inst;
}

bool GamePlay::Init()
{
	bool  ret = LoadFromConfig("res/wave/wave01.xml");
	return ret;
}

void GamePlay::Update(float time)
{
	static int currentWaveIndex = 0;
	static float timePassed = 0;
	timePassed += time;

	if (pawnSequence.empty())
		return;

	if (currentWaveIndex >= pawnSequence.size())
		return;

	PawnSequenceInfo& seqInfo = pawnSequence[currentWaveIndex];
	if (timePassed < seqInfo.time)
		return;

	seqInfo.done = true;
	for (auto iter = seqInfo.pawns.begin(); iter != seqInfo.pawns.end(); ++iter)
	{
		PawnBornInfo& bornInfo = *iter;
		if ((!bornInfo.done) && timePassed - seqInfo.time > bornInfo.time)
		{
			EntityCreator::CreatePawn(bornInfo.pawnID, seqInfo.x + bornInfo.x, seqInfo.y + bornInfo.y, Team_Monster);
			bornInfo.done = true;
		}
		if (!bornInfo.done)
			seqInfo.done = false;
	}

	if (seqInfo.done)
		currentWaveIndex++;
}

void GamePlay::Destroy()
{
	for (auto iter = pawnSequence.begin(); iter != pawnSequence.end(); ++iter)
	{
		for (auto iter2 = (*iter).pawns.begin(); iter2 != (*iter).pawns.end(); ++iter2)
		{
		}
	}
}

void GamePlay::SendMonster()
{

}

void GamePlay::SendHuman()
{

}

bool GamePlay::LoadFromConfig(std::string filePath)
{
	XMLDocument* doc = new XMLDocument();
	if (!doc->LoadFile(filePath.c_str()))
		return false;

	std::string forePath = filePath.substr(0, filePath.find_last_of("/") + 1);

	XMLElement* root = doc->RootElement();
	for (XMLElement* animSetNode = root->FirstChildElement(); animSetNode; animSetNode = animSetNode->NextSiblingElement())
	{
		PawnSequenceInfo seqInfo;
		seqInfo.name = animSetNode->Attribute("name");
		seqInfo.time = atof(animSetNode->Attribute("time"));
		seqInfo.x = atof(animSetNode->Attribute("x"));
		seqInfo.y = atof(animSetNode->Attribute("y"));
		seqInfo.done = false;
		for (XMLElement* animNode = animSetNode->FirstChildElement(); animNode; animNode = animNode->NextSiblingElement())
		{
			PawnBornInfo bornInfo;
			bornInfo.pawnID = animNode->Attribute("type");
			bornInfo.time = atoi(animNode->Attribute("time"));
			bornInfo.x = atoi(animNode->Attribute("x"));
			bornInfo.y = atoi(animNode->Attribute("y"));
			bornInfo.done = false;
			seqInfo.pawns.push_back(bornInfo);
		}
		pawnSequence.push_back(seqInfo);
	}
	delete doc;

	return true;
}
// d:)
#include "BevtreeCom.h"
#include "pawn/PawnBHTree.h"

using namespace Genius;

BevtreeCom::BevtreeCom(std::string fileName)
{
	m_tree = nullptr;
	InitTree(fileName);
}

void BevtreeCom::InitTree(std::string fileName)
{
	m_tree = new PawnBHTree;
	m_tree->Init(fileName.c_str());
}

BevtreeCom::~BevtreeCom()
{
	if (m_tree)
	{
		m_tree->Destroy();
		delete m_tree;
		m_tree = nullptr;
	}
}

#include "ComPawnBevtree.h"
#include "pawn/PawnBHTree.h"

using namespace Genius;

ComPawnBevtree::ComPawnBevtree(std::string fileName)
{
	m_tree = nullptr;
	InitTree(fileName);
}

void ComPawnBevtree::InitTree(std::string fileName)
{
	m_tree = new PawnBHTree;
	m_tree->Init(fileName.c_str());
}

ComPawnBevtree::~ComPawnBevtree()
{
	if (m_tree)
	{
		m_tree->Destroy();
		delete m_tree;
		m_tree = nullptr;
	}
}
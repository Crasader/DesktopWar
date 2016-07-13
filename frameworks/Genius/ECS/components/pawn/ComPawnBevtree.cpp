
#include "ComPawnBevtree.h"
#include "pawn/bevtree/PawnBHTree.h"

using namespace Genius;


void ComPawnBevtree::Create(std::string fileName)
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

#ifndef _BEVTREE_COMPONENT_H_
#define _BEVTREE_COMPONENT_H_

#include "../core/Component.h"
#include "AI/AI.h"
#include <string>

class PawnBHTree;

namespace Genius
{
	class Entity;

	struct EntityBevInputData
	{
		Entity*	pEntity;
		float		timeDelta;
	};

	class BevtreeCom : public Genius::Component
	{
	public:
		BevtreeCom(std::string fileName);

		virtual ~BevtreeCom();

	private:
		void InitTree(std::string fileName);

	public:
		PawnBHTree*	m_tree;
	};
};

#endif
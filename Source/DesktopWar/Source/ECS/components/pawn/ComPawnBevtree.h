
#ifndef _BEVTREE_COMPONENT_H_
#define _BEVTREE_COMPONENT_H_

#include "../../core/Component.h"
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

	class ComPawnBevtree : public Genius::Component
	{
	public:
		ComPawnBevtree(std::string fileName);

		virtual ~ComPawnBevtree();

	private:
		void InitTree(std::string fileName);

	public:
		PawnBHTree*	m_tree;
	};
};

#endif
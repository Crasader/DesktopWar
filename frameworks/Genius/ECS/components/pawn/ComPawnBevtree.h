
#ifndef _BEVTREE_COMPONENT_H_
#define _BEVTREE_COMPONENT_H_

#include "../../core/IComponent.h"
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

	class ComPawnBevtree : public Genius::IComponent
	{
	public:
		COM_CREATE_FN_DECL(ComPawnBevtree);

	public:

		ComPawnBevtree();

		virtual ~ComPawnBevtree();

		void Create(std::string fileName);

	public:
		PawnBHTree*	m_tree;
	};
};

#endif
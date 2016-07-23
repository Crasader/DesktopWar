#pragma once

// core
#include "core/IComponent.h"
#include "core/Entity.h"
#include "core/EntityManager.h"
#include "core/SystemManager.h"
#include "core/ECSWorld.h"


// components
#include "components/common/ComTransform.h"
#include "components/common/ComBoxCollider.h"
#include "components/common/ComRenderRoot.h"
#include "components/common/ComParticle.h"
#include "components/common/ComBezierMovement.h"
#include "components/common/ComDelayTrackMovement.h"

#include "components/pawn/ComPawnAgent.h"
#include "components/pawn/ComPawnAnim.h"
#include "components/pawn/ComPawnDebugDraw.h"
#include "components/pawn/ComPawnFight.h"
#include "components/pawn/ComPawnNavigation.h"
#include "components/pawn/ComPawnBevtree.h"


#include "components/bullet/ComBulletAnimArrow.h"
#include "components/bullet/ComBulletAnimBase.h"
#include "components/bullet/ComBulletAnimBomb.h"
#include "components/bullet/ComBulletDamage.h"
#include "components/bullet/ComBulletDebugDraw.h"
#include "components/bullet/ComBulletAnimEgg.h"




// systems
#include "systems/common/SystemTransform.h"
#include "systems/common/SystemRender.h"
#include "systems/common/SystemDirection.h"
#include "systems/common/SystemBoxCollider.h"
#include "systems/common/SystemBezierMovement.h"
#include "systems/common/SystemDelayTrackMovement.h"

#include "systems/pawn/SystemPawnBevtree.h"
#include "systems/pawn/SystemPawnNavigation.h"
#include "systems/pawn/SystemPawnFight.h"
#include "systems/pawn/SystemPawnDebugDraw.h"

//#include "systems/bullet/SystemBulletAnim.h"
#include "systems/bullet/SystemBulletDamage.h"
#include "systems/bullet/SystemBulletDebugDraw.h"
#include "systems/bullet/SystemBulletArrowAnim.h"
#include "systems/bullet/SystemBulletBombAnim.h"
//#include "systems/bullet/SystemBulletEggAnim.h"
#include "systems/bullet/SystemBulletTarget.h"





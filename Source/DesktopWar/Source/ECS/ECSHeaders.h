#ifndef _ECS_HEADERS_H_
#define _ECS_HEADERS_H_

// core
#include "core/Component.h"
#include "core/Entity.h"
#include "core/EntityManager.h"
#include "core/SystemManager.h"
#include "core/ECSWorld.h"


// components
#include "components/common/PositionCom.h"
#include "components/common/VelocityCom.h"
#include "components/common/BoxColliderCom.h"
#include "components/common/ColliderHandlerCom.h"
#include "components/common/AnimationCom.h"
#include "components/common/TeamCom.h"
#include "components/common/TargetCom.h"
#include "components/common/ParticleCom.h"
#include "components/common/BezierMovementCom.h"
#include "components/common/DelayTrackMovementCom.h"

#include "components/pawn/PawnActionCom.h"
#include "components/pawn/PawnAnimCom.h"
#include "components/pawn/PawnAttributeCom.h"
#include "components/pawn/PawnDebugDrawCom.h"
#include "components/pawn/PawnDirectionCom.h"
#include "components/pawn/PawnFightCom.h"
#include "components/pawn/PawnNavigationCom.h"
#include "components/pawn/PawnTemplateCom.h"

#include "components/BevtreeCom.h"

#include "components/bullet/BulletArrowAnimCom.h"
#include "components/bullet/BulletBaseAnimCom.h"
#include "components/bullet/BulletBombAnimCom.h"
#include "components/bullet/BulletDamageNoneCom.h"
#include "components/bullet/BulletDamageScopeCom.h"
#include "components/bullet/BulletDamageSingleCom.h"
#include "components/bullet/BulletDebugDrawCom.h"
#include "components/bullet/BulletEggAnimCom.h"
#include "components/bullet/BulletTemplateCom.h"

#include "components/GamePlayCom.h"


// systems
#include "systems/common/MovementSystem.h"
#include "systems/common/SimpleAnimSystem.h"
#include "systems/common/BoxColliderSystem.h"
#include "systems/common/BezierMovingSystem.h"
#include "systems/common/DelayTrackMovingSystem.h"

#include "systems/pawn/BevtreeSystem.h"
#include "systems/pawn/PawnAnimSystem.h"
#include "systems/pawn/PawnActionSystem.h"
#include "systems/pawn/PawnDirectionSystem.h"
#include "systems/pawn/navigationSystem.h"
#include "systems/pawn/PawnFightSystem.h"
#include "systems/pawn/PawnDebugDrawSystem.h"

#include "systems/bullet/BulletAnimSystem.h"
#include "systems/bullet/BulletDamageSingleSystem.h"
#include "systems/bullet/BulletDamageScopeSystem.h"
#include "systems/bullet/BulletDamageNoneSystem.h"
#include "systems/bullet/BulletDebugDrawSystem.h"
#include "systems/bullet/BulletArrowAnimSystem.h"
#include "systems/bullet/BulletBombAnimSystem.h"
#include "systems/bullet/BulletEggAnimSystem.h"
#include "systems/bullet/BulletTargetSystem.h"

#include "systems/game/HumanGameControlSystem.h"
#include "systems/game/MonsterGameControlSystem.h"



#endif
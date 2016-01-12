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

#include "components/BevtreeCom.h"
#include "components/PawnComponents.h"
#include "components/BulletComponents.h"
#include "components/GamePlayCom.h"


// systems
#include "systems/MovementSystem.h"
#include "systems/SimpleAnimSystem.h"
#include "systems/BoxColliderSystem.h"
#include "systems/BezierMovingSystem.h"
#include "systems/DelayTrackMovingSystem.h"
#include "systems/BevtreeSystem.h"
#include "systems/PawnAnimSystem.h"
#include "systems/PawnActionSystem.h"
#include "systems/PawnDirectionSystem.h"
#include "systems/navigationSystem.h"
#include "systems/PawnFightSystem.h"
#include "systems/PawnDebugDrawSystem.h"
#include "systems/BulletAnimSystem.h"
#include "systems/BulletDamageSingleSystem.h"
#include "systems/BulletDamageScopeSystem.h"
#include "systems/BulletDamageNoneSystem.h"
#include "systems/BulletDebugDrawSystem.h"
#include "systems/BulletArrowAnimSystem.h"
#include "systems/BulletBombAnimSystem.h"
#include "systems/BulletEggAnimSystem.h"
#include "systems/BulletTargetSystem.h"
#include "systems/HumanGameControlSystem.h"
#include "systems/MonsterGameControlSystem.h"



#endif
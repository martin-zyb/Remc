#include "rcpch.h"
#include "Entity.h"

namespace Remc {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}
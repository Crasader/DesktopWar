
#include "EventManager.h"

using namespace Genius;


EventManager::EventManager()
{

}

EventManager::~EventManager()
{
	Destroy();
}

bool EventManager::Init()
{
	return true;
}

void EventManager::Destroy()
{
	for (auto iter = m_listeners.begin(); iter != m_listeners.end(); ++iter)
	{
		iter->second.clear();
	}
	m_listeners.clear();
	m_globals.clear();
}

void EventManager::AddListener(IEventListener* listener, EventType type)
{
	if (nullptr == listener)
		return;

	EventListenerList& listenerList = m_listeners[type];
	for (auto iter = listenerList.begin(); iter != listenerList.end(); ++iter)
	{
		if (*iter == listener)
			return;
	}
	
	listenerList.push_back(listener);
}

void EventManager::RemoveListener(IEventListener* listener, EventType type)
{
	if (nullptr == listener)
		return;

	auto iterFind = m_listeners.find(type);
	if (iterFind != m_listeners.end())
	{
		EventListenerList& listenerList = iterFind->second;
		for (auto iter = listenerList.begin(); iter != listenerList.end(); ++iter)
		{
			if (*iter == listener)
			{
				listenerList.erase(iter);
				break;
			}
		}
	}
}

void EventManager::AddGlobalListener(IEventListener* listener)
{
	if (nullptr == listener)
		return;

	for (auto iter = m_globals.begin(); iter != m_globals.end(); ++iter)
	{
		if (*iter == listener)
			return;
	}

	m_globals.push_back(listener);
}

void EventManager::RemoveGlobalListener(IEventListener* listener)
{
	if (nullptr == listener)
		return;

	for (auto iter = m_globals.begin(); iter != m_globals.end(); ++iter)
	{
		if (*iter == listener)
		{
			m_globals.erase(iter);
			break;
		}
	}
}

void EventManager::RemoveAllListeners()
{
	for (auto iter = m_listeners.begin(); iter != m_listeners.end(); ++iter)
	{
		iter->second.clear();
	}
	m_listeners.clear();
	m_globals.clear();
}

bool EventManager::FireEvent(IEventData const &evt) const
{
	// Notify all global listeners.
	for (auto iter = m_globals.begin(); iter != m_globals.end(); ++iter)
	{
		if (*iter && (*iter)->HandleEvent(evt))
		{
			return true;
		}
	}

	auto iterFind = m_listeners.find(evt.GetType());
	if (iterFind != m_listeners.end())
	{
		//EventListenerList& listenerList = iterFind->second;
		for (auto iter = iterFind->second.begin(); iter != iterFind->second.end(); ++iter)
		{
			if (*iter)
			{
				(*iter)->HandleEvent(evt);
			}
		}
	}

	return true;
}
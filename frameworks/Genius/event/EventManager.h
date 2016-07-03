#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "Event.h"
#include <map>
#include <list>
#include "common/Singleton.h"

namespace Genius
{
	class EventManager : public Genius::Singleton<EventManager>
	{
	public:
		static EventManager& GetInstance();
		virtual ~EventManager();
		EventManager();

	public:
		bool Init();
		void Destroy();

		void AddListener(IEventListener* listener, EventType type);

		void RemoveListener(IEventListener* listener, EventType type);

		void AddGlobalListener(IEventListener* listener);

		void RemoveGlobalListener(IEventListener* listener);

		void RemoveAllListeners();

		bool FireEvent(IEventData const &evt) const;

	protected:
		typedef std::list<IEventListener*>		EventListenerList;
		typedef std::map<EventType, EventListenerList>	EventListenerMap;
		typedef std::pair<EventType, EventListenerList>	EventListenerMapPair;

		EventListenerMap			m_listeners;
		EventListenerList			m_globals;
	};
};
#endif
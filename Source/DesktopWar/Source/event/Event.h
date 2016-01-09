#ifndef _EVENT_H_
#define _EVENT_H_

namespace Genius
{
	typedef unsigned int EventType;

	class IEventData
	{
	public:
		IEventData(EventType _type) :
			m_type(_type)
		{}

		EventType		GetType() const
		{
			return m_type;
		}

	private:
		EventType		m_type;
	};

	class IEventListener
	{
	public:
		virtual ~IEventListener(){}
		virtual bool HandleEvent(IEventData const &event) = 0;
	};

};

#endif
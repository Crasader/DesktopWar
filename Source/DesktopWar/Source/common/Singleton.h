#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

namespace Genius
{

	template <typename TYPE>
	class  Singleton
	{
	protected:
		static  TYPE*  m_pMySelf;

	public:
		Singleton()
		{
			assert(m_pMySelf == nullptr);

			m_pMySelf = (TYPE*)this;
		}
		virtual ~Singleton()
		{
			m_pMySelf = nullptr;
		}

	public:
		static  TYPE*  GetSingleton()
		{
			return m_pMySelf;
		}
	};
	template<typename TYPE> TYPE* Singleton<TYPE>::m_pMySelf = nullptr;

};

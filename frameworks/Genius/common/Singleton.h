#pragma once

#include <assert.h>


namespace Genius
{
	template <typename TYPE>
	class  Singleton
	{
	public:
		static  TYPE*  GetSingleton()
		{
			static  TYPE*  pInst = nullptr;
			if (nullptr == pInst)
				pInst = new TYPE();
			return pInst;
		}
	};

};

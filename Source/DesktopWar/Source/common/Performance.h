
#pragma once

namespace Genius
{

	class Performance
	{
	public:
		static void Begin();
		static float End();

	private:
		static int m_tickCountBegin;
	};

};
#ifndef  _GENIUS_IDATAMANAGER_H_
#define  _GENIUS_IDATAMANAGER_H_


#include <string>
#include "TabFile.h"

namespace Genius
{

#pragma pack(push, 1)
	class IData
	{
	public:
		IData(){}
		virtual ~IData(){}

	public:
		virtual  bool  ParseBuffer(TabFile& reader, int row) = 0;
	};
#pragma pack(pop)

	
	class IDataManager
	{
	public:
		IDataManager(){}
		virtual ~IDataManager(){}

	public:
		virtual  bool  Init();
		virtual  void  Destroy() = 0;

	public:
		virtual  std::string   GetName() = 0;
		virtual  int GetSize() = 0;

	protected:
		virtual  bool  LoadData(TabFile& reader, int row) = 0;
	};

};

#endif

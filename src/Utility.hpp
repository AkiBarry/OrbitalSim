#pragma once

#include "Common.hpp"

namespace NUtil
{
	extern DWORD FindPattern( std::string moduleName, std::string pattern );

	template < class T >
	extern T GetVFunc( void* Table, int Index );

	template < class T >
	extern T * CaptureInterface( std::string Module, std::string Interface );
}

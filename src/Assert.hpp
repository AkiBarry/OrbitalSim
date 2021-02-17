#pragma once

#include "DbgFlags.hpp"
#include "Common.hpp"

#ifdef DBG_ASSERT
#define Assert(exp)																		\
	do {																				\
		if (!(exp))																		\
		{ 																				\
																						\
			printf("Assertion Failed: %s at Line %s, %s\n", #exp, __LINE__, __FILE__);	\
																						\
																						\
																						\
		}																				\
	} while (0)			
#else
#define Assert(exp) ((void)0)
#endif // _DEBUG
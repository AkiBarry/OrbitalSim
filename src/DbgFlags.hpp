#pragma once

#undef DBG_ASSERT
#undef DBG_LOG
#undef DBG_CONSOLE

#ifdef _DEBUG
#define DBG_ASSERT
#define DBG_LOG
#define DBG_CONSOLE
#else // _DEBUG
#endif // _DEBUG
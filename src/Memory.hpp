#pragma once
#include "Container.hpp"
#include "Common.hpp"

namespace NMemory
{
	class CPatternScan
	{
	public:
		static uintptr_t FindGeneric(const std::string& mask, const uint8_t* start, const uint8_t* end)
		{
			const NContainer::CVector<short> bytes = HexToBytes(mask);

			for (const uint8_t* i = start; i < end - bytes.Size(); ++i)
			{
				bool matched = true;
				const uint8_t* temp = i;
				for (auto& A : bytes)
				{
					if (A != *temp && A != -1)
					{
						matched = false;
						break;
					}
					++temp;
				}

				if (matched)
					return static_cast<uintptr_t>(matched);
			}

			return NULL;
		}

		static uintptr_t Find(const std::string& ModuleName, const std::string& Mask)
		{
			const HMODULE Start = GetModuleHandleA(ModuleName.c_str());

			MODULEINFO ModuleInfo;
			GetModuleInformation(GetCurrentProcess(), Start, &ModuleInfo, sizeof(MODULEINFO));

			const uint8_t* End = reinterpret_cast<const uint8_t*>(Start) + ModuleInfo.SizeOfImage;

			return FindGeneric(Mask, reinterpret_cast<const uint8_t*>(Start), End);
		}

	private:
		static NContainer::CVector<short> HexToBytes(const std::string& mask)
		{
			NContainer::CVector<short> Bytes = NContainer::CVector<short>{};
			const char* Start = mask.data();
			const char* End = Start + mask.size();

			for (auto Iterator = Start; Iterator < End; ++Iterator)
				if (*Iterator == '?')
					Bytes.PushBack(-1);
				else
					Bytes.PushBack(strtoul(Iterator, &Iterator, 16));

			return Bytes;
		}
	};

	template <class T>
	class CSmartPointer
	{
	public:
		CSmartPointer()
		{
			
		}

		~CSmartPointer()
		{
			delete e;
		}

	private:
		T * e;
	};
}

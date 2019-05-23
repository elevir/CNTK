#pragma once
#include <CNTKLibrary.h>

#ifdef _WIN32
#ifdef CNTKLAYERSLIBRARYDLL
#define CNTK_API __declspec(dllexport)
#else
#define CNTK_API __declspec(dllimport)
#endif
#define _SCL_SECURE_NO_WARNINGS
#else // no DLLs on Linux
#define CNTK_API
#endif

namespace CNTK
{
	namespace Layers
	{
		class ILayer
		{
        protected:
            ILayer() = default;
		public:
            inline virtual FunctionPtr operator()(const Variable& input)
            {
                return nullptr;
            };
		};

	} // namespace Layers
} // namespace CNTK

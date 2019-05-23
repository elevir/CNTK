#pragma once
#include <CNTKLibrary.h>
#include <stack>
#include "ILayer.h"

namespace CNTK
{
	namespace Layers
	{

		class CNTK_API Sequential : public std::stack<ILayer>, public ILayer
		{
		public:
            Sequential(std::initializer_list<ILayer>&& initializer_list);
            FunctionPtr operator()(const Variable& input);
		};

	}
}
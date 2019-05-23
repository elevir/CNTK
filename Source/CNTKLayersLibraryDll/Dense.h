#pragma once
#include "ILayer.h"

namespace CNTK
{
	namespace Layers
	{
		class CNTK_API Dense : public ILayer
		{
		public:
			Dense(size_t outputDim);
            FunctionPtr operator()(const Variable& input);
		
		private:
            size_t _outputDim;
		};
	} // namespace Layers
} // namespace CNTK


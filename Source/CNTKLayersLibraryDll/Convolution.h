#pragma once
#include "ILayer.h"

namespace CNTK
{
	namespace Layers
	{
		
		class CNTK_API Convolution : public ILayer
		{
		public:
            Convolution(std::vector<size_t> filterShape, size_t numOfFilters, std::vector<size_t> strides);
            FunctionPtr operator()(const Variable& input);

		private:
            std::vector<size_t> _filterShape;
            size_t _numOfFilters;
            std::vector<size_t> _strides;
		};

	} // namespace Layers
} // namespace CNTK


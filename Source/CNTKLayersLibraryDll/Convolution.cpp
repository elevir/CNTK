#include "Convolution.h"

using namespace CNTK;
using namespace CNTK::Layers;

Convolution::Convolution(std::vector<size_t> filterShape, size_t numOfFilters, std::vector<size_t> strides) : 
	_filterShape(filterShape), _numOfFilters(numOfFilters), _strides(strides){
    assert(_filterShape.size() == 2);
    assert(strides.size() == 2);
}

FunctionPtr Convolution::operator()(const Variable& input)
{
    NDShape shape(_filterShape);
    Parameter filters(shape.AppendShape({ _numOfFilters }), DataType::Float, HeNormalInitializer());
    Parameter bias({ 1, 1, _numOfFilters }, .0f);
    return CNTK::Convolution(filters, input, _strides);
}
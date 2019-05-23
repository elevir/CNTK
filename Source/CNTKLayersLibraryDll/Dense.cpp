#include "Dense.h"
#include <numeric>

using namespace CNTK;
using namespace Layers;

Dense::Dense(size_t outputDim)
    : _outputDim(outputDim)
{
}

FunctionPtr Dense::operator()(const Variable& input)
{
    auto dims = input.Shape().Dimensions();
    size_t newDim = std::accumulate(dims.begin(), dims.end(), size_t(1), [](size_t a, size_t b) { return a * b; });
    if (input.Shape().Rank() != 1)
    {
        input = Reshape(input, { newDim });
    }
    Parameter weights({ newDim, _outputDim }, DataType::Float, XavierInitializer());
    Parameter bias({ _outputDim }, .0f);
    return Times(input, weights) + bias;
}
#pragma once
#include "ILayer.h"
#include <functional>
#include <opencv2/opencv.hpp>

namespace CNTK
{
namespace Layers
{

class CNTK_API For : public ILayer
{
public:
    For(size_t start, size_t end, std::function<ILayer(size_t i)> body);
    FunctionPtr operator()(const Variable& input);

private:
    std::function<ILayer(size_t i)> _body;
    size_t _start;
    size_t _end;
};
} // namespace Layers
} // namespace CNTK

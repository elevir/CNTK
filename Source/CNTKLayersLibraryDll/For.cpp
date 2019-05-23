#include "For.h"

using namespace CNTK;
using namespace CNTK::Layers;

For::For(size_t start, size_t end, std::function<ILayer(size_t)>body)
    : _start(start), _end(end), _body(body)
{
}

FunctionPtr CNTK::Layers::For::operator()(const Variable& input)
{
    FunctionPtr graph = nullptr;
    for (size_t i = _start; i < _end; ++i)
    {
        if (!graph)
            graph = _body(i)(input);
        else
			graph = _body(i)(graph);
	}
    return graph;
}

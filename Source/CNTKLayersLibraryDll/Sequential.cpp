#include "Sequential.h"
#include <iostream>
#include "CNTKLayers.h"

using namespace CNTK::Layers;

Sequential::Sequential(std::initializer_list<ILayer>&& initializer_list)
    : std::stack<ILayer>(initializer_list)
{
}

CNTK::FunctionPtr Sequential::operator()(CNTK::Variable input)
{
    FunctionPtr graph = nullptr;
    for (auto i = c.begin(); i != c.end(); ++i)
    {
        if (i == c.begin())
        {
            graph = (*i)(input);
        }
        else
        {
            graph = (*i)(graph);
        }
    }
    return graph;
}

void asd()
{
    CNTK::Variable x;
    CNTK::Variable y;

    Sequential block1 {
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Dense(100),
    };

    Sequential block2 {
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        InsertBlock(block1(x)),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Convolution({3, 3}, 16, {1, 1}),
        Dense(100),
    };

    Sequential block3 {
        For(0, 5, [&](size_t i) { return Sequential{block1, block2}; }),
        For(2, 10, [&](size_t i) { return Dense(100); }),
    };

    block3.push(Dense(50));

    
    std::unordered_map<CNTK::Variable, CNTK::ValuePtr> output{{y, nullptr}};
    block3(x)->Evaluate({{x, nullptr}}, output);
}
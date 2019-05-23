#pragma once
#include "ILayer.h"

namespace CNTK
{
namespace Layers
{

class InsertBlock : public ILayer
{
public:
    InsertBlock(FunctionPtr submodel, ParameterCloningMethod cloningMethod = ParameterCloningMethod::Clone);

	FunctionPtr operator()(const Variable& input);

private:
    FunctionPtr m_submodel;
    ParameterCloningMethod m_cloningMethod;
};

} // namespace Layers
} // namespace CNTK
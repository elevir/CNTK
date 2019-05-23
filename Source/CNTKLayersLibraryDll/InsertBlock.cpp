#include "InsertBlock.h"

using namespace CNTK;
using namespace CNTK::Layers;

InsertBlock::InsertBlock(FunctionPtr submodel, ParameterCloningMethod cloningMethod) 
	: m_submodel(submodel), m_cloningMethod(cloningMethod)
{
}

FunctionPtr InsertBlock::operator()(const Variable& input)
{
    return CNTK::AsComposite(m_submodel)->Clone(m_cloningMethod, {{m_submodel->Arguments()[0], input}});
}

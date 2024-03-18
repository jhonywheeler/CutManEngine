#include "InputLayout.h"
#include "Device.h"
#include "DeviceContext.h"

// Método para inicializar el Input Layout

void InputLayout::init(Device device, 
						std::vector<D3D11_INPUT_ELEMENT_DESC> Layout, 
						ID3DBlob* VertexShaderData)
{
	// Verificar si el Input Layout y los datos del VertexShaderData son nulos

	if (Layout.size() == 0)
	{
		WARNING("ERROR: InputLayout::init : Error in data from params [CHECK FOR std::vector<D3D11_INPUT_ELEMENT_DESC> Layout]\n");
		exit(1);
	}
	else if (VertexShaderData == nullptr)
	{
		WARNING("ERROR: InputLayout::init : Error in data from params [CHECK FOR ID3DBlob* VertexShaderData]\n");
		exit(1);
	}
	//Create the resource
	device.CreateInputLayout(Layout.data(),	
							 Layout.size(),
							 VertexShaderData->GetBufferPointer(),
							 VertexShaderData->GetBufferSize(), 
							 &m_inputLayout);
}

void InputLayout::update()
{
}

// Método para aplicar el Input Layout en el Device Context

void 
InputLayout::render(DeviceContext& deviceContext)
{
	deviceContext.IASetInputLayout(m_inputLayout);
}

// Método para liberar recursos del Input Layout

void InputLayout::destroy()
{
	SAFE_RELEASE(m_inputLayout);
}

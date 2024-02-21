#include "DeviceContext.h" 

void DeviceContext::destroy()
{
	m_deviceContext->ClearState();
}

// Limpia la vista de profundidad y stencil
void DeviceContext::ClearDephtStencilView(ID3D11DepthStencilView* pDepthStencilView, unsigned int ClearFlags, float Depth, unsigned int Stencil)
{
	// Verificar si el puntero a la vista de profundidad y stencil es v�lido
	if (pDepthStencilView == nullptr) {
		WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error en los par�metros [VERIFICAR ID311DepthStencilView]\n")
			exit(1); // Salir del programa si hay un error
	}
	else {
		// Limpiar la vista de profundidad y stencil utilizando el contexto del dispositivo
		m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}
}

// M�todo para establecer los recursos de sombreador de p�xel
void DeviceContext::PSSetShaderResources(unsigned int StartSlot, unsigned int NumViews, ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
	// Verificar si el arreglo de recursos de sombreador de p�xel es v�lido
	if (ppShaderResourceViews == nullptr)
	{
		WARNING("ERROR: DeviceContext::PSSetShaderResources : Error en los par�metros [VERIFICAR ID3D11ShaderResourceView* const* ppShaderResourceViews]\n")
			exit(1); // Salir del programa si hay un error
	}
	else {
		// Establecer los recursos de sombreador de p�xel utilizando el contexto del dispositivo
		m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}

void DeviceContext::OMSetRenderTargets(unsigned int NumViews, 
									   ID3D11RenderTargetView* const* ppRenderTargetViews, 
									   ID3D11DepthStencilView* pDepthStencilView)
{
	if (ppRenderTargetViews == nullptr)
	{
		WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los par�metros [VERIFICAR ID3D11RenderTargetView* const* ppRenderTargetViews]\n")
		exit(1); // Salir del programa si hay un error
	}
	else if(pDepthStencilView == nullptr)
	{
		WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los par�metros [VERIFICAR ID3D11DepthStencilView* pDepthStencilView]\n")
		exit(1); // Salir del programa si hay un error
	}
	else
	{
		m_deviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
	}

}

void DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView, 
										  const float ColorRGBA[4])
{
	if (pRenderTargetView == nullptr)
	{
		WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los par�metros [VERIFICAR ID3D11RenderTargetView* pRenderTargetView]\n")
			exit(1); // Salir del programa si hay un error
	}
	else
	{
		m_deviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
	}
}

void DeviceContext::RSSetViewports(unsigned int NumViewports, 
								const D3D11_VIEWPORT* pViewports)
{
	m_deviceContext->RSSetViewports(NumViewports, pViewports);
}



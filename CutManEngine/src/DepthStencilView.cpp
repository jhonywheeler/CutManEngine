#include "DepthStencilView.h" 
#include "Device.h" 
#include "DeviceContext.h" 

void DepthStencilView::init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format)
{
	// Verificar si el dispositivo es válido
	if (device.m_device == nullptr)
	{
		WARNING("ERROR: Device::DepthStencilView::init : Error en los parámetros [VERIFICAR Device device]\n");
		exit(1); // Salir del programa si hay un error
	}
	// Verificar si la vista de profundidad y stencil es válida
	else if (depthStencil == nullptr)
	{
		WARNING("ERROR: Device::DepthStencilView::init Error en los parámetros [VERIFICAR ID3D11Resource* depthStencil]\n");
		exit(1); // Salir del programa si hay un error
	}
	else
	{
		// Configurar la descripción de la vista de profundidad y stencil
		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		memset(&descDSV, 0, sizeof(descDSV));
		descDSV.Format = format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		// Crear la vista de profundidad y stencil utilizando el dispositivo
		device.CreateDepthStencilView(depthStencil, &descDSV, &m_depthStencilView);
	}
}

// Método para actualizar la vista de profundidad y stencil (no implementado en este código)
void DepthStencilView::update()
{
}

// Método para renderizar utilizando la vista de profundidad y stencil
void DepthStencilView::render(DeviceContext& deviceContext)
{
	// Limpiar la vista de profundidad y stencil utilizando el contexto del dispositivo
	deviceContext.ClearDephtStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

// Método para liberar la memoria asignada para la vista de profundidad y stencil
void DepthStencilView::destroy()
{
	// Liberar la memoria de la vista de profundidad y stencil
	SAFE_RELEASE(m_depthStencilView);
}

#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

// Definición de la clase DepthStencilView
class DepthStencilView
{
public:
	DepthStencilView() = default;
	~DepthStencilView() { SAFE_RELEASE(m_depthStencilView); };

	// Inicializa la vista de profundidad y stencil

	void
		init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format);

	// Actualiza la vista de profundidad y stencil (no implementado en este código)

	void
		update();

	// Renderiza la vista de profundidad y stencil (no implementado en este código)

	void
		render(DeviceContext& deviceContext);

	// Libera la memoria asignada para la vista de profundidad y stencil

	void
		destroy();

public:
	// Puntero a la vista de profundidad y stencil

	ID3D11DepthStencilView* m_depthStencilView = nullptr;

};
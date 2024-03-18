#pragma once
#include "Prerequisites.h"

//Forward Declaration

class Device;
class DeviceContext;
class Texture;
class DepthStencilView;

class RenderTargetView
{
public:
	RenderTargetView() = default;
	~RenderTargetView() {};

	// Inicializa la vista de destino del render

	void init(Device device, Texture backBuffer, DXGI_FORMAT Format);

	void update();

	// Renderiza utilizando la vista de destino del render

	void render(DeviceContext & deviceContext,
				DepthStencilView & depthStencilView,
				unsigned int numViews,
				float ClearColor[4]);


	void destroy();
	
public:
	ID3D11RenderTargetView* m_renderTargetView = nullptr;

};



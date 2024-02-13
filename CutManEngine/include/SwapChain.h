#pragma once // Directiva de preprocesador para evitar la inclusi�n m�ltiple del archivo de encabezado

#include "Prerequisites.h" // Incluir la lib "Prerequisites.h"

// Declaraciones de clases
class Device;
class DeviceContext;
class Window;
class Texture;

// Definici�n de la clase SwapChain
class SwapChain
{
public:
	// Constructor y destructor
	SwapChain() = default;
	~SwapChain() { SAFE_RELEASE(m_swapChain) };

	// M�todos p�blicos de la clase SwapChain

	// Inicializa el intercambiador de memoria (swap chain)
	void init(Device& device,
		DeviceContext& deviceContext,
		Texture& backBuffer,
		Window window);

	void update();

	void render();

	void destroy();

	void present();

public:

	// Puntero al intercambiador de memoria DXGI
	IDXGISwapChain* m_swapChain = nullptr;

private:

	// Tipo de controlador de gr�ficos utilizado 
	D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

	// Nivel de caracter�sticas de D3D 
	D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
};

// Constructor de la clase SwapChain 
SwapChain::SwapChain()
{
}

// Destructor de la clase SwapChain 
SwapChain::~SwapChain()
{
}

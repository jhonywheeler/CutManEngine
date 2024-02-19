#pragma once // Directiva de preprocesador para evitar la inclusión múltiple del archivo de encabezado

#include "Prerequisites.h" // Incluir la lib "Prerequisites.h"

// forward declaration o declaracion directa
class Device;
class DeviceContext;
class Window;
class Texture;

// Definición de la clase SwapChain
class SwapChain
{
public:
	// Constructor y destructor
	SwapChain() = default;
	~SwapChain() { SAFE_RELEASE(m_swapChain) };

	// Métodos públicos de la clase SwapChain

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
	// Tipo de controlador de gráficos utilizado 
	D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:

	// Nivel de características de D3D 
	D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
};

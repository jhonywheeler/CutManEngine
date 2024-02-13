#pragma once 

#include "Prerequisites.h" 

// Definición de la clase DeviceContext
class DeviceContext
{
public:
	// Constructor y destructor
	DeviceContext() = default;
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

	// Métodos públicos de la clase DeviceContext

	// Inicializa el contexto del dispositivo
	void init();

	void update();

	void render();

	void destroy();

	// Limpia la vista de profundidad y stencil
	void ClearDephtStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		unsigned int Stencil);

	// Establece los recursos de sombreador de píxel
	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:

	// Puntero al contexto del dispositivo
	ID3D11DeviceContext* m_deviceContext = nullptr;
};

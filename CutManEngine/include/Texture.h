#pragma once
#include "Prerequisites.h" // Incluimos la libreria "Prerequisites.h" 

// Declaraci�n de las clases Device y DeviceContext 
class Device;
class DeviceContext;

// Declaraci�n de la clase Texture
class Texture
{
public:
	// Constructor y destructor
	Texture() = default;
	~Texture();

	// M�todos p�blicos de la clase text

	// Inicializa la text a partir de un archivo de imagen
	void init(Device device, std::string textureName);

	// Inicializa la text con dimensiones y formato espec�ficos
	void init(Device device,
		unsigned int width,
		unsigned int height,
		DXGI_FORMAT Format,
		unsigned int BindFlags);

	// Actualiza la text (este m�todo no est� implementado en el c�digo proporcionado)
	void update();

	// Renderiza la text asign�ndola a un contexto de dispositivo
	void render(DeviceContext& deviceContext, unsigned int StarSlot);

	// Libera la memoria asignada para las text
	void destroy();

public:

	// Puntero a una text creada
	ID3D11Texture2D* m_texture = nullptr;

	// Puntero a una text creada a partir de un archivo de imagen
	ID3D11ShaderResourceView* m_textureFromImg = nullptr;
};


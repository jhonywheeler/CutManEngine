#pragma once
#include "Prerequisites.h"
#include "Texture.h"
#include "Buffer.h"

class Devide;
class DeviceContext;

// Estructura para almacenar los buffers de material

struct
	MaterialBuffer {
	Texture albedo;
	Texture normal;
	Texture metallic;
	Texture ambientOcclusion;
	Texture roughness;
};

// Enumeración para los tipos de textura

enum TextureType {
	NONE = 0,
	ALBEDO,
	NORMAL,
	METALLIC,
	ROUGHNESS,
	SPECULAR,
	AO
};

class
	Material
{
public:
	Material() = default;
	~Material() = default;
	// Funciones para inicializar, actualizar, renderizar y destruir el material
	void
		init(Device device,
			DeviceContext* deviceContext,
			std::unordered_map<TextureType, std::string> textureNames);

	void
		update();

	void
		render(DeviceContext& deviceContext);

	void
		destroy();
private:
	MaterialBuffer m_materialBuffer;
	Buffer* m_constantBuffer;
};

#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"

// Destructor 
Texture::~Texture()
{
	/*
	// Libera memoria si hay una text
	if (m_texture != nullptr)
	{
		SAFE_RELEASE(m_texture);
	}
	// libera la memoria si hay una text imagen
	else if (m_textureFromImg != nullptr)
	{
		SAFE_RELEASE(m_textureFromImg);
	}
	*/
}

// Inicializa una text desde un archivo de imagen
void Texture::init(Device device, std::string textureName)
{
	// Vemos si device es valido
	if (device.m_device == nullptr)
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR Device device]\n");
		exit(1);
	}
	HRESULT hr = S_OK;
	// Crear la text desde el archivo de imagen
	hr = D3DX11CreateShaderResourceViewFromFile(device.m_device,
		textureName.c_str(),
		nullptr,
		nullptr,
		&m_textureFromImg,
		nullptr);
	// Si la operaci�n falla, mostrar un mensaje de error y salir del programa
	if (FAILED(hr))
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR string textureName -> Verificar el nombre de la textura en la ruta de archivo]\n");
		exit(1);
	}
}

// Inicializa una text creada en el momento
void Texture::init(Device device,
	unsigned int width,
	unsigned int height,
	DXGI_FORMAT Format,
	unsigned int BindFlags)
{
	// Verificar si el device es v�lido y si las dimensiones son v�lidas
	if (device.m_device == nullptr)
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR Device device]\n");
		exit(1);
	}
	else if (width <= 0 || height <= 0)
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR unsigned int width O unsigned int height]\n");
		exit(1);
	}
	HRESULT hr = S_OK;

	D3D11_TEXTURE2D_DESC desc;
	memset(&desc, 0, sizeof(desc));
	desc.Width = width;
	desc.Height = height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = Format;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = BindFlags;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	// Crear la text usando el device
	if (BindFlags == D3D11_BIND_DEPTH_STENCIL) {
		hr = device.CreateTexture2D(&desc, nullptr, &m_texture);
	}
	else if (BindFlags == D3D11_BIND_RENDER_TARGET)
	{
		hr = device.CreateTexture2D(&desc, nullptr, &m_texture);
	}

	// Verificar si la text se cre� correctamente
	if (m_texture == nullptr)
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR m_texture]\n");
		exit(1);
	}
	else if (FAILED(hr))
	{
		WARNING("ERROR: Texture::init : Error en los par�metros [VERIFICAR CreateTexture2D]\n");
		exit(1);
	}
}

void Texture::update()
{
}

// Renderiza la text asign�ndola al contexto de device
void Texture::render(DeviceContext& deviceContext, unsigned int StarSlot)
{
	// Si la text proviene de un archivo de imagen
	if (m_textureFromImg != nullptr)
	{
		// Asignar la text al contexto de device para el proceso de renderizaci�n
		ID3D11ShaderResourceView* nullSRV[] = { nullptr };
		deviceContext.PSSetShaderResources(StarSlot, 1, nullSRV);
		deviceContext.PSSetShaderResources(StarSlot, 1, &m_textureFromImg);
	}
}

// Libera la memoria asignada para las text
void Texture::destroy()
{
	// Si existe una text, liberar su memoria
	if (m_texture != nullptr)
	{
		SAFE_RELEASE(m_texture);
	}
	// Si existe una text de imagen, liberar su memoria
	else if (m_textureFromImg != nullptr)
	{
		SAFE_RELEASE(m_textureFromImg);
	}
}

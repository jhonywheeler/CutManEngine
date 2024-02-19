#pragma once
#include "Prerequisites.h" // Incluimos la libreria "Prerequisites.h" 

// Declaración de las clases Device y DeviceContext 
class Device;
class DeviceContext;

/**
*brief: Esta clase textura esta encargada de alamacenar 
* recursos de texturas (Textels)
*/

//Comentar la classe y Metodos

// Declaración de la clase Texture
class Texture
{
public:
	// Constructor y destructor
	Texture() = default;
	~Texture();

	///<summary>
	/// Brief:  Crea una textura a partir de una imagen (.dds) desde nuestro ordenador
	/// </summary>
	/// <param name name="device> llamamos al device para poder generar los recursos en memoria </param>
	/// <paeram name "textureName>: Almacenamos el nombrre de la textura, para cargarla desde memoria. </params>

	// Métodos públicos de la clase text

	// Inicializa la text a partir de un archivo de imagen
	void init(Device device, std::string textureName);

	///<summary>
	/// Brief: Esta funcion esta encargada de crear una textura2d a partir de datos proporcionados
	/// por el desarrollador
	/// </summary>
	/// <param name="device">: Esta encargado de proporcionar los recursos para crear la textura 2d.</param>
	/// <param name="width">: Tomara el ancho de nuestra ventana.</params>
	/// <param name="">: Tomara el alto de nuestra ventana.</params>
	/// <param name="Format">:Es un clasificador que permitira crear los espacios de bits correctamente en la mempria.</params>
	/// <param name="BindFlags">: Es una caracteristica para clasificar el tipo de textura que se esta creando.</params>
	// Inicializa la text con dimensiones y formato específicos
	void init(Device device,
		unsigned int width,
		unsigned int height,
		DXGI_FORMAT Format,
		unsigned int BindFlags);

	// Actualiza la text (este método no está implementado en el código proporcionado) ALT +ENTER
	void update();

	// Renderiza la text asignándola a un contexto de dispositivo
	///<summary>
	/// Este metodo esta encargado de dibujar los recursos en pantalla (solo si es necesario)
	/// </summary>
	/// <param name="deviceContext">Esta encargado de asignar los recursos para ser utilizados.</param>
	/// <params name="StarSlots">Esta encargado de asignar el punto de inicio en memoria. Recomendamos revisar que no se empalme en memoria con otros
	/// recursos
	void render(DeviceContext& deviceContext, unsigned int StarSlot);

	///<summary>
	///Brief: This method is in charge of releasing the resources stored in the class's memory
	/// </summary>
	// Libera la memoria asignada para las text
	void destroy();

public:

	// Puntero a una text creada
	ID3D11Texture2D* m_texture = nullptr;

	// Puntero a una text creada a partir de un archivo de imagen
	ID3D11ShaderResourceView* m_textureFromImg = nullptr;
};


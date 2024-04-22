#pragma once
#include "Prerequisites.h"

class Window
{
public:

	// Constructor de la clase Window

	Window();

	~Window();

	// Destructor de la clase Window

	/// Inicializa la ventana con los par�metros especificados.
	/// \param hInstance - El identificador de la instancia de la aplicaci�n.
	/// \param nCmdShow - Especifica c�mo se mostrar� la ventana.
	/// \param windproc - Puntero a la funci�n del procedimiento de ventana.
	/// \return HRESULT - Resultado de la operaci�n de inicializaci�n.
	
	HRESULT 
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC windproc);
	
	// Funci�n de actualizaci�n, podr�a utilizarse para manejar actualizaciones o eventos

	void 
	update();

	// Funci�n de renderizado, podr�a utilizarse para renderizar gr�ficos

	void
	render();

	// Destruye la ventana y libera los recursos

	void
	Destroy();

public:
	HWND m_hWnd = nullptr;  // Identificador de la ventana
	unsigned int m_width;	// Ancho de la ventana
	unsigned int m_height;  // Altura de la ventana

private:
	HINSTANCE m_hInst = nullptr; // Identificador de la instancia
	RECT m_rect;				  // Estructura de rect�ngulo para la ventana
	std::string m_windowName = "Direct3D 11 Tutorial 7"; //Name Ventana

};


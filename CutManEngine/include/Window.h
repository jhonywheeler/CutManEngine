#pragma once
#include "Prerequisites.h"

class Window
{
public:

	// Constructor de la clase Window

	Window();

	~Window();

	// Destructor de la clase Window

	/// Inicializa la ventana con los parámetros especificados.
	/// \param hInstance - El identificador de la instancia de la aplicación.
	/// \param nCmdShow - Especifica cómo se mostrará la ventana.
	/// \param windproc - Puntero a la función del procedimiento de ventana.
	/// \return HRESULT - Resultado de la operación de inicialización.
	
	HRESULT 
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC windproc);
	
	// Función de actualización, podría utilizarse para manejar actualizaciones o eventos

	void 
	update();

	// Función de renderizado, podría utilizarse para renderizar gráficos

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
	RECT m_rect;				  // Estructura de rectángulo para la ventana
	std::string m_windowName = "Direct3D 11 Tutorial 7"; //Name Ventana

};


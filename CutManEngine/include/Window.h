#pragma once
#include "Prerequisites.h"

class Window
{
public:
	Window();
	~Window();
	/*This metod xd o poner /// Summary*/
	///Summary
	HRESULT 
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC windproc);
	
	void 
	update();

	void
	render();

	void
	Destroy();

public:
	HWND m_hWnd = nullptr;
	unsigned int m_width;
	unsigned int m_height;

private:
	HINSTANCE m_hInst = nullptr;
	RECT m_rect;
	std::string m_windowName = "Direct3D 11 Tutorial 7"; //Name Ventana

};


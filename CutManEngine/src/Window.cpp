#include "Window.h" 

Window::Window()
{
}

Window::~Window()
{
}

// Método para inicializar la ventana
HRESULT Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc)
{
    // Asignar el identificador de instancia de la aplicación
    m_hInst = hInstance;

    // Registrar la clase de la ventana
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndproc; // Asignar el procedimiento de ventana
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1); // Cargar el icono de la ventana
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // Cargar el cursor de la ventana
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Establecer el color de fondo de la ventana
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "TutorialWindowClass"; // Nombre de la clase de la ventana
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1); // Cargar el icono pequeño de la ventana

    // Registrar la clase de ventana
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Crear la ventana
    RECT rc = { 0, 0, 1920, 1080 }; // Tamaño inicial de la ventana
    m_rect = rc;
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE); // Ajustar el tamaño de la ventana
    m_hWnd = CreateWindow("TutorialWindowClass", // Clase de ventana registrada
        "Direct3D 11 Tutorial 7", // Título de la ventana
        WS_OVERLAPPEDWINDOW, // Estilo de la ventana
        CW_USEDEFAULT, CW_USEDEFAULT, // Posición inicial de la ventana
        m_rect.right - m_rect.left, // Ancho de la ventana
        m_rect.bottom - m_rect.top, // Altura de la ventana
        nullptr, // Ventana padre
        nullptr, // Menú
        m_hInst, // Instancia de la aplicación
        nullptr); // Parámetro adicional
    if (!m_hWnd)
        return E_FAIL;

    // Mostrar la ventana
    ShowWindow(m_hWnd, nCmdShow);

    // Obtener el tamaño de cliente de la ventana
    GetClientRect(m_hWnd, &m_rect);
    m_width = m_rect.right - m_rect.left; // Calcular el ancho de la ventana
    m_height = m_rect.bottom - m_rect.top; // Calcular la altura de la ventana

    return S_OK;
}

void Window::update()
{
}

void Window::render()
{
}

void Window::destroy()
{
}

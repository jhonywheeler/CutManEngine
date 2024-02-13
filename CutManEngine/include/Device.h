#pragma once

#include "Prerequisites.h" 

class Device
{
public:
    // Constructor y destructor
    Device() = default;
    ~Device() = default;


    // Método para inicializar el dispositivo (sin implementación en este código)
    void init();

    // Método para actualizar el dispositivo (sin implementación en este código)
    void update();

    // Método para renderizar (sin implementación en este código)
    void render();

    // Método para destruir el dispositivo
    void Destroy();

    // Método para crear una vista de destino de renderizado
    HRESULT CreateRenderTargetView(ID3D11Resource* pResource,
        const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
        ID3D11RenderTargetView** ppRTView);

    // Método para crear una textura 2D
    HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture2D** ppTexture2D);

    // Método para crear una vista de profundidad y stencil
    HRESULT CreateDepthStencilView(ID3D11Resource* pResource,
        const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
        ID3D11DepthStencilView** ppDepthStencilView);

    // Método para crear un sombreador de vértices
    HRESULT CreateVertexShader(const void* pShaderBytecode,
        unsigned int BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11VertexShader** ppVertexShader);

    // Método para crear un diseño de entrada
    HRESULT CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
        unsigned int NumElements,
        const void* pShaderBytecodeWithInputSignature,
        unsigned int BytecodeLength,
        ID3D11InputLayout** ppInputLayout);

    // Método para crear un sombreador de píxeles
    HRESULT CreatePixelShader(const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11PixelShader** ppPixelShader);

    // Método para crear un búfer
    HRESULT CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Buffer** ppBuffer);

    // Método para crear un estado de muestreo
    HRESULT CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
        ID3D11SamplerState** ppSamplerState);

public:
    ID3D11Device* m_device = nullptr; // Puntero al dispositivo de DirectX
};

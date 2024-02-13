#pragma once

#include "Prerequisites.h" 

class Device
{
public:
    // Constructor y destructor
    Device() = default;
    ~Device() = default;


    // M�todo para inicializar el dispositivo (sin implementaci�n en este c�digo)
    void init();

    // M�todo para actualizar el dispositivo (sin implementaci�n en este c�digo)
    void update();

    // M�todo para renderizar (sin implementaci�n en este c�digo)
    void render();

    // M�todo para destruir el dispositivo
    void Destroy();

    // M�todo para crear una vista de destino de renderizado
    HRESULT CreateRenderTargetView(ID3D11Resource* pResource,
        const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
        ID3D11RenderTargetView** ppRTView);

    // M�todo para crear una textura 2D
    HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture2D** ppTexture2D);

    // M�todo para crear una vista de profundidad y stencil
    HRESULT CreateDepthStencilView(ID3D11Resource* pResource,
        const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
        ID3D11DepthStencilView** ppDepthStencilView);

    // M�todo para crear un sombreador de v�rtices
    HRESULT CreateVertexShader(const void* pShaderBytecode,
        unsigned int BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11VertexShader** ppVertexShader);

    // M�todo para crear un dise�o de entrada
    HRESULT CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
        unsigned int NumElements,
        const void* pShaderBytecodeWithInputSignature,
        unsigned int BytecodeLength,
        ID3D11InputLayout** ppInputLayout);

    // M�todo para crear un sombreador de p�xeles
    HRESULT CreatePixelShader(const void* pShaderBytecode,
        SIZE_T BytecodeLength,
        ID3D11ClassLinkage* pClassLinkage,
        ID3D11PixelShader** ppPixelShader);

    // M�todo para crear un b�fer
    HRESULT CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Buffer** ppBuffer);

    // M�todo para crear un estado de muestreo
    HRESULT CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
        ID3D11SamplerState** ppSamplerState);

public:
    ID3D11Device* m_device = nullptr; // Puntero al dispositivo de DirectX
};

#pragma once
#include "Prerequisites.h"

class
	DeviceContext {
public:
	DeviceContext() = default;
	~DeviceContext() { SAFE_RELEASE(m_deviceContext) };

	void
		init();

	void
		update();

	void
		render();

	void
		destroy();

	// Dibuja primitivas indexadas, no instanciadas.
	void
		DrawIndexed(unsigned int IndexCount,
			unsigned int StartIndexLocation,
			unsigned int BaseVertexLocation);

	// Establece una matriz de estados de muestreo en la etapa del pipeline del sombreador de píxeles.
	void
		PSSetSamplers(unsigned int StartSlot,
			unsigned int NumSamplers,
			ID3D11SamplerState* const* ppSamplers);

	// Vincula una matriz de recursos de sombreador a la etapa de sombreador de píxeles.
	void
		PSSetShaderResources(unsigned int StartSlot,
			unsigned int NumViews,
			ID3D11ShaderResourceView* const* ppShaderResourceViews);

	// Establece los búferes constantes utilizados por la etapa del pipeline del sombreador de píxeles.
	void
		PSSetConstantBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppConstantBuffers);

	// Establece un sombreador de píxeles en el dispositivo.
	void
		PSSetShader(ID3D11PixelShader* pPixelShader,
			ID3D11ClassInstance* const* ppClassInstances,
			unsigned int NumClassInstances);

	// Establece los búferes constantes utilizados por la etapa del pipeline del sombreador de vértices.
	void
		VSSetConstantBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppConstantBuffers);

	// Establece un sombreador de vértices en el dispositivo.
	void
		VSSetShader(ID3D11VertexShader* pVertexShader,
			ID3D11ClassInstance* const* ppClassInstances,
			unsigned int NumClassInstances);

	// Limpia el recurso de DepthStencil
	void
		ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
			unsigned int ClearFlags,
			float Depth,
			unsigned int Stencil);

	// Establece todos los elementos en un destino de renderización a un valor.
	void
		ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
			const float ColorRGBA[4]);

	// Vincula uno o más destinos de renderización atómicamente y el búfer de profundidad y estencil a la etapa de combinación de salida.

	void
		OMSetRenderTargets(unsigned int NumViews,
			ID3D11RenderTargetView* const* ppRenderTargetViews,
			ID3D11DepthStencilView* pDepthStencilView);

	//Bind an array of viewports to the rasterizer stage of the pipeline.
	void
		RSSetViewports(unsigned int NumViewports,
			const D3D11_VIEWPORT* pViewports);

	//Bind an input-layout object to the input-assembler stage.
	void
		IASetInputLayout(ID3D11InputLayout* pInputLayout);

	// Vincula una matriz de vistas a la etapa de rasterización del pipeline.
	void
		IASetVertexBuffers(unsigned int StartSlot,
			unsigned int NumBuffers,
			ID3D11Buffer* const* ppVertexBuffers,
			const unsigned int* pStrides,
			const unsigned int* pOffsets);

	// Vincula un objeto de diseño de entrada a la etapa de ensamblador de entrada.
	void
		IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
			DXGI_FORMAT Format,
			unsigned int Offset);

	// Vincula información sobre el tipo de primitiva y el orden de datos que describe los datos de entrada para la etapa de ensamblador de entrada.

	void
		IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

	// La CPU copia datos de la memoria a un subrecurso creado en memoria no mapeable.
	void
		UpdateSubresource(ID3D11Resource* pDstResource,
			unsigned int DstSubresource,
			const D3D11_BOX* pDstBox,
			const void* pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch);

public:
	// La interfaz ID3D11DeviceContext representa un contexto de dispositivo que genera comandos de renderización.
	ID3D11DeviceContext* m_deviceContext = nullptr;
};

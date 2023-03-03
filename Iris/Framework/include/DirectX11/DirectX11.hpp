#pragma once

// Direct3Dのライブラリを使用できるようにする
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

// Direct3Dの型・クラス・関数などを呼べるようにする
#include <d3d11.h>

// DirectXMath(数学ライブラリ)を使用できるようにする
#include <DirectXMath.h>

// ComPtrを使用できるようにする
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

#include <Iris/Common/Numeric.hpp>
#include <Iris/Common/Singleton.hpp>

namespace Iris
{
	CLASS_IRIS_ENGINE(DirectX11)
	{
	public:

		bool createWindow(HWND hWnd, int32 width, int32 height);

		void clearRenderTargetView(float32 _color[4]);

		void draw()const;

	private:

		// Direct3Dデバイス
		ComPtr<ID3D11Device> m_device;
		// Direct3Dデバイスコンテキスト
		ComPtr<ID3D11DeviceContext>	m_deviceContext;
		// スワップチェイン
		ComPtr<IDXGISwapChain> m_swapChain;
		// バックバッファーのRTビュー
		ComPtr<ID3D11RenderTargetView> m_backBufferView;

		friend class Singleton<Managements>;

	};
}
#pragma once

// Direct3D�̃��C�u�������g�p�ł���悤�ɂ���
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

// Direct3D�̌^�E�N���X�E�֐��Ȃǂ��Ăׂ�悤�ɂ���
#include <d3d11.h>

// DirectXMath(���w���C�u����)���g�p�ł���悤�ɂ���
#include <DirectXMath.h>

// ComPtr���g�p�ł���悤�ɂ���
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

		// Direct3D�f�o�C�X
		ComPtr<ID3D11Device> m_device;
		// Direct3D�f�o�C�X�R���e�L�X�g
		ComPtr<ID3D11DeviceContext>	m_deviceContext;
		// �X���b�v�`�F�C��
		ComPtr<IDXGISwapChain> m_swapChain;
		// �o�b�N�o�b�t�@�[��RT�r���[
		ComPtr<ID3D11RenderTargetView> m_backBufferView;

		friend class Singleton<Managements>;

	};
}
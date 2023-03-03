#include <DirectX11/DirectX11.hpp>

namespace Iris
{
	bool Iris_DirectX11::createWindow(HWND hWnd, int32 width, int32 height)
	{
		//=====================================================
		// �t�@�N�g���[�쐬(�r�f�I �O���t�B�b�N�̐ݒ�̗񋓂�w��Ɏg�p�����I�u�W�F�N�g)
		//=====================================================
		ComPtr<IDXGIFactory> factory;

		if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&factory))))
		{
			return false;
		}

		//=====================================================
		//�f�o�C�X����(��Ƀ��\�[�X�쐬���Ɏg�p����I�u�W�F�N�g)
		//=====================================================
		UINT creationFlags = 0;

#ifdef _DEBUG
		// DEBUG�r���h����Direct3D�̃f�o�b�O��L���ɂ���
		// (�������d�����ׂ����G���[���킩��)
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_1,	// Direct3D 11.1  ShaderModel 5
			D3D_FEATURE_LEVEL_11_0,	// Direct3D 11    ShaderModel 5
			D3D_FEATURE_LEVEL_10_1,	// Direct3D 10.1  ShaderModel 4
			D3D_FEATURE_LEVEL_10_0,	// Direct3D 10.0  ShaderModel 4
			D3D_FEATURE_LEVEL_9_3,	// Direct3D 9.3   ShaderModel 3
			D3D_FEATURE_LEVEL_9_2,	// Direct3D 9.2   ShaderModel 3
			D3D_FEATURE_LEVEL_9_1,	// Direct3D 9.1   ShaderModel 3
		};

		// �f�o�C�X�ƂŃf�o�C�X�R���e�L�X�g���쐬
		D3D_FEATURE_LEVEL futureLevel;
		if (FAILED(D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			creationFlags,
			featureLevels,
			_countof(featureLevels),
			D3D11_SDK_VERSION,
			&m_device,
			&futureLevel,
			&m_deviceContext)))
		{
			return false;
		}

		//=====================================================
		// �X���b�v�`�F�C���쐬(�t�����g�o�b�t�@�ɕ\���\�ȃo�b�N�o�b�t�@��������)
		//=====================================================
		DXGI_SWAP_CHAIN_DESC scDesc = {};		// �X���b�v�`�F�[���̐ݒ�f�[�^
		scDesc.BufferDesc.Width = width;						// ��ʂ̕�
		scDesc.BufferDesc.Height = height;						// ��ʂ̍���
		scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// �o�b�t�@�̌`��
		scDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		scDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		scDesc.BufferDesc.RefreshRate.Numerator = 0;
		scDesc.BufferDesc.RefreshRate.Denominator = 1;
		scDesc.SampleDesc.Count = 1;							// MSAA�͎g�p���Ȃ�
		scDesc.SampleDesc.Quality = 0;							// MSAA�͎g�p���Ȃ�
		scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// �o�b�t�@�̎g�p���@
		scDesc.BufferCount = 2;									// �o�b�t�@�̐�
		scDesc.OutputWindow = hWnd;
		scDesc.Windowed = TRUE;									// �E�B���h�E���[�h
		scDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		scDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		// �X���b�v�`�F�C���̍쐬
		if (FAILED(factory->CreateSwapChain(m_device.Get(), &scDesc, &m_swapChain)))
		{
			return false;
		}

		// �X���b�v�`�F�C������o�b�N�o�b�t�@���\�[�X�擾
		ComPtr<ID3D11Texture2D> pBackBuffer;
		if (FAILED(m_swapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer))))
		{
			return false;
		}

		// �o�b�N�o�b�t�@���\�[�X�p��RTV���쐬
		D3D11_RENDER_TARGET_VIEW_DESC rtvDesc = {};
		rtvDesc.Format = scDesc.BufferDesc.Format;
		rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		if (FAILED(m_device->CreateRenderTargetView(pBackBuffer.Get(), &rtvDesc, &m_backBufferView)))
		{
			return false;
		}

		//=====================================================
		// �f�o�C�X�R���e�L�X�g�ɕ`��Ɋւ���ݒ���s���Ă���
		//=====================================================

		// �o�b�N�o�b�t�@��RT�Ƃ��ăZ�b�g
		m_deviceContext->OMSetRenderTargets(1, m_backBufferView.GetAddressOf(), nullptr);

		// �r���[�|�[�g�̐ݒ�
		D3D11_VIEWPORT vp = { 0.0f, 0.0f, (float)width, (float)height, 0.0f, 1.0f };
		m_deviceContext->RSSetViewports(1, &vp);

		return true;
	}

	void Iris_DirectX11::clearRenderTargetView(float32 _color[4])
	{
		m_deviceContext->ClearRenderTargetView(m_backBufferView.Get(), _color);
	}

	void Iris_DirectX11::draw() const
	{
		m_swapChain->Present(1, 0);
	}
}
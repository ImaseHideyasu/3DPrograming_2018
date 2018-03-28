//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

// �L�[�{�[�h���g�����߂ɕK�v�ȃw�b�_
#include <Keyboard.h>

// �}�E�X���g�����߂ɕK�v�ȃw�b�_
#include <Mouse.h>

// �X�v���C�g���g�����߂ɕK�v�ȃw�b�_
#include <SpriteBatch.h>

// �f�o�b�O�p�t�H���g���g�����߂ɕK�v�ȃw�b�_
#include <SpriteFont.h>

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	// �L�[�{�[�h�I�u�W�F�N�g�ւ̃��j�[�N�|�C���^
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	// �}�E�X�I�u�W�F�N�g�ւ̃��j�[�N�|�C���^
	std::unique_ptr<DirectX::Mouse> m_mouse;

	// �X�v���C�g�o�b�`�ւ̃��j�[�N�|�C���^
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	// �X�v���C�g�t�H���g�ւ̃��j�[�N�|�C���^
	std::unique_ptr<DirectX::SpriteFont> m_font;
};

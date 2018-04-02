//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

// キーボードを使うために必要なヘッダ
#include <Keyboard.h>

// マウスを使うために必要なヘッダ
#include <Mouse.h>

// コメンステートを使うために必要なヘッダ
#include <CommonStates.h>

// スプライトを使うために必要なヘッダ
#include <SpriteBatch.h>

// デバッグ用フォントを使うために必要なヘッダ
#include <SpriteFont.h>

// テクスチャを読み込むために必要なヘッダ
#include <WICTextureLoader.h>

// VectorやMatrixを使うために必要なヘッダ
#include <d3d11.h>
#include <SimpleMath.h>

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

	/// <summary>
	/// キーボードオブジェクトへのユニークポインタ 
	/// </summary>
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	/// <summary>
	/// マウスオブジェクトへのユニークポインタ 
	/// </summary>
	std::unique_ptr<DirectX::Mouse> m_mouse;

	/// <summary>
	/// コモンステートオブジェクトへのポインタ
	/// </summary>
	std::unique_ptr<DirectX::CommonStates> m_states;

	/// <summary>
	/// スプライトバッチへのユニークポインタ
	/// </summary>
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	/// <summary>
	/// スプライトフォントへのユニークポインタ
	/// </summary>
	std::unique_ptr<DirectX::SpriteFont> m_font;

	/// <summary>
	/// テクスチャハンドル
	/// </summary>
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
};

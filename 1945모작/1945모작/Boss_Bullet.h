#pragma once
#include "GameObject.h"

class CBoss_Bullet : public CGameObject
{
public:
	CBoss_Bullet();
	virtual ~CBoss_Bullet();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:

	const TCHAR*			m_pFrameKey;

	float					m_fMIN_X = 30.f;
	float					m_fMIN_Y = 30.f;

	float					m_fMAX_X = 580.f;
	float					m_fMAX_Y = 850.f;

	int						m_iMoveRange;
	int						m_iFrameCnt;

	PLAYER_BULLET			m_eBulletKind;

};


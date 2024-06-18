#include "pch.h"
#include "Boss_Bullet.h"
#include "Bmp_Manager.h"

CBoss_Bullet::CBoss_Bullet()
{

}

CBoss_Bullet::~CBoss_Bullet()
{

	

}

void CBoss_Bullet::Initialize()
{
	m_tInfo.fCX = 8.f;
	m_tInfo.fCY = 8.f;
	m_fSpeed = 3.f;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 500;
	m_tFrame.dwTime = GetTickCount64();
	m_pFrameKey = L"MINI_GUN_BULLET";
}

int CBoss_Bullet::Update()
{
	m_tInfo.fX += m_vDirection.x * m_fSpeed;
	m_tInfo.fY += m_vDirection.y * m_fSpeed;


	if (m_bDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CBoss_Bullet::Late_Update()
{
	
}

void CBoss_Bullet::Render(HDC hDC)
{
	HDC	BOSSBULLETDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(
		hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,					// ������� Y��ġ
		(int)m_tInfo.fY - m_tInfo.fCY / 2,
		(int)m_tInfo.fCX,									// ���� ���� ���� ����
		(int)m_tInfo.fCY,									// ���� ���� ���� ����
		BOSSBULLETDC,											// ������ ��Ʈ�� DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,			// ��Ʈ�� ��� X��ǥ
		0,													// ��Ʈ�� ��� Y��ǥ
		(int)m_tInfo.fCX,									// ������ ��Ʈ���� ���� ����
		(int)m_tInfo.fCY,									// ������ ��Ʈ���� ���� ����
		RGB(255, 255, 255));
}

void CBoss_Bullet::Release(void)
{
	
}

void CBoss_Bullet::Set_Direction(float x, float y)
{
	m_vDirection = Vector2(x, y).normalize();
}

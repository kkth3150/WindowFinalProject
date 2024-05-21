#include "pch.h"
#include "Player_Bullet.h"
#include "Bmp_Manager.h"


CPlayer_Bullet::CPlayer_Bullet()
{
	
}

CPlayer_Bullet::~CPlayer_Bullet()
{
}

void CPlayer_Bullet::Initialize()
{

	m_fSpeed = 15.f;
	Motion_Change();
	switch (m_eBulletKind) {
	case PB_NORMAL:
		m_tInfo.fCX = 24.f;
		m_tInfo.fCY = 72.f;
		//CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/MainBullet/MainBullet(24X72X4).bmp", L"MAINBULLET_IMAGE");
		m_pFrameKey = L"MAINBULLET_IMAGE";

		break;

	case PB_LSUB:
		m_tInfo.fCX = 24.f;
		m_tInfo.fCY = 63.f;
		//CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SubBullet/SubBullet(24X63X4).bmp", L"SUBBULLET_IMAGE");
		m_pFrameKey = L"SUBBULLET_IMAGE";
		break;

	case PB_RSUB:
		m_tInfo.fCX = 24.f;
		m_tInfo.fCY = 63.f;
		//CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SubBullet/SubBullet(24X63X4).bmp", L"SUBBULLET_IMAGE");
		m_pFrameKey = L"SUBBULLET_IMAGE";
		break;


	case PB_LSIDE:
		m_tInfo.fCX = 24.f;
		m_tInfo.fCY = 42.f;
		//CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SideBullet/SideBullet_LEFT(24X42X4).bmp", L"SIDELBULLET_IMAGE");
		m_pFrameKey = L"SIDELBULLET_IMAGE";
		break;

	case PB_RSIDE:
		m_tInfo.fCX = 24.f;
		m_tInfo.fCY = 42.f;
		//CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Bullet/PlayerBullet/SideBullet/SideBullet_RIGHT(24X42X4).bmp", L"SIDERBULLET_IMAGE");
		m_pFrameKey = L"SIDERBULLET_IMAGE";
		break;

	default:
		break;

	}


}

int CPlayer_Bullet::Update()
{


	if (m_iMoveRange > 900) {
		m_bDead = true;
	}

	if (m_bDead)
		return OBJ_DEAD;
	


	switch (m_eBulletKind) {
	case PB_NORMAL:
		m_tInfo.fY -= m_fSpeed;
		m_iMoveRange += m_fSpeed;
		break;

	case PB_LSUB:
		m_tInfo.fX -= m_fSpeed * cos(88.f * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sin(88.f * PI / 180.f);
		m_iMoveRange += m_fSpeed;

		break;

	case PB_RSUB:
		m_tInfo.fX += m_fSpeed * cos(88.f * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sin(88.f * PI / 180.f);
		m_iMoveRange += m_fSpeed;
		break;

	case PB_LSIDE:
		m_tInfo.fX -= m_fSpeed * cos(80.f * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sin(80.f * PI / 180.f);
		m_iMoveRange += m_fSpeed;
		break;

	case PB_RSIDE:
		m_tInfo.fX += m_fSpeed * cos(80.f * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sin(80.f * PI / 180.f);
		m_iMoveRange += m_fSpeed;
		break;

	default:
		break;

	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer_Bullet::Late_Update()
{
	__super::Move_Frame();

}

void CPlayer_Bullet::Render(HDC hDC)
{
	//Rectangle(hDC, m_tInfo.fX - m_tInfo.fCX / 2, m_tInfo.fY - m_tInfo.fCY / 2, m_tInfo.fX + m_tInfo.fCX / 2, m_tInfo.fY + m_tInfo.fCY / 2);
	HDC	BULLETDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(
		hDC,
		m_tRect.left,										// ������� X��ġ
		m_tRect.top,										// ������� Y��ġ
		(int)m_tInfo.fCX,									// ���� ���� ���� ����
		(int)m_tInfo.fCY,									// ���� ���� ���� ����
		BULLETDC,											// ������ ��Ʈ�� DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,			// ��Ʈ�� ��� X��ǥ
		0,													// ��Ʈ�� ��� Y��ǥ
		(int)m_tInfo.fCX,									// ������ ��Ʈ���� ���� ����
		(int)m_tInfo.fCY,									// ������ ��Ʈ���� ���� ����
		RGB(255, 255, 255));

}

void CPlayer_Bullet::Release(void)
{
}

void CPlayer_Bullet::Motion_Change()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount64();
}

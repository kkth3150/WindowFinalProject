#include "pch.h"
#include "Boss_Gun.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"

CBoss_Gun::CBoss_Gun()
{
}

CBoss_Gun::~CBoss_Gun()
{
}

void CBoss_Gun::Initialize()
{
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Boss/mini_28X28X16.bmp", L"MINI_GUN");
	m_pFrameKey = L"MINI_GUN";
	m_tInfo.fCX = 28.f;
	m_tInfo.fCY = 28.f;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 15;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 20;
	m_tFrame.dwTime = GetTickCount64();
}

int CBoss_Gun::Update()
{
	m_fBossPosX = CObject_Manager::Get_Instance()->Get_List(OBJ_BOSS)->front()->Get_Info().fX;
	m_fBossPosY = CObject_Manager::Get_Instance()->Get_List(OBJ_BOSS)->front()->Get_Info().fY;

	switch (m_iGun_Num) {
	case 0:
		m_tInfo.fX = m_fBossPosX - 457.f;
		m_tInfo.fY = m_fBossPosY - 46.f;
		break;

	case 1:
		m_tInfo.fX = m_fBossPosX - 495.f;
		m_tInfo.fY = m_fBossPosY - 18.f;
		break;

	case 2:
		m_tInfo.fX = m_fBossPosX - 495.f;
		m_tInfo.fY = m_fBossPosY + 10.f;
		break;

	case 3:
		m_tInfo.fX = m_fBossPosX - 457.f;
		m_tInfo.fY = m_fBossPosY + 36.f;
		break;

	case 4:
		m_tInfo.fX = m_fBossPosX - 199.f;
		m_tInfo.fY = m_fBossPosY - 58.f;
		break;

	case 5:
		m_tInfo.fX = m_fBossPosX - 199.f;
		m_tInfo.fY = m_fBossPosY + 47.f;
		break;

	case 6:
		m_tInfo.fX = m_fBossPosX + 22.f;
		m_tInfo.fY = m_fBossPosY - 68.f;
		break;

	case 7:
		m_tInfo.fX = m_fBossPosX + 22.f;
		m_tInfo.fY = m_fBossPosY + 57.f;
		break;

	case 8:
		m_tInfo.fX = m_fBossPosX + 75.f;
		m_tInfo.fY = m_fBossPosY - 68.f;
		break;

	case 9:
		m_tInfo.fX = m_fBossPosX + 75.f;
		m_tInfo.fY = m_fBossPosY + 57.f;
		break;

	case 10:
		m_tInfo.fX = m_fBossPosX + 495.f;
		m_tInfo.fY = m_fBossPosY + 50.f;
		break;
	
	case 11:
		m_tInfo.fX = m_fBossPosX + 495.f;
		m_tInfo.fY = m_fBossPosY - 61.f;
		break;

	default:

		break;
	}

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CBoss_Gun::Late_Update()
{
	__super::Move_Frame();
}

void CBoss_Gun::Render(HDC hDC)
{
	HDC GunDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//복사 받을 X 위치
		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//복사 받을 Y 위치
		28,									//복사 받을 가로 길이
		28,									//복사 받을 세로 길이
		GunDC,							//복사할 비트맵 DC
		28 * m_tFrame.iFrameStart,					//비트맵 이미지의 왼쪽 X 좌표
		0,									//비트맵 이미지의 위쪽 Y 좌표
		m_tInfo.fCX,						//복사할 이미지의 가로 사이즈 
		m_tInfo.fCY,						//복사할 이미지의 세로 사이즈
		RGB(255, 255, 255));
}

void CBoss_Gun::Release(void)
{
}


void CBoss_Gun::Motion_Change()
{
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 20;
	m_tFrame.dwTime = GetTickCount64();
}


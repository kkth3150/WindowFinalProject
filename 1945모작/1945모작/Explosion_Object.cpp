#include"pch.h"
#include "Explosion_Object.h"
#include "Bmp_Manager.h"

CExplosion_Object::CExplosion_Object()
{
}

CExplosion_Object::~CExplosion_Object()
{
}

void CExplosion_Object::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_fSpeed = 0.f;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 27;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 50;
	m_tFrame.dwTime = GetTickCount64();
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Medium_Explosion(50X50X28ea).bmp", L"EXPLO");
	m_pFrameKey = L"EXPLO";
	m_bDead = false;

}

int CExplosion_Object::Update()
{
	if (m_tFrame.iFrameStart == 26)
		m_bDead = true;

	__super::Update_Rect();

	if (m_bDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;


}

void CExplosion_Object::Late_Update()
{
	__super::Move_Frame();
}

void CExplosion_Object::Render(HDC hDC)
{
	if (!m_bDead) {
		HDC	ExplosionDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

		GdiTransparentBlt(
			hDC,
			(int)m_tInfo.fX - m_tInfo.fCX / 2,					// ������� Y��ġ
			(int)m_tInfo.fY - m_tInfo.fCY / 2,
			(int)m_tInfo.fCX,									// ���� ���� ���� ����
			(int)m_tInfo.fCY,									// ���� ���� ���� ����
			ExplosionDC,											// ������ ��Ʈ�� DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,			// ��Ʈ�� ��� X��ǥ
			0,													// ��Ʈ�� ��� Y��ǥ
			(int)m_tInfo.fCX,									// ������ ��Ʈ���� ���� ����
			(int)m_tInfo.fCY,									// ������ ��Ʈ���� ���� ����
			RGB(255, 255, 255));


	}
}

void CExplosion_Object::Release(void)
{
}

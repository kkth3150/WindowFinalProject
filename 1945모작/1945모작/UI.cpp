#include "pch.h"
#include "UI.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"
#include "Player.h"

CUI::CUI()
{
}

CUI::~CUI()
{
	Release();
}

void CUI::Initialize()
{
}

int CUI::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CUI::Late_Update()
{

	switch (m_eUIState) {
	case UI_NONANIM:
		break;

	case UI_ANIM:
		__super::Move_Frame();
		break;

	case UI_SCORE:
		m_iScore = dynamic_cast<CPlayer*>(CObject_Manager::Get_Instance()->Get_Player())->Get_Score();
		break;

	case UI_LIFE:
		m_iLife = dynamic_cast<CPlayer*>(CObject_Manager::Get_Instance()->Get_Player())->Get_Life();
		break;

	default:
		break;
	}
}

void CUI::Render(HDC hDC)
{
	HDC	hMemDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);
	switch (m_eUIState) {
	case UI_NONANIM:

		GdiTransparentBlt(
			hDC,
			m_tRect.left,
			m_tRect.top,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDC,
			0,
			0,
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));

		break;

	case UI_ANIM:

		GdiTransparentBlt(
			hDC,
			m_tRect.left,										// ������� X��ġ
			m_tRect.top,										// ������� Y��ġ
			(int)m_tInfo.fCX,									// ���� ���� ���� ����
			(int)m_tInfo.fCY,									// ���� ���� ���� ����
			hMemDC,											// ������ ��Ʈ�� DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,			// ��Ʈ�� ��� X��ǥ
			0,													// ��Ʈ�� ��� Y��ǥ
			(int)m_tInfo.fCX,									// ������ ��Ʈ���� ���� ����
			(int)m_tInfo.fCY,									// ������ ��Ʈ���� ���� ����
			RGB(255, 255, 255));

		break;

	case UI_SCORE:
		Render_ScoreImage(hDC, hMemDC);
		break;

	case UI_LIFE:
		Render_LifeImage(hDC, hMemDC);
		break;

	default:
		break;

	}
	
}

void CUI::Release(void)
{
}


void CUI::Set_State(UISTATE eState)
{
	m_eUIState = eState;
}

void CUI::Render_ScoreImage(HDC hDC, HDC hMemDC)
{
	//�����ڸ�
	GdiTransparentBlt(
		hDC,
		175,					
		20,						
		47,						
		47,
		hMemDC,					
		0,
		(m_iScore % 10) * 47,	
		46,						
		46, RGB(255, 255, 255));

	//�����ڸ�
	GdiTransparentBlt(
		hDC,
		135,
		20,
		47,
		47,
		hMemDC,
		0,
		(m_iScore % 100 / 10) * 47,
		46,
		46, RGB(255, 255, 255));

	//�����ڸ�
	GdiTransparentBlt(
		hDC,
		95,
		20,
		47,
		47,
		hMemDC,
		0,
		((m_iScore % 1000) / 100) * 47,
		46,
		46, RGB(255, 255, 255));
	
	//õ���ڸ�
		GdiTransparentBlt(
		hDC,
		55,
		20,
		47,
		47,
		hMemDC,
		0,
		((m_iScore % 10000) / 1000) * 47,
		46,
		46, RGB(255, 255, 255));
	
	//�����ڸ�
		GdiTransparentBlt(
		hDC,
		15,
		20,
		47,
		47,
		hMemDC,
		0,
		(m_iScore / 10000) * 47,
		46,
		46, RGB(255, 255, 255));
}

void CUI::Render_LifeImage(HDC hDC, HDC hMemDC)
{

	GdiTransparentBlt(
		hDC,
		20,
		70,
		(m_iLife) * 30,
		40,
		hMemDC,
		0,
		0,
		(m_iLife) * 30,
		40, RGB(255, 255, 255));


}

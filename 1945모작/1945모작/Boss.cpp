#include "pch.h"
#include "Boss.h"
#include "Bmp_Manager.h"
#include "Object_Manager.h"
#include "AbstractFactory.h"

CBoss::CBoss()
{
}

CBoss::~CBoss()
{
}

void CBoss::Initialize()
{
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Boss/BossNormal.bmp", L"BOSS_IDLE");
	CBmp_Manager::Get_Instance()->Insert_Bmp(L"../Image/Boss/BossEnd.bmp", L"BOSS_DEAD");
	
	Set_Init_Boss_Parts();

	m_pFrameKey = L"BOSS_IDLE";
	m_tInfo.fX = 1000.f;
	m_tInfo.fY = 800.f;
	m_tInfo.fCX = 1365.f;
	m_tInfo.fCY = 166.f;
	m_fSpeed = 3.f;
}

int CBoss::Update()
{
	if(m_tInfo.fX<600){
		m_tInfo.fX -= m_fSpeed;
	}
	
	__super::Update_Rect();


	return OBJ_NOEVENT;
}

void CBoss::Late_Update()
{
	__super::Move_Frame();
}

void CBoss::Render(HDC hDC)
{
	HDC PlayerDC = CBmp_Manager::Get_Instance()->Find_Img(m_pFrameKey);

	//Rectangle(hDC, m_tInfo.fX - m_tInfo.fCX / 2, m_tInfo.fY - m_tInfo.fCY / 2, m_tInfo.fX + m_tInfo.fCX / 2, m_tInfo.fY + m_tInfo.fCY / 2);
	//�ǰ� ������ Rect => ���� �ʿ�

	GdiTransparentBlt(hDC,
		(int)m_tInfo.fX - m_tInfo.fCX / 2,	//���� ���� X ��ġ
		(int)m_tInfo.fY - m_tInfo.fCY / 2,	//���� ���� Y ��ġ
		1365,								//���� ���� ���� ����
		166,								//���� ���� ���� ����
		PlayerDC,							//������ ��Ʈ�� DC
		0,									//��Ʈ�� �̹����� ���� X ��ǥ
		0,									//��Ʈ�� �̹����� ���� Y ��ǥ
		m_tInfo.fCX,						//������ �̹����� ���� ������ 
		m_tInfo.fCY,						//������ �̹����� ���� ������
		RGB(255, 255, 255));
}

void CBoss::Release(void)
{
}

void CBoss::Set_Init_Boss_Parts()
{

	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(0));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(1));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(2));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(3));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(4));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(5));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Posin>::CreatePosin(6));

	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(0));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(1));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(2));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(3));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(4));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(5));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(6));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(7));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(8));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(9));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(10));
	CObject_Manager::Get_Instance()->Add_Object(OBJ_BOSSPART, CAbstractFactory<CBoss_Gun>::CreateGun(11));
}

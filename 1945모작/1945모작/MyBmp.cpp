#include "pch.h"
#include "MyBmp.h"

CMyBmp::CMyBmp()
{
}

CMyBmp::~CMyBmp()
{
	Release();
}

void CMyBmp::Load_Bmp(const TCHAR* pFilePath)
{
	HDC		hDC = GetDC(g_hWnd);
	m_hMemDC = CreateCompatibleDC(hDC);

	ReleaseDC(g_hWnd, hDC);

	m_hBitmap = (HBITMAP)LoadImage(NULL,		// ���α׷� �ν��Ͻ��� �ڵ�, �̹����� ���α׷����� ������ ���� �ƴ϶� ���Ϸκ��� �о�� ���̱� NULL�� ����
		pFilePath,  // ������ ���
		IMAGE_BITMAP, // � Ÿ���� �о���� ���� 
		0,	// �̹����� ���� ũ��
		0,	// �̹����� ���� ũ��
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);  // LR_LOADFROMFILE : ���Ͽ��� �̹����� �ҷ����ڴٴ� �ǹ�, LR_CREATEDIBSECTION : �о�� ������ DIB ���·� ��ȯ

	// SelectObject : GDI ������Ʈ�� �����ϱ� ���� ������ ������ �ִ� ������Ʈ�� ��ȯ
	m_hOldBmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldBmp);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}

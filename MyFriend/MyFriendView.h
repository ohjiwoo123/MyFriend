
// MyFriendView.h: CMyFriendView 클래스의 인터페이스
//

#pragma once
//#include "CPerson.h"
#include <vector>

class CMyFriendView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMyFriendView() noexcept;
	DECLARE_DYNCREATE(CMyFriendView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MYFRIEND_FORM };
#endif

// 특성입니다.
public:
	CMyFriendDoc* GetDocument() const;

// 작업입니다.

public:
	int m_nCount;

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//virtual void Serialize(CArchive& ar);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMyFriendView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	int m_nAge;
	int m_nGender;


	CSpinButtonCtrl m_Ctrl_Spin;
	CListCtrl m_Control_Friend;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedRemove();

};

#ifndef _DEBUG  // MyFriendView.cpp의 디버그 버전
inline CMyFriendDoc* CMyFriendView::GetDocument() const
   { return reinterpret_cast<CMyFriendDoc*>(m_pDocument); }
#endif


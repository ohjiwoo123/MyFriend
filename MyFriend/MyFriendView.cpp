
// MyFriendView.cpp: CMyFriendView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MyFriend.h"
#endif

#include "MyFriendDoc.h"
#include "MyFriendView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyFriendView

IMPLEMENT_DYNCREATE(CMyFriendView, CFormView)

BEGIN_MESSAGE_MAP(CMyFriendView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_ADD, &CMyFriendView::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_LOAD, &CMyFriendView::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_SAVE, &CMyFriendView::OnBnClickedSave)
	ON_BN_CLICKED(IDC_REMOVE, &CMyFriendView::OnBnClickedRemove)
END_MESSAGE_MAP()

// CMyFriendView 생성/소멸

CMyFriendView::CMyFriendView() noexcept
	: CFormView(IDD_MYFRIEND_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_strName = _T("");
	m_nAge = 0;
	m_nGender = 0;
	m_nCount = 0;
}


CMyFriendView::~CMyFriendView()
{
}

void CMyFriendView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_AGE, m_nAge);
	DDX_Radio(pDX, IDC_RADIO, m_nGender);
	DDX_Control(pDX, IDC_SPIN, m_Ctrl_Spin);
	DDX_Control(pDX, IDC_LIST, m_Control_Friend);	
}

BOOL CMyFriendView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMyFriendView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_Control_Friend.InsertColumn(0, _T("이름"), 0, 100);
	m_Control_Friend.InsertColumn(1, _T("나이"), 2, 200);
	m_Control_Friend.InsertColumn(2, _T("성별"), 0, 100);

	m_Ctrl_Spin.SetRange(0, 100);
	m_Ctrl_Spin.SetPos(0);

	static CImageList imgListSmall;
	imgListSmall.Create(16, 16, ILC_COLOR32, 2, 0);	// 방은 5개
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_Control_Friend.SetImageList(&imgListSmall, LVSIL_SMALL);


	DWORD dwStyle = m_Control_Friend.GetExtendedStyle();
	m_Control_Friend.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

}


// CMyFriendView 인쇄

BOOL CMyFriendView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMyFriendView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMyFriendView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMyFriendView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMyFriendView 진단

#ifdef _DEBUG
void CMyFriendView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyFriendView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMyFriendDoc* CMyFriendView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFriendDoc)));
	return (CMyFriendDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyFriendView 메시지 처리기

void CMyFriendView::OnBnClickedAdd()
{
	///////////////////////////////////
	if (m_nCount >= 5)
	{
		AfxMessageBox(_T("더 이상 입력 할 수 없습니다."));
		return;
	}

	///////////////////////////////////
	//1. 사용자 입력 값을 읽어온다.(이름,나이,성별 from DDX) 컨트롤 --> 변수
	UpdateData(1);

	///////////////////////////////////
	// 2. 그 값들을 화면(리스트컨트롤)에 한명 추가한다.
	//int image = 0;	
	// int -> string
	m_Control_Friend.InsertItem(0, m_strName);
	//m_Control_Friend.InsertItem(0, m_strName, image);

	CString strTemp;
	strTemp.Format(_T("%d"), m_nAge);
	m_Control_Friend.SetItemText(0, 1, strTemp);

	if (m_nGender == 0) {

		m_Control_Friend.SetItemText(0, 2, _T("남성"));
		//image = 1;
	}
	else
	{

		m_Control_Friend.SetItemText(0, 2, _T("여성"));
		//image = 0;
	}
	

	///////////////////////////////////
	// 3. 그 값들을 메모리(배열)에 한 명 추가한다.
	m_pPerson[m_nCount].m_nAge = m_nAge;
	m_pPerson[m_nCount].m_nGender = m_nGender;
	m_pPerson[m_nCount].m_strName = m_strName;
	
	m_nCount++;
	
	///////////////////////////////////
	//UpdateData(0);
}



void CMyFriendView::OnBnClickedLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog a(TRUE); // 저장모드
	int nResult = a.DoModal();
	if (nResult != IDOK)
	{
		return;
	}

	CFile file(a.GetPathName(),
		CFile::modeReadWrite);

	CArchive ar(&file, CArchive::load);

	ar >> m_nCount;
	for (int i = 0; i < m_nCount; i++)
	{
		m_pPerson[i].Serialize(ar);
	}

	for (int i = 0; i < m_nCount; i++)
	{
		m_Control_Friend.InsertItem(i, m_pPerson[i].m_strName);
		CString strTemp;
		strTemp.Format(_T("%d"), m_pPerson[i].m_nAge);
		m_Control_Friend.SetItemText(i, 1, strTemp);
		if (m_pPerson[i].m_nGender == 0)
			m_Control_Friend.SetItemText(i, 2, _T("남성"));
		else
			m_Control_Friend.SetItemText(i, 2, _T("여성"));
	}
	//////////////////////////////
	// 메모리와 화면을 초기화한다.(지우기)
	//m_nCount = 0; // 메모리초기화
	//m_Control_Friend.DeleteAllItems(); // 화면 초기화

}


void CMyFriendView::OnBnClickedSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog a(FALSE); // 저장모드
	int nResult = a.DoModal();
	if (nResult != IDOK)
	{
		return;
	}

	CFile file(a.GetPathName(),
		CFile::modeCreate | CFile::modeReadWrite);

	CArchive ar(&file, CArchive::store);

	ar << m_nCount;
	for (int i = 0; i < m_nCount; i++)
	{
		m_pPerson[i].Serialize(ar);
	}

}


void CMyFriendView::OnBnClickedRemove()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = m_nCount - 1; i >= 0; i--)
	{
		if (m_Control_Friend.GetCheck(i) == TRUE)
		{
			m_Control_Friend.DeleteItem(i);
		}
	}
}

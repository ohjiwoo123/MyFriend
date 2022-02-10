# MyFriend (주소록 실습)

## CPerson Class 만들기
```
// CPerson.h
#pragma once  // 어떠한 코드나 헤더파일이 다른 코드나 헤더에서 include 될때, 중복되어 복사되는 것을 방지하는 기능을 한다.
#include <afx.h>

class CPerson : public CObject
{
public:
    CPerson();
    ~CPerson();
```
```
// CPerson.cpp
#include "pch.h"
#include "CPerson.h"

CPerson::CPerson()
{
	int m_nAge=0;
	int m_nGender=0;
	CString m_strName=_T("");
}

CPerson::~CPerson()
{
}

void CPerson::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
}
```
CPerson 사용하려면  
내가 사용할 헤더에서 (현재의 경우 MyFriendView.h)  
```
// MyFriendView.h
#pragma once
#include "CPerson.h"
```
해줘야 한다.  
## Serialize 함수 
CArchive Class를 사용하며 기본적인 구조는 아래와 같다.
```
void CPerson::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_nAge;
		ar << m_nGender;
		ar << m_strName;
	}
	else
	{	// loading code
		ar >> m_nAge;
		ar >> m_nGender;
		ar >> m_strName;
	}
}
```
## 2022-02-09 vector로 데이터 변환 완료 (저장,불러오기 완료)
**유의사항**  
```
vector<Friend> myFriendList;
ar << (int)myFriendList.size();
```
여기서 `myFriendList.size();`의 데이터 타입이 size_t로 크기가 8바이트이다. (int는 4바이트)  
그래서 처음에 count 값을 넣고 load해서 카운트 값을 읽으면 처음의 count 숫자 값은 제대로 읽어오나,  
그 뒤에 값들이 load가 올바르게 되지 않는다.

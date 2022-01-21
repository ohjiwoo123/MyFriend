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
???
## 기타 등등

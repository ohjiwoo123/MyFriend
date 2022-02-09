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

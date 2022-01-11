#pragma once
#include <afx.h>

class CPerson : public CObject
{
public:
    CPerson();
    ~CPerson();

    int m_nAge;
    int m_nGender;
    CString m_strName;

    virtual void Serialize(CArchive& ar);
};


#pragma once
#include <afx.h>
#include <vector>
class CPerson : public CObject
{
public:
    CPerson();
    ~CPerson();

    int m_nAge;
    int m_nGender;
    CString m_strName;

    virtual void Serialize(CArchive& ar);

    //CPerson(const CPerson&) = default;
    //CPerson& operator=(const CPerson&) = default;
    //CPerson(const CPerson&) = default;
    //CPerson& operator=(const CPerson&) = default;
    //CPerson& operator=(CPerson&&) = default;
    //CPerson(CPerson&&) = default;

};


//
// Created by chxxi on 2023-02-13.
//

#include "CMyString.h"
//#include<string.h>
//#include<cstring>

//CMyString::CMyString()
//{
//
//}

//CMyString::~CMyString()
//{
//    delete [] m_pszData;
//}

//복사 생성자
CMyString::CMyString(const CMyString& rhs)
{
    m_nLength = rhs.GetLength();
    m_pszData = new char[m_nLength + 1];
    strncpy(m_pszData, rhs.m_pszData, m_nLength + 1);
}


//변환 생성자
CMyString::CMyString(const char* pszParam)
{
    m_nLength = strlen(pszParam);
    m_pszData = new char[m_nLength+1];
    strncpy(m_pszData, pszParam, m_nLength+1);
}

//MyString -> char*로 변환 연산자
//CMyString::operator char* () const
//{
//    return m_pszData;
//}

//이동 생성자 - shallow copy
CMyString::CMyString(CMyString&& rhs)
{
    m_nLength = rhs.m_nLength;
    m_pszData = rhs.m_pszData;

    //이동 생성자 호출로 생성되는 객체의 원본 instance member들은 모두 초기화
    //-> 해당 생성자 call한 statement가 종료되면 원본 소멸
    rhs.m_nLength = 0;
    rhs.m_pszData = nullptr;
}


//대입 연산자
CMyString& CMyString::operator= (const CMyString& rhs)
{
    strcpy(m_pszData, rhs.m_pszData);

    return *this;
}

//const int CMyString::GetLength() const
//{
//    return m_nLength;
//}

void CMyString::SetString(const char *pszParam)
{
    //기존 정보 해제
    Release();

    //0. 예외처리1
    // 입력 data에 대한 유효성 확인 - callee에서 수행
    //nullptr이 입력된 예외 처리
    if(pszParam == nullptr)
    {
        throw nullptr;
    }

    //1. pszParam으로 받은 문자배열 길이 파악
    //-> strnlen()으로 하면 기준 뭐로 잡아야할까?
    m_nLength = strlen(pszParam);

    //1-1. 예외처리2
    //문자배열 길이==0 case
    if(m_nLength == 0)
    {
          throw 0;
    }

    //2. '1.'에서 파악한 길이의 문자배열 동적할당 + deep copy
    // b. branch 사용하여 동적할당 전에 이전 문자열 소멸시키기 --> Release로 대체
/*
    if(m_pszData != nullptr)
    {
        delete [] m_pszData;
        m_pszData = nullptr;
    }
*/
    m_pszData = new char[m_nLength+1];
    //strcpy_s(m_pszData, sizeof(char) * (m_nLength+1), pszParam);
    strncpy(m_pszData, pszParam, m_nLength+1);
   // m_pszData = pszParam;
   pszParam = nullptr;

}

//const char *CMyString::GetString() const
//{
//    return m_pszData;
//}

//전체 member data 초기화
void CMyString::Release()
{
    //double free방지
    //if(m_pszData != nullptr)
    //{
        delete [] m_pszData;
    //}

    //member data 초기화
    m_pszData = nullptr;
    m_nLength = 0;
}


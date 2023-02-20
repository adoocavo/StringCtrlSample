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

CMyString::~CMyString()
{
    delete [] m_pszData;
}

//복사 생성자
CMyString::CMyString(const CMyString& rhs)
{
    /*
    m_nLength = rhs.GetLength();
    m_pszData = new char[m_nLength + 1];
    strncpy(m_pszData, rhs.m_pszData, m_nLength + 1);
*/
    //this->SetString(rhs.GetString());
    *this = rhs;
}


//변환 생성자
CMyString::CMyString(const char* pszParam)
{
    /*
    m_nLength = strlen(pszParam);
    m_pszData = new char[m_nLength+1];
    strncpy(m_pszData, pszParam, m_nLength+1);
    */
    this->SetString(pszParam);
}

//MyString -> char*로 변환 연산자
//CMyString::operator char* () const
//{
//    return m_pszData;
//}

//이동 생성자 - shallow copy
CMyString::CMyString(CMyString&& rhs) noexcept(true)
{
    /*
    m_nLength = rhs.m_nLength;
    m_pszData = rhs.m_pszData;

    //이동 생성자 호출로 생성되는 객체의 원본 instance member들은 모두 초기화
    //-> 해당 생성자 call한 statement가 종료되면 원본 소멸
    rhs.m_nLength = 0;
    rhs.m_pszData = nullptr;
    */
    //(*this).operator=(rhs);
    *this = std::move(rhs);
}

//대입(복사) 연산자
CMyString& CMyString::operator= (const CMyString& rhs)
{
/*
    strcpy(m_pszData, rhs.m_pszData);
    return *this;
*/
    if(this != &rhs)
    {
        this->SetString(rhs.GetString());
    }

    return *this;
}

//const int CMyString::GetLength() const
//{
//    return m_nLength;
//}

//이동 연산자
CMyString& CMyString::operator= (CMyString &&rhs)
{
    m_nLength = rhs.m_nLength;
    m_pszData = rhs.m_pszData;

    //이동 생성자 호출로 생성되는 객체의 원본 instance member들은 모두 초기화
    //-> 해당 생성자 call한 statement가 종료되면 원본 소멸
    rhs.m_nLength = 0;
    rhs.m_pszData = nullptr;

    return *this;
}

//'obj + obj' 연산자
CMyString CMyString::operator+(const CMyString& rhs)
{
    //1. 정답 리턴할 객체 생성
    CMyString result{*this};

    //2. Append() 실행
    result.Append(rhs.m_pszData);

    //3. return
    return result;                  //copy elision or move constructor call
}

// 'char* + obj'연산자
CMyString operator+(const char *pszParam, const CMyString &rhs)
{
    //1. 정답 리턴할 객체 생성
    CMyString result{rhs};

    //2. Append() 실행
    result.Append(pszParam);

    //3. return
    return result;                  //copy elison or mover constructor
}


//"obj += obj" 연산자
CMyString& CMyString::operator+=(const CMyString& rhs)
{
    this->Append(rhs.m_pszData);

    return *this;                       //임시객체 생성X
}

//[] 연산자 - const 객체와 binding(read only)
const char CMyString::operator[] (const int index) const
{
    CheckIndex(index);
    return *(m_pszData + index);
}

//[] 연산자 - nonConst 객체와 binding(RW)
char& CMyString::operator[] (const int index)
{
    CheckIndex(index);
    return *(m_pszData + index);
}

// == 연산자
const int CMyString::operator==(const CMyString & rhs) const
{
    //0.각 instance의 m_pszData 유효성 검사
    if(m_pszData != nullptr && rhs.m_pszData != nullptr)
    {
        if(strcmp(this->m_pszData, rhs.m_pszData) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// != 연산자
const int CMyString::operator!=(const CMyString &rhs) const
{
    //0.각 instance의 m_pszData 유효성 검사
    if(m_pszData != nullptr && rhs.m_pszData != nullptr)
    {
        if(strcmp(this->m_pszData, rhs.m_pszData) != 0)
        {
            return 1;
        }
    }

    return 0;
}


// 문자열/문자열 길이 Setting
void CMyString::SetString(const char *pszParam)
{

    //0. 기존 정보 해제
    Release();
/*
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
*/

/*
    //2. '1.'에서 파악한 길이의 문자배열 동적할당 + deep copy
    // b. branch 사용하여 동적할당 전에 이전 문자열 소멸시키기 --> Release로 대체

    if(m_pszData != nullptr)
    {
        delete [] m_pszData;
        m_pszData = nullptr;
    }
*/
    //1. param 유효성 확인 && 문자열 길이 측정
    m_nLength = CheckPszParam(pszParam);

    //2. 동적할당 && deep copy
    m_pszData = new char[m_nLength+1];
    strncpy(m_pszData, pszParam, m_nLength+1);

    //pszParam = nullptr;
/*
    //strcpy_s(m_pszData, sizeof(char) * (m_nLength+1), pszParam);
    // m_pszData = pszParam;
*/

    // 참조/포인터로 호출시에 실 형식의 method 호출
    OnSetString(m_pszData, m_nLength);

}

//const char *CMyString::GetString() const
//{
//    return m_pszData;
//}


//전체 member data 초기화
void CMyString::Release()
{
    //double free 방지
    //if(m_pszData != nullptr || m_nLength != 0)
    if(m_pszData != nullptr)
    {
        delete [] m_pszData;
        m_pszData = nullptr;
    }

    //member data 초기화
    //m_pszData = nullptr;
    m_nLength = 0;
}

//문자열 + 문자열
const char* CMyString::Append(const char* pszParam)
{

    //0. parma 유효성 확인 && param 길이 확인
    const int paramLength = CheckPszParam(pszParam);

    //1.this->m_pszData == nullptr인 경우 다른 처리
    if(m_pszData == nullptr)
    {
            this->SetString(pszParam);
            return this->m_pszData;
    }

    //2. 문자열 길이 다시 setting (newLength, newPszData)
    // int paramLength = strlen(pszParam);
    const int curLength = this->GetLength();
    const int newLength = curLength + paramLength;

    //3. caller instance 문자열 길이 + (pszParam 문자얄 길이 +1) 로 동적할당
    char* newPszData = new char[newLength + 1];

    //4. 동적할당 공간에 copy
    strncpy(newPszData, this->m_pszData, curLength);
    strncpy(newPszData + sizeof(char) * curLength,
            pszParam, paramLength+1);

    //5. 기존 instance 정보 삭제(기존 m_pszData delete -> newPszData 값 대입 -> newPszData nullptr)
    Release();

    //shallow copy
    m_pszData = newPszData;
    newPszData = nullptr;

    m_nLength = newLength;

    return m_pszData;
}

//문자열 param 유효성 확인 메서드
const int CMyString::CheckPszParam(const char* pszParam) const
{
    //0. 예외처리1
    // 입력 data에 대한 유효성 확인 - callee에서 수행
    //nullptr이 입력된 예외 처리
    if(pszParam == nullptr)
    {
        throw nullptr;
    }

    //1. pszParam으로 받은 문자배열 길이 파악
    //-> strnlen()으로 하면 기준 뭐로 잡아야할까?
    int checkLength = strlen(pszParam);

    //1-1. 예외처리2
    //문자배열 길이==0 case
    if(checkLength == 0)
    {
        throw 0;
    }

    return checkLength;
}

//index 범위 확인 메서드
void CMyString::CheckIndex(const int paramIndex) const
{
    if(m_nLength <= paramIndex)
    {
        throw "SIGSEGV: Index Out Of Range";
    }
}


//
// Created by chxxi on 2023-02-13.
//

#ifndef STRINGCTRLSAMPLE_CMYSTRING_H
#define STRINGCTRLSAMPLE_CMYSTRING_H
#include<iostream>
using namespace std;

class CMyString
{
    // 기본 생성자/소멸자/대입/이동연산자 삽입

    public:
        CMyString() = default;
        ~CMyString(){    delete [] m_pszData;   }
        CMyString(const CMyString&);
        explicit CMyString(const char*);
        CMyString(CMyString&&);

        CMyString& operator= (const CMyString&);
        explicit operator char*() const { return m_pszData; }



    private:
        //문자열을 저장하기 위해 동적 할당된 메모리를 가리키는 포인터
        char* m_pszData = nullptr;
        //shared_ptr<char> m_spSzData = nullptr;

        //저장된 문자열의 길이
        int m_nLength = 0;

    public:
        const int GetLength () const { return m_nLength; };
        void SetString(const char *pszParam);
        const char* GetString() const { return m_pszData; }
        void Release();

};


#endif //STRINGCTRLSAMPLE_CMYSTRING_H

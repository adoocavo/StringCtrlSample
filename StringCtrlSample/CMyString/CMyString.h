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
        virtual ~CMyString();
        CMyString(const CMyString&);
        explicit CMyString(const char*);
        CMyString(CMyString&&) noexcept(true);

        CMyString& operator= (const CMyString&);
        CMyString& operator= (CMyString&&);
        explicit operator char*() const { return m_pszData; }
        CMyString& operator+= (const CMyString&);
        CMyString operator+ (const CMyString&);
        const char operator[](const int index) const;
        char& operator[](const int index);
        const int operator== (const CMyString&) const;
        const int operator!= (const CMyString&) const;
        friend CMyString operator+ (const char*, const CMyString&);


    private:
        //문자열을 저장하기 위해 동적 할당된 메모리를 가리키는 포인터
        char* m_pszData = nullptr;
        //shared_ptr<char> m_sdpSzData = nullptr;

        //저장된 문자열의 길이
        int m_nLength = 0;

    public:
        const int GetLength () const { return m_nLength; };
        /*virtual*/ void SetString(const char*);
        const char* GetString() const { return m_pszData; }
        void Release();
        const char* Append(const char*);
        const int CheckPszParam(const char*) const;
        void CheckIndex(const int) const;

        //SetString() method에 미래에 추가되는 기능 고려
        virtual void OnSetString(char*, const int) {;}
};



#endif //STRINGCTRLSAMPLE_CMYSTRING_H

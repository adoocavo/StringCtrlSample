//
// Created by chxxi on 2023-02-13.
//

#ifndef STRINGCTRLSAMPLE_CMYSTRING_H
#define STRINGCTRLSAMPLE_CMYSTRING_H
#include<iostream>
using namespace std;

class CMyString
{
    public:
        CMyString();
        ~CMyString();

    private:
        //문자열을 저장하기 위해 동적 할당된 메모리를 가리키는 포인터
        char* m_pszData;

        //저장된 문자열의 길이
        int m_nLength;

    public:
        int SetString(char *pszParam);
        const char* GetString();
        void Release();

};


#endif //STRINGCTRLSAMPLE_CMYSTRING_H

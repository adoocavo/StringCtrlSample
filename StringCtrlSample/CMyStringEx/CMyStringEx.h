//
// Created by KHANG JU CHOI on 2023/02/18.
//

#ifndef STRINGCTRLSAMPLE_CMYSTRINGEX_H
#define STRINGCTRLSAMPLE_CMYSTRINGEX_H
#include"../CMyString/CMyString.h"

class CMyStringEx : public CMyString
{
public:
    //생성자들&&대입 연산자는 상속받지X
    using CMyString::CMyString;
    using CMyString::operator=;

    const int Find(const char*) const;
/*
    //문자열 필터 기능추가1
    //=> base class의 기존 method가 derived class에서 재정의한
    // method 내에서 call back 되는 구조 만들기
    virtual void SetString(const char *);
*/
    //문자열 필터 기능추가2
    //=> derived class에서 재정의한 method가 base class의 기존 method
    // 내에서 call back 되는 구조 만들기
    virtual void OnSetString(char*, const int);


};

#endif //STRINGCTRLSAMPLE_CMYSTRINGEX_H

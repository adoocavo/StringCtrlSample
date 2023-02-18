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
    virtual void SetString(const char *);

};

#endif //STRINGCTRLSAMPLE_CMYSTRINGEX_H

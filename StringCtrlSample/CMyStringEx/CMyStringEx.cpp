//
// Created by KHANG JU CHOI on 2023/02/18.
//

#include "CMyStringEx.h"

//입력 문자열 검색 메서드
const int CMyStringEx::Find(const char *pszParam) const
{
    //0. pszParam 유호성 점검
    if(GetString() != nullptr && pszParam != nullptr)
    {
        //1. 문자열 추출
        const char* pszResult = strstr(this->GetString(), pszParam);

        if(pszResult != nullptr)
        {
            return pszResult - GetString();
        }
    }
    return -1;
}

void CMyStringEx::SetString(const char *pszParam)
{
    //0.특정 단어 필터링 기능만 추가
    if(strcmp(pszParam, "fuck") == 0)
    {
        //1-1. 언어 필터링 이후 direct base class의 SetString() method call
        CMyString::SetString("f**k");
    }

    else
    {
        //1-1. 필터링 필요X -> direct base class의 SetString() method call
        CMyString::SetString(pszParam);
    }

}

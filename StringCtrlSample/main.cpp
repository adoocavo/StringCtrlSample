//사용자 code
//StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점
#include"CMyString/CMyString.h"

//inline void TestFunc(const CMyString &param)
//{
//    cout << param.GetString() << endl;
//}

inline void TestFunc_ch4(const CMyString& strParam)
{
    //cout << strParam << endl;
    cout << (char*)strParam << endl;
}

int main(int argc, char* argv[])
{

    CMyString strData;
    CMyString strData_ch4;
    try
    {
        strData.SetString(" ");
        cout << strData.GetString() << endl;
        strData.SetString("Hello");
        cout << strData.GetString() << endl;
        strData.SetString("lklkkl");
        cout << strData.GetString() << endl;
        strData.Release();
//        strData.SetString(nullptr);
//        cout << strData.GetString() << endl;

        strData_ch4.SetString("Hello");
        ::TestFunc_ch4(strData_ch4);
        ::TestFunc_ch4(CMyString{"World"});
        //::TestFunc_ch4("World");

    }

    catch(char* errNullptr)
    {
        cout << "NULL입력됨" << endl;
    }

    catch(int error_length0)
    {
        cout << "길이가 0" << endl;
    }
    return 0;
}

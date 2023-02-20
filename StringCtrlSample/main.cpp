//사용자 code
//StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점
#include"CMyString/CMyString.h"
#include"CMyStringEx/CMyStringEx.h"
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

    //CMyString strData;
    //CMyStringEx strTest{"Test for conversion constructor"};

//    CMyString strData_ch4;
//    CMyString strData_ch5_1;
//    const CMyString strData_ch5_2;

    try
    {
/*
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
*/

/*
        strData_ch5_1.SetString("Hello");
        const CMyString strData_ch5_2{"world"};

        cout << (char*)strData_ch5_1 << endl;
        cout << (char*)strData_ch5_2 << endl;

        cout << strData_ch5_1[0] <<endl;
        cout << strData_ch5_1[strData_ch5_1.GetLength()-1] << endl;

        cout << strData_ch5_2[0] <<endl;
        cout << strData_ch5_2[strData_ch5_2.GetLength()-1] << endl;

      //  cout << strData_ch5_1[strData_ch5_1.GetLength()] << endl;
        cout << strData_ch5_2[strData_ch5_2.GetLength()] << endl;
*/

/*
    CMyStringEx strTest;
    strTest.SetString("I am a boy");
    cout << (char*)strTest << endl;

    int nIndex = strTest.Find("am");
    cout << "Index : " << nIndex << endl;
*/

/*  10번 실습
    CMyString* strTest_10 = new CMyStringEx;
    strTest_10->SetString("fuck");
    cout << (char*)(*strTest_10) << endl;
*/
//    CMyStringEx strTest{"Test for conversion constructor"};

/*
    CMyString* strTest_12 = new CMyStringEx;
    strTest_12->SetString("fuck");

    cout << (char*)(*strTest_12) << endl;

    delete strTest_12;
*/
    CMyString a{"Hello"}, b;
    b = " world" + a;

    cout << (char*)b << endl;
    }

    catch(const char* errMsg)
    {
        if(errMsg == nullptr)
        {
            cout << "잘못된 접근 : nullptr access" << endl;
        }

        else
        {
            cout << errMsg << endl;
        }
    }

    catch(const int errInt)
    {
        cout << errInt << endl;
    }
    return 0;
}

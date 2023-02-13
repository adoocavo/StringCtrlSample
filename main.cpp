//사용자 code
//StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점
#include"CMyString/CMyString.h"

int main(int argc, char* argv[])
{
    CMyString strData;
    strData.SetString("Hello");
    cout << strData.GetString() << endl;

    return 0;
}

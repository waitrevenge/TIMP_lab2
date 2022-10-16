#include <iostream>
#include <cctype>
#include "Sergienko.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        TiMP cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = tolower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"САМСУНГ",L"ЭПЛ");
    check(L"САМСУНГ",L"");
    check(L"САМСУНГ",L"7ЭПЛ7");
    check(L"С А М С У Н Г",L"ЭПЛ");
    check(L"123",L"САМСУНГ");
}

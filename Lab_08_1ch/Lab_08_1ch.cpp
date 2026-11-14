// Програма за допомогою стандартних функцій мови C (strstr, strncat, strcat)
// перевіряє наявність "!!!" у рядку та замінює кожну трійку на "**".
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Пошук підрядка "!!!" за допомогою strstr()
bool Include(const char* str)
{
    return strstr(str, "!!!") != nullptr;
}

// Заміна підрядків "!!!" на "**" за допомогою strstr(), strncat(), strcat()
char* Change(char* dest, const char* str)
{
    dest[0] = '\0';
    const char* pos = str;
    const char* p;

    while ((p = strstr(pos, "!!!")) != nullptr)
    {
        strncat(dest, pos, p - pos);
        strcat(dest, "**");
        pos = p + 3;
    }
    strcat(dest, pos);
    return dest;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str))
        cout << "Yes, string contains '!!!'" << endl;
    else
        cout << "No, string does not contain '!!!'" << endl;

    char dest[101];
    Change(dest, str);
    cout << "Modified string: " << dest << endl;

    return 0;
}
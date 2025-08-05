#include <iostream>
#include <map>

using namespace std;

int roman_to_int(string s)
{
    map<string, int> symtoval = {
                                    {"M", 1000},
                                    {"CM", 900},
                                    {"D", 500},
                                    {"CD", 400},
                                    {"C", 100},
                                    {"XC", 90},
                                    {"L", 50},
                                    {"XL", 40},
                                    {"X", 10},
                                    {"IX", 9},
                                    {"V", 5},
                                    {"IV", 4},
                                    {"I", 1}
    };

    string ans;
    int i = 0;
    int num = 0;

    while (s[i])
    {
        if ((s[i] == 'C') && (s[i+1] == 'M' || s[i+1] == 'D'))
        {
            ans = s[i];
            ans += s[i+1];
            i += 2;    
        }
        else if((s[i] == 'X') && (s[i+1] == 'C' || s[i+1] == 'L'))
        {
            ans = s[i];
            ans += s[i+1];
            i += 2;
        }
        else if ((s[i] == 'I') && (s[i+1] == 'V' || s[i+1] == 'X'))
        {
            ans = s[i];
            ans += s[i+1];
            i += 2;
        }
        else
        {
            ans = s[i];
            i++;
        }
        num += symtoval[ans];
    }

    return num;
}

int main()
{

    int num = roman_to_int("MCMIIIV");
    cout << num << endl;
    return 0;
}
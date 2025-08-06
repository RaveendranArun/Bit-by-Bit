#include <iostream>
#include <map>

using namespace std;

string int_to_roman(int n)
{
    
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4,1};
    string sym[]= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans;
    int i = 0;
    int num = 0;

    while (n)
    {
        while (n >= val[i])
        {
            ans += sym[i];
            n -= val[i];
        }
        i++;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;  
    string ans = int_to_roman(n);
    cout << ans << endl;
    return 0;
}
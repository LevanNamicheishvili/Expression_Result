#include <bits/stdc++.h>
using namespace std;

string twoDigitSumer(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res = "";

    while (i >= 0 || j >= 0 || carry)
    {
        long sum = 0;
        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        res = char(sum + '0') + res;
    }

    return res;
}

string twoDigiSubtraction(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;

    int borrow = 0;
    string res = "";

    while (i >= 0 || j >= 0 || borrow)
    {
        int digitA = 0;
        int digitB = 0;
        if (i >= 0)
        {
            digitA = a[i] - '0';
        }

        if (j >= 0)
        {
            digitB = b[j] - '0';
        }

        digitA -= borrow;

        if (digitA < digitB)
        {
            digitA += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        res = char(digitA - digitB + '0') + res;

        i--;
        j--;
    }
    while(res.size() > 1 && res[0] == '0')
    {
        res.erase(res.begin());
    }

    return res;
}
string twoDigitMultiplier(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    string result = "0";
    int i = num2.size() - 1;
    while (i >= 0)
    {
        string current = "";
        int carry = 0;
        int j = num1.size() - 1;
        while (j >= 0)
        {
            int temp = ((num1[j] - '0') * (num2[i] - '0')) + carry;
            carry = temp / 10;
            current = char(temp % 10 + '0') + current;
            j--;
        }
        if (carry > 0)
        {
            current = char(carry + '0') + current;
        }

        current += string(num2.size() - i - 1, '0');
        result = twoDigitSumer(result, current);
        i--;
    }
    return result;
}
int main()
{
    string n;
    string n = "21111+23135-1"

        char mult = "*";

    n.find(mult);

    int num = n.find(mult);

    cout << num;
    return 0;
}

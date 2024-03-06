#include <bits/stdc++.h>

using namespace std;

string twoDigitSumer(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res = "";

    while(i >= 0 || j >= 0 || carry)
    {
        long sum = 0;
        if(i >= 0)
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
    bool negative = false;
    if (b.size() > a.size() || (b.size() == a.size() && b > a))
    {
        swap(a, b);
        negative = true;
    }

    int i = a.size() - 1;
    int j = b.size() - 1;
    int borrow = 0;
    string res = "";

    while(i >= 0 || j >= 0)
    {
        int digitA = i >= 0 ? a[i] - '0' : 0;
        int digitB = j >= 0 ? b[j] - '0' : 0;

        if(digitA < digitB + borrow)
        {
            digitA += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        res = char(digitA - digitB - borrow + '0') + res;

        i--;
        j--;
    }

    while(res.size() > 1 && res[0] == '0')
    {
        res.erase(res.begin());
    }

    if (negative)
    {
        res = '-' + res;
    }

    return res;
}
string twoDigitMultiplier(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    string result = "0";
    int i = num2.size() - 1;
    while(i >= 0)
    {
        string current = "";
        int carry = 0;
        int j = num1.size() - 1;
        while(j >= 0)
        {
            int temp = ((num1[j] - '0') * (num2[i] - '0')) + carry;
            carry = temp / 10;
            current = char(temp % 10 + '0') + current;
            j--;
        }
        if  (carry > 0)
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
    string n = "138181+28183818+88*121313+391938*121";

    char mult = '+';
    char mult2 = '-';
    char mult3 = '*';

    while(n.find(mult3) != -1)
    {
        int num3 = n.find(mult3);

        string temp = "";
        string temp2 = "";

        for(int i = num3 - 1; i >= 0; i--)
        {
            if(isdigit(n[i]))
            {
                temp = n[i] + temp;
            }
            else
            {
                break;
            }
        }

        for (int j = num3 + 1; j < n.size(); j++)
        {
            if(isdigit(n[j]))
            {
                temp2 = temp2 + n[j];
            }
            else
            {
                break;
            }
        }

        string res = twoDigitMultiplier(temp, temp2);

        n.erase(num3 - temp.size(), temp.size() + temp2.size() + 1);
        n.insert(num3 - temp.size(), res);
    }

    while(n.find(mult) != -1)
    {
        int num = n.find(mult);

        string temp = "";
        string temp2 = "";

        for(int i = num - 1; i >= 0; i--)
        {
            if (isdigit(n[i]))
            {
                temp = n[i] + temp;
            }
            else
            {
                break;
            }
        }

        for(int j = num + 1; j < n.size() && isdigit(n[j]); j++)
        {
            temp2 = temp2 + n[j];
        }

        string res = twoDigitSumer(temp, temp2);

        n.erase(num - temp.size(), temp.size() + temp2.size() + 1);
        n.insert(num - temp.size(), res);
    }
    while(n.find(mult2) != -1)
    {
        int num2 = n.find(mult2);

        string temp = "";
        string temp2 = "";

        for(int i = num2 - 1; i >= 0; i--)
        {
            if (isdigit(n[i]))
            {
                temp = n[i] + temp;
            }
            else
            {
                break;
            }
        }

        for(int j = num2 + 1; j < n.size() && isdigit(n[j]); j++)
        {
            temp2 = temp2 + n[j];
        }

        string res = twoDigiSubtraction(temp, temp2);

        n.erase(num2 - temp.size(), temp.size() + temp2.size() + 1);
        n.insert(num2 - temp.size(), res);
    }

    cout << n;
    return 0;
}

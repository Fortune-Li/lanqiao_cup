#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1000;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int reverse(int n)
{
    string str = to_string(n);

    reverse(str.begin(), str.end());

    int newNum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        newNum *= 10;
        newNum += (str[i] - '0');
    }

    return newNum;
}

bool splitDigit(int n)
{
    bool flag = true;
    int temp;
    while (n)
    {
        if (!isPrime(n))
            flag = false;
        temp = n % 10;
        if (!isPrime(temp))
            flag = false;
        n /= 10;
    }
    return flag;
}

void solution()
{
    int res = 0;
    for (int i = 2; i < N; i++)
    {
        if (splitDigit(i) && splitDigit(reverse(i)))
            res = max(res, i);
    }
    printf("%d\n", res);
}

int main()
{
    solution();
}
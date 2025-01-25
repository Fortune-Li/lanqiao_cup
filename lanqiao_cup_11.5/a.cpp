#include <iostream>

using namespace std;

const int N = 10000 + 1;

bool isPalindrome(int n)
{
    if (n < 0 || (n % 10 == 0 && n != 0))
        return false;
    int reverseHalf = 0;
    int temp = n;
    while (temp)
    {
        reverseHalf = reverseHalf * 10 + temp % 10;
        temp /= 10;
    }
    return reverseHalf == n;
}

int calcTriangleNumber(int k)
{
    return k * (k + 1) / 2;
}

void solution()
{
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        // 因为每次通过 calcTriangleNumber(i) 计算出来的结果本身就是三角数，所以无需再判断它是否是三角数
        int triangleNumber = calcTriangleNumber(i);
        // 以此只需要在三角数的基础上继续判断是否为回文数，并且大于 20220514 即可
        if (isPalindrome(triangleNumber) && triangleNumber >= 20220514)
        {
            printf("%d\n", triangleNumber);
            break;
        }
    }
}

int main()
{
    solution();
}
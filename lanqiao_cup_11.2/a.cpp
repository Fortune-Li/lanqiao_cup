#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

// 计算最小质因数
int smallestPrimeFactor(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n; // n 是质数
}

// 动态规划解决方案
void solution(const vector<int> &Arr, int n)
{
    vector<int> DP(n+1, INT_MIN); // 初始化为负无穷
    DP[1] = Arr[1];             // 从第一个方格开始

    // 遍历每个方格
    for (int i = 1; i <= n; i++)
    {
        int step = i + smallestPrimeFactor(n - i); // 获取从 i+1 位置的最小质因数
        for (int j = i + 1; j <= step; j++)
        {                                       // 从当前方格 i 跳跃到其他方格 j
            DP[j] = max(DP[j], DP[i] + Arr[j]); // 更新方格 j 的最大分数
        }
    }

    cout << DP[n] << endl; // 输出最终到达方格 n 的最大分数
}

int main()
{
    int n;
    cin >> n;              // 输入方格数
    vector<int> Arr(n+1, 0); // 宝物分值数组
    for (int i = 1; i <= n; i++)
    {
        cin >> Arr[i]; // 输入每个方格的宝物分值
    }

    solution(Arr, n); // 调用解法
    return 0;
}

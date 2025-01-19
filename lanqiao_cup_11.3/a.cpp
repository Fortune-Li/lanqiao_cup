#include <iostream>
using namespace std;

void solution(int n)
{
    int k = 1; // 从k=1开始
    while (k * (k + 1) / 2 < n)
    {        // 当总卡片对数小于n时
        k++; // 逐步增大k，直到满足条件
    }
    cout << k << endl; // 输出最小的k
}

int main()
{
    int n;
    cin >> n;    // 输入n
    solution(n); // 调用解法
    return 0;
}

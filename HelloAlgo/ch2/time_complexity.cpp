
//
// Created by Yao on 2023/11/1.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

/* 常数阶 */
int constant(int n)
{
    int count = 0;
    int size = 100000;
    for (int i = 0; i < size; i++)
        count++;
    return count;
}

/* 线性阶 */
int linear(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        count++;
    return count;
}

/* 线性阶（遍历数组） */
int arrayTraversal(vector<int> &nums)
{
    int count = 0;
    // 循环次数与数组长度成正比
    for (int num : nums)
    {
        count++;
    }
    return count;
}

/* 平方阶 */
int quadratic(int n)
{
    int count = 0;
    // 循环次数与数组长度成平方关系
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count++;
        }
    }
    return count;
}

/* 平方阶（冒泡排序） */
void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}


/* 指数阶（循环实现） */
int exponential(int n) {
    int count = 0, base = 1;
    // 细胞每轮一分为二，形成数列 1, 2, 4, 8, ..., 2^(n-1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < base; j++) {
            count++;
        }
        base *= 2;
    }
    // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
    return count;
}

/* 指数阶（递归实现） */
int expRecur(int n) {
    if (n == 1)
        return 1;
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* 对数阶（循环实现） */
int logarithmic(float n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}

/* 对数阶（递归实现） */
int logRecur(float n) {
    if (n <= 1)
        return 0;
    return logRecur(n / 2) + 1;
}

/* 线性对数阶 */
int linearLogRecur(float n) {
    if (n <= 1)
        return 1;
    int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

/* 阶乘阶（递归实现） */
int factorialRecur(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    // 从 1 个分裂出 n 个
    for (int i = 0; i < n; i++) {
        count += factorialRecur(n - 1);
    }
    return count;
}

int main()
{
    cout << constant(1) << endl;
    cout << linear(10) << endl;

    vector<int> v{1, 5, 3, 4, 2};
    cout << arrayTraversal(v) << endl;

    cout << quadratic(4) << endl;

    bubbleSort(v);

    for(int n : v){
        cout << n << " ";
    }
    cout << endl;

    cout << exponential(3) << endl;
    cout << expRecur(3) << endl;

    cout << logarithmic(16) << endl;
    cout << logRecur(16) << endl;

    cout << linearLogRecur(16) << endl; // n*(logn+1) = 16*5

    cout << factorialRecur(4) << endl;
}

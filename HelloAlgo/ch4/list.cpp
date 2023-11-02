
//
// Created by Yao on 2023/11/2.
// Description:
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> & nums){
    for (int num : nums)
    {
        cout << num << " " ;
    }
    cout << endl;
}

int main()
{
    /* 初始化列表 */
    // 需注意，C++ 中 vector 即是本文描述的 nums
    // 无初始值
//    vector<int> nums1;
    // 有初始值
    vector<int> nums = { 1, 3, 2, 5, 4 };
    /* 访问元素 */
    int num = nums[1];  // 访问索引 1 处的元素
    cout << num << endl;

    /* 更新元素 */
    nums[1] = 0;  // 将索引 1 处的元素更新为 0
    cout << nums[1] << endl;

    nums.clear();
    /* 尾部添加元素 */
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    printVector(nums);

    /* 中间插入元素 */
    nums.insert(nums.begin() + 3, 6);  // 在索引 3 处插入数字 6
    printVector(nums);
    /* 删除元素 */
    nums.erase(nums.begin() + 3);      // 删除索引 3 处的元素
    printVector(nums);

    /* 拼接两个列表 */
    vector<int> nums1 = { 6, 8, 7, 10, 9 };
    // 将列表 nums1 拼接到 nums 之后
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    printVector(nums);

    sort(nums.begin(), nums.end());
    printVector(nums);
}

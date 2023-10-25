//
// Created by Liu on 2023/7/2.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int pos = nums.size() - 1;

    vector<int> res(nums.size());

    while (left <= right)
    {
        if (abs(nums[left]) < abs(nums[right]))
        {
            res[pos--] = nums[right] * nums[right];
            right--;
        }
        else
        {
            res[pos--] = nums[left] * nums[left];
            left++;
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Please input the size of vector: " << endl;
    cin >> n;

    cout << "Please input elements of vector: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    vector<int> res = sortedSquares(nums);

    for (int num : res)
    {
        cout << num << " ";
    }
}

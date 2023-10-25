//
// Created by Liu on 2023/7/1.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int pos = 0;
    nums[pos++] = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[pos - 1])
        {
            nums[pos++] = nums[i];
        }
    }
    return pos;
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

    int res = removeDuplicates(nums);

    cout << res << endl;

    for (int i = 0; i < res; ++i)
    {
        cout << nums[i] << " ";
    }
}

//
// Created by Liu on 2023/7/1.
// Description:
//

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int pos = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
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

    cout << "Please input the element needed to be removed: " << endl;
    int target;
    cin >> target;

    int res = removeElement(nums, target);

    cout << res;
}

//
// Created by Liu on 2023/7/2.
// Description: 
//

#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void moveZeroes(vector<int> & nums){
    int left = 0;
    int right = 0;
    int len = nums.size();

    while(right < len){
        if (nums[right] != 0){
            swap(nums, left, right);
            left++;
        }
        right++;
    }
}
/*// 这样就改变了非零元素的相对顺序
void moveZeroes(vector<int> & nums){
    int left = 0;
    int right = nums.size()-1;

    while(left < right){
        while (nums[left] != 0){
            left++;
        }
        while (nums[right] == 0){
            right--;
        }

        if (left < right){
            swap(nums, left, right);
        }
    }
}*/

int main() {
    int n;
    cout << "Please input the size of vector: " << endl;
    cin >> n;

    cout << "Please input elements of vector: " << endl;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    moveZeroes(nums);

    for (int num : nums){
        cout << num << " ";
    }

}

//
// Created by Liu on 2023/7/6.
// Description: 
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res ;
    if (nums[0] > 0 || nums[nums.size()-1] < 0){
        return res;
    }

    for(int i = 0; i < nums.size(); ++i){
        if (nums[i] > 0){
            break;
        }

        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int left = i+1, right = nums.size()-1;


        while(left < right){
            vector<int> temp;
            if (nums[left] + nums[right] == -nums[i]){
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                res.push_back(temp);

                while(left < right && nums[left] == nums[left+1]){
                    left++;
                }
                while(left < right && nums[right] == nums[right-1]){
                    right--;
                }
                left++;
                right--;
            }else if(nums[left] + nums[right] < -nums[i]){
                left++;
            }else{
                right--;
            }
        }
    }
    return res;
}

int main() {

}


//
// Created by Yao on 2023/10/17.
// Description:     
//

#include <iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size()-1;

    while(left < right){
        if(numbers[left] + numbers[right] == target){
            return vector<int>{left+1, right+1};
        }else if(numbers[left] + numbers[right] < target){
            left++;
        }else{
            right--;
        }
    }
    return {};
}

int main() {

}

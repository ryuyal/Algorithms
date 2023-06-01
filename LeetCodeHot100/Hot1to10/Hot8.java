package LeetCodeHot100.Hot1to10;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


/*
Hot100题单中的题号为 15
 */
public class Hot8 {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        if (nums[0] > 0 || nums[nums.length-1] < 0){
            return res;
        }
        for (int i = 0; i < nums.length; ++i){
            if (nums[i] > 0)
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i+1;
            int right = nums.length-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                List<Integer> tmp = new ArrayList<>();
                if (sum == 0){
                    tmp.add(nums[i]);
                    tmp.add(nums[left]);
                    tmp.add(nums[right]);

                    res.add(tmp);

                    /*
                    处理重复情况
                     */
                    while(nums[left] == nums[left+1]){
                        left++;
                    }
                    while(nums[right] == nums[right-1]){
                        right--;
                    }

                    left++;
                    right--;
                }
                if (sum < 0){
                    left++;
                }
                if (sum > 0){
                    right--;
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        List<List<Integer>> res = threeSum(nums);
        for (List<Integer> ll : res){
            for (int num : ll){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

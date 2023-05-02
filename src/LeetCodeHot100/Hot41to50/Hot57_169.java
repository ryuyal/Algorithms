package LeetCodeHot100.Hot41to50;

import java.util.Arrays;
import java.util.Scanner;

public class Hot57_169 {
    public static int majorityElement(int[] nums) {
        Arrays.sort(nums);

        return nums[nums.length/2];
    }
    public static int majorityElement2(int[] nums){
        int target = nums[0];
        int count = 1;

        for (int i = 1; i < nums.length; ++i){
            if (count == 0){
                count++;
                target = nums[i];
                continue;
            }

            if (target == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return target;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = majorityElement2(nums);

        System.out.println(res);
    }
}

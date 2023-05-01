package LeetCodeHot100.Hot71to80;

import java.util.Arrays;
import java.util.Scanner;

public class Hot73_283 {
    public static void moveZeroes(int[] nums) {
        int index = 0;

        for (int i = 0; i < nums.length; ++i){
            if (nums[i] != 0){
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.length; ++i){
            nums[index++] = 0;
        }

    }
    /*
    双指针：
    非零, 左右指针交换, 左右指针都右移
    零, 右指针右移
     */
    public static void moveZeroes2(int [] nums){
        int len = nums.length;
        int left = 0;
        int right = 0;

        while(right < len){
            if (nums[right] != 0){
                swap(nums, left, right);
                left++;
            }
            right++;
        }
    }
    public static void swap(int [] nums, int left, int right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        moveZeroes2(nums);

        for (int num : nums){
            System.out.print(num + " ");
        }
    }
}

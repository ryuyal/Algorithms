package JianZhiOffer2;

import java.util.Arrays;
import java.util.Scanner;

public class Offer2_012 {
    /*

     */
    public static int pivotIndex2(int[] nums){
        int total = Arrays.stream(nums).sum(); // 总和
        int sum = 0; // 左侧和
        for (int i = 0; i < nums.length; ++i){
            if (2 * sum + nums[i] == total){
                return i;
            }
            sum += nums[i];
        }

        return -1;
    }
    /*
    暴力解法
     */
    public static int pivotIndex(int[] nums) {

        for (int i = 0; i < nums.length; ++i){
            int sum_left = 0;
            int sum_right = 0;

            for (int j = 0; j < i; ++j){
                sum_left += nums[j];
            }

            for (int k = i+1; k < nums.length; ++k){
                sum_right += nums[k];
            }
            if (sum_left == sum_right){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = pivotIndex2(nums);

        System.out.println(res);
    }
}

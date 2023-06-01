package Basic_Algos.binarySearch;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_410 {
    public static int splitArray(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum(); // 最大为数组内元素之和
        int max = Arrays.stream(nums).max().getAsInt(); // 最小为 数组中值最大的元素
        if (k == 1){
            return sum;
        }
        if (k == nums.length){
            return max;
        }

        return binary(nums, k, max, sum);
    }

    public static int binary(int[]nums, int k, int low, int high){

        while(low <= high){
            int mid = low + (high-low)/2; // 猜测是否为 mid
            if(valid(nums, k, mid)){
                high = mid-1; // 看是否可以更小
            }else{
                low = mid+1;
            }
        }
        return low;
    }

    // valid 验证数组可以k个子数组，子数组最大和为 mid
    public static boolean valid(int[]nums, int k, int subArraySum){
        int curSum = 0, count = 1;
        for (int num : nums){
            curSum += num;
            if (curSum > subArraySum){
                curSum = num;
                count++;
                if (count > k){
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int k = sc.nextInt();

        int res = splitArray(nums, k);
        System.out.println(res);

    }

}

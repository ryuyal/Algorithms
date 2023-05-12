package Basic_DS.LinkedList;

import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_287 {
    // n+1个元素 取值范围为1-n
    public static int findDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; ++i){
            int index = Math.abs(nums[i])-1; // 元素值作为下标
            if (nums[index] > 0){
                nums[index] *= -1;
            }else{
                return index + 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = findDuplicate(nums);
        System.out.println(res);
    }
}

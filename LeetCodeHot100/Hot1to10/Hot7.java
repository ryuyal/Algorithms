package LeetCodeHot100.Hot1to10;

import java.util.Arrays;
import java.util.Scanner;

/*
Hot100题单中的题号为 11
 */
public class Hot7 {
    /*
    暴力解超时
     */
    public static int maxAreaOne(int[] height) {
        int maxRes = 0;
        for (int i = 0; i < height.length-1; ++i){
            for (int j = i+1; j < height.length; ++j){
                int area = (j-i) * Math.min(height[i], height[j]);
                maxRes = Math.max(maxRes, area);
            }
        }
        return maxRes;
    }

    /*
    双指针解法
     */
    public static int maxArea(int[] height) {
        int maxRes = 0;
        int left = 0;
        int right = height.length-1;

        while(left < right){
            int area = Math.min(height[left], height[right]) * (right - left);
            maxRes = Math.max(maxRes, area);

            if (height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxRes;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = maxArea(nums);

        System.out.println(res);
    }
}

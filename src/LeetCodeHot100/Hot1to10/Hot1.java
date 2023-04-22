package LeetCodeHot100.Hot1to10;

import java.util.*;

public class Hot1 {
    public static int[] twoSum(int []nums, int target){
        Map<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < nums.length; ++i){
            if (hm.containsKey(target - nums[i])){
                return new int[]{hm.get(target - nums[i]), i};
            }
            hm.put(nums[i], i);
        }
        return null;
    }
    public static void main(String[] args) {
        System.out.println("This is LeetCode Hot100-1!!!");
        System.out.println("Good Luck!");
        Scanner sc = new Scanner(System.in);
        /*
        转换为 Integer 数组
         */
//        Integer[] integers = Arrays.stream(
//                sc.nextLine().split(" ")
//        ).map(Integer::parseInt).toArray(Integer[]::new);

        /*
        转换为 int 数组
         */
        int[] integers = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int target = sc.nextInt();

        int[] res = twoSum(integers, target);
        for (int num : res){
            System.out.println(num);
        }
    }
}

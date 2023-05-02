package LeetCodeHot100.Hot81to90;

import java.util.*;

public class Hot90_448 {
    public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Set<Integer> hs = new HashSet<>();
        for (int num : nums){
            hs.add(num);
        }

        for (int i = 1; i <= nums.length; ++i){
            if (!hs.contains(i)){
                res.add(i);
            }
        }
        return res;
    }

    public static List<Integer> findDisappearedNumbers2(int[] nums) {
        List<Integer> res = new ArrayList<>();

        // 元素值范围: 1-n
        for (int num : nums){
            /*
            对于当前元素 num, 将 num-1 位置的元素设为负值 表明num出现过
             */
            if (nums[Math.abs(num)-1] > 0) {
                nums[Math.abs(num) - 1] *= -1;
            }
        }

        /*
        遍历元素 如果当前位置的元素大于 0, 说明元素值等于该位置下标的值未出现过
         */
        for (int i = 1; i <= nums.length; ++i){
            if (nums[i-1] > 0){
                res.add(i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        List<Integer> res = findDisappearedNumbers2(nums);

        System.out.println(Arrays.toString(res.toArray()));
    }
}

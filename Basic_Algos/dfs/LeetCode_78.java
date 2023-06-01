package Basic_Algos.dfs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class LeetCode_78 {

    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        backtrack(res, new ArrayList<>(), nums, 0);

        return res;
    }

    public static void backtrack(List<List<Integer>> res, List<Integer> tmp, int[] nums, int start){
        res.add(new ArrayList<>(tmp));

        for (int i = start; i < nums.length; i++){
            tmp.add(nums[i]);
            backtrack(res, tmp, nums, i+1);
            tmp.remove(tmp.size()-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        List<List<Integer>> res = subsets(nums);

        for (List<Integer> list : res){
            System.out.print("[");
            for (int num : list){
                System.out.print(num + " ");
            }
            System.out.print("] ");
        }
    }
}

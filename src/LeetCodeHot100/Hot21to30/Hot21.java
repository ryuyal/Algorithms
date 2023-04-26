package LeetCodeHot100.Hot21to30;

import java.util.*;

/*
Hot 题号 46
 */
public class Hot21 {
    public static List<List<Integer>> permute(int[] nums) {
        int len = nums.length;
        List<List<Integer>> res = new ArrayList<>();

        if (len == 0){
            return res;
        }

        Deque<Integer> path = new ArrayDeque<>();
        boolean[] used = new boolean[len];
        dfs(nums, len, 0, path, used, res);

        return res;
    }

    private static void dfs(int[] nums, int len, int depth, Deque<Integer> path, boolean[] used, List<List<Integer>> res) {
        if (depth == len){
            res.add(new ArrayList<>(path));
            return ;
        }

        for (int i = 0; i < len; i++){
            if (used[i]){
                continue;
            }
            path.addLast(nums[i]);
            used[i] = true;
            dfs(nums, len, depth+1, path, used, res);
            // 回溯
            path.removeLast();
            used[i] = false;
        }
    }

    public static void main(String[] args) {
        System.out.println("This is LeetCode Hot100!!!");
        System.out.println("Good Luck!");

        Scanner sc = new Scanner(System.in);
        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        List<List<Integer>> res = permute(nums);

        for (List<Integer> l : res){
            for (int num : l){
                System.out.print(num);
            }
            System.out.println();
        }
    }
}

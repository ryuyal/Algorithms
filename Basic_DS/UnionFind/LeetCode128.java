package Basic_DS.UnionFind;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode128 {

    /*
    时间复杂度 O(n*logn)
     */
    public static int longestConsecutive(int[] nums) {

        if (nums.length==0 || nums.length==1){
            return nums.length;
        }
        Arrays.sort(nums);

        int res = 0;
        int cur_con = 1;
        for (int i = 0; i < nums.length-1; ++i){
            if (nums[i+1] - nums[i] == 1){
                cur_con++;
            }else if (nums[i+1] == nums[i]){
                res = Math.max(cur_con, res);
                continue;
            }else{
                cur_con = 1;
            }

            res = Math.max(cur_con, res);
        }
        return res;
    }

    /*
    并查集方法
     */
    static class DSU{
        int[] parent;
        int[] size;

        public DSU(int N){
            parent = new int[N];
            size = new int[N];
            for (int i = 0; i < N; i++){
                parent[i] = i;
            }
            Arrays.fill(size, 1);
        }

        public int find(int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public void union(int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY){
                return ;
            }

            if (size[rootX] <= size[rootY]){
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }else{
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }

        public int findMax(){
            int maxSize = 0;
            for (int s : size){ // size中保存的是当前group所含的节点个数
                maxSize = Math.max(maxSize, s);
            }
            return maxSize;
        }
    }
    public static int longestConsecutive2(int[] nums) {
        DSU dsu = new DSU(nums.length);
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++){
            if (map.containsKey(nums[i])) continue;

            map.put(nums[i], i);

            if (map.containsKey(nums[i] + 1)){
                dsu.union(i, map.get(nums[i] + 1)); // union的时候不是union值，而是union下标！！！
            }

            if (map.containsKey(nums[i] - 1)){
                dsu.union(i, map.get(nums[i] - 1));
            }
        }

        return dsu.findMax();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = longestConsecutive2(nums);
        System.out.println(res);
    }
}

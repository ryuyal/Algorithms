package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode_218 {
    public static List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> res = new ArrayList<>();
        List<int[]> height = new ArrayList<>();

        for (int [] building : buildings){
            height.add(new int[]{building[0], -building[2]});
            height.add(new int[]{building[1], building[2]});
        }

        Collections.sort(height, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (b - a));

        pq.offer(0);
        int preMax = 0;

        for (int[] h : height){
            if (h[1] < 0){
                pq.offer(-h[1]); // 遇到新房子 加入pq 高度从大到小
            }else{
                pq.remove(h[1]); // 遇到旧房子, 拿掉
            }

            int curMax = pq.peek(); // 最高高度
            if (curMax != preMax){
                res.add(List.of(h[0], curMax));
                preMax = curMax;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};

        List<List<Integer>> res = getSkyline(buildings);

        for (List<Integer> list : res){
            System.out.print("[");
            for (int num : list){
                System.out.print(num + " ");
            }
            System.out.print("] ");
        }
    }
}

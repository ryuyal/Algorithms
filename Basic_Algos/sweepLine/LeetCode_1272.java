package Basic_Algos.sweepLine;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode_1272 {
    public static List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved){
        List<List<Integer>> res = new ArrayList<>();

        for (int[] ints : intervals){
            if (ints[1] <= toBeRemoved[0] || ints[0] >= toBeRemoved[1]){
                res.add(Arrays.asList(ints[0], ints[1]));
            }else{ // ints[1] > toBeRemoved[0] && ints[0] < toBeRemoved[1]
                if (ints[0] < toBeRemoved[0]){
                    res.add(Arrays.asList(ints[0], toBeRemoved[0]));
                }
                if (ints[1] > toBeRemoved[1]){
                    res.add(Arrays.asList(toBeRemoved[1], ints[1]));
                }
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int[][] intervals = new int[][]{{0, 2}, {3, 4}, {5, 7}};
        int[] toBeRemoved = new int[]{1, 6};

//        int[][] intervals = new int[][]{{0, 5}};
//        int[] toBeRemoved = new int[]{2, 3};

        List<List<Integer>> res = removeInterval(intervals, toBeRemoved);

        for (List<Integer> list : res){
            System.out.println(Arrays.toString(list.toArray()));
        }
    }
}

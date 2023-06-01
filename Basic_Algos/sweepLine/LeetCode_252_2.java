package Basic_Algos.sweepLine;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class LeetCode_252_2 {
    static class MyComparator implements Comparator<int[]>{
        @Override
        public int compare(int[] a, int[] b){
            return Integer.compare(a[0], b[0]); // 根据 开始时间从小到大排序
        }
    }
    public static boolean canAttendMeetings(int[][] intervals){
        // 1. 外部Comparator普通写法
        Arrays.sort(intervals, new MyComparator());

//        // 2. 内部Comparator普通写法
//        Arrays.sort(intervals, new Comparator<int[]>() {
//            @Override
//            public int compare(int[] o1, int[] o2) {
//                return o1[0] - o2[0];
//            }
//        });
//
//        // 3. 内部lambda 两种Comparator写法
//        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
//        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0])); // 更严谨

        for (int i = 0; i < intervals.length-1; i++){
            if (intervals[i][1] > intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int[][] intervals = new int[3][2];

        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 3; i++){
            intervals[i] = new int[] {sc.nextInt(), sc.nextInt()};
        }

        boolean res = canAttendMeetings(intervals);
        System.out.println(res);
    }
}

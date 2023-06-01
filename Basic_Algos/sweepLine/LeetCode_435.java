package Basic_Algos.sweepLine;

import java.util.Arrays;

public class LeetCode_435 {
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0 || intervals.length == 1){
            return 0;
        }

        Arrays.sort(intervals, (a, b) -> a[1] - b[1]); // 根据结束时间排序
        int count = 0;
        int end = Integer.MIN_VALUE;

//        对于两个重叠的区间 要删除最晚结束的那个区间 这样留下来的可以给后面的区间留下更多空间
//        当备选区间左端点大于等于end的时候，它不与已选区间们有重叠。
//        至于一开始按照右端点排序是为了优先选择右端点靠前的区间，这样给后面留的空间大，能挑出来的区间数也大
        for (int[] cur : intervals){
            if(end <= cur[0]){
                end = cur[1];
            }else{
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int[][] intervals = {{1,2},{2,3},{3,4},{1,3}};

        int res = eraseOverlapIntervals(intervals);

        System.out.println(res);
    }
}

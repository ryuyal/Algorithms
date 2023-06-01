package Basic_Algos.sweepLine;

import java.util.*;

/*
给出飞机的起飞和降落时间的列表，用序列 Interval 表示. 请计算出天上同时最多有多少架飞机？
 */
public class LintCode_391 {
     static class Interval {
         int start, end;
         Interval(int start, int end) {
             this.start = start;
             this.end = end;
         }
    }
    public static int countOfAirplanes(List<Interval> airplanes) {
         List<int[]> list = new ArrayList<>();
         for (Interval in: airplanes){
             list.add(new int[]{in.start, 1}); // 起飞时间权重为1
             list.add(new int[]{in.end, -1}); // 降落时间权重为-1
         }

         // 时间升序  cost升序
         list.sort(Comparator.comparing((int[] p) -> p[0]).thenComparing((int[] p) -> p[1]));

         int ans = 0;
         int cnt = 0;
         for (int[] in : list){
             cnt += in[1]; // in[1] = 1 或 in[1] = -1
             ans = Math.max(ans, cnt);
         }
         return ans;
    }
    public static void main(String[] args) {
         List<Interval> airs = new ArrayList<>();

         Scanner sc = new Scanner(System.in);
         for (int i = 0; i < 4; ++i){
             int s = sc.nextInt();
             int e = sc.nextInt();
             Interval in = new Interval(s, e);
             airs.add(in);
         }

         int res = countOfAirplanes(airs);
        System.out.println(res);
    }
}

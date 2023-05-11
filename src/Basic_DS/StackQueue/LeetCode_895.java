package Basic_DS.StackQueue;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class LeetCode_895 {
    static class FreqStack {

        int pushCount;
        PriorityQueue<int[]> pq; // <element, frequency, insertSequence>
        Map<Integer, Integer> map;

        public FreqStack() {
            pushCount = 0;
            map = new HashMap<>();
            pq = new PriorityQueue<>((a, b) -> a[1] == b[1] ? b[2] - a[2] : b[1] - a[1]); // 频率相同时看进入栈的顺序
        }

        public void push(int val) {
            map.put(val, map.getOrDefault(val, 0) + 1 );
            pq.offer(new int[] {val, map.get(val), pushCount++});
        }

        public int pop() {
            int mostFreqEle = pq.peek()[0];
            map.put(mostFreqEle, map.get(mostFreqEle)-1);
            return pq.poll()[0];
        }
    }
    public static void main(String[] args) {

        FreqStack freqStack= new FreqStack();
        freqStack.push (5);//堆栈为 [5]
        freqStack.push (7);//堆栈是 [5,7]
        freqStack.push (5);//堆栈是 [5,7,5]
        freqStack.push (7);//堆栈是 [5,7,5,7]
        freqStack.push (4);//堆栈是 [5,7,5,7,4]
        freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
        freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
        System.out.println(freqStack.pop ());//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
        freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
        System.out.println(freqStack.pop ());//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]

    }
}

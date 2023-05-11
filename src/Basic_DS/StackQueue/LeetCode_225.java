package Basic_DS.StackQueue;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode_225 {
//    static class MyStack {
//
//        Queue<Integer> queue1;
//        Queue<Integer> queue2;
//        public MyStack() {
//            queue1 = new LinkedList<>();
//            queue2 = new LinkedList<>();
//        }
//
//        public void push(int x) {
//            if (queue1.isEmpty()){
//                queue1.offer(x);
//            }
//
//            while(!queue2.isEmpty()){
//                queue1.offer(queue2.poll());
//            }
//            while(!queue1.isEmpty()){
//                queue2.offer(queue1.poll());
//            }
//        }
//
//        public int pop() {
//            return queue2.poll();
//        }
//
//        public int top() {
//            return queue2.peek();
//        }
//
//        public boolean empty() {
//            return queue1.isEmpty() && queue2.isEmpty();
//        }
//    }

    static class MyStack {

        Queue<Integer> queue;
        public MyStack() {
            queue = new LinkedList<>();
        }

        public void push(int x) {
            queue.offer(x);
            int len = queue.size();

            for (int i = 0; i < len-1; i++){
                queue.offer(queue.poll());
            }
        }

        public int pop() {
            return queue.poll();
        }

        public int top() {
            return queue.peek();
        }

        public boolean empty() {
            return queue.isEmpty() ;
        }
    }

    public static void main(String[] args) {
        MyStack myStack = new MyStack();
        myStack.push(1);
        myStack.push(2);
        System.out.println(myStack.top()); // 返回 2
        System.out.println(myStack.pop()); // 返回 2
        System.out.println(myStack.empty()); // 返回 False
    }
}

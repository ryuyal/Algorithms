package Basic_DS.StackQueue;

import java.util.Stack;

public class LeetCode155 {
    /*
    两个栈的方式
     */
//    static class MinStack {
//        Stack<Integer> stack;
//        Stack<Integer> minStack;
//
//        public MinStack() {
//            stack = new Stack<>();
//            minStack = new Stack<>();
//        }
//
//        public void push(int val) {
//            stack.push(val);
//
//            if (minStack.isEmpty() || val <= minStack.peek()){
//                minStack.push(val);
//            }
//
//        }
//
//        public void pop() {
//            int val = stack.pop();
//
//            if (val == minStack.peek()){
//                minStack.pop();
//            }
//        }
//
//        public int top() {
//            return stack.peek();
//        }
//
//        public int getMin() {
//            return minStack.peek();
//        }
//    }

    /*
    一个栈的方式
     */
    static class MinStack {
        Stack<int[]> stack;

        public MinStack() {
            stack = new Stack<>();
        }

        public void push(int val) {

            if (stack.isEmpty()){
                stack.push(new int[]{val, val});

                return ;
            }
            int min = stack.peek()[1];
            stack.push(new int[]{val, Math.min(val, min)});
        }

        public void pop() {
            stack.pop();
        }

        public int top() {
            return stack.peek()[0];
        }

        public int getMin() {
            return stack.peek()[1];
        }
    }
    public static void main(String[] args) {

        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        System.out.println(minStack.getMin());   //--> 返回 -3.
        minStack.pop();
        System.out.println(minStack.top());      //--> 返回 0.
        System.out.println(minStack.getMin());   //--> 返回 -2.

    }
}

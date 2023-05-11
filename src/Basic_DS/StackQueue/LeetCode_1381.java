package Basic_DS.StackQueue;

import java.util.Stack;

public class LeetCode_1381 {

    static class CustomStack {

        Stack<Integer> stack;
        int capacity;
        Stack<Integer> stack2;
        public CustomStack(int maxSize) {
            stack = new Stack<>();
            stack2 = new Stack<>();
            capacity = maxSize;
        }

        public void push(int x) {
            if (stack.size() == capacity){
                return ;
            }
            stack.push(x);
        }

        public int pop() {
            if (stack.isEmpty()){
                return -1;
            }
            return stack.pop();
        }

        public void increment(int k, int val) {
            int len = stack.size();
            if (k >= len){
                while(!stack.isEmpty()){
                    stack2.push(stack.pop() + val);
                }

                while(!stack2.isEmpty()){
                    stack.push(stack2.pop());
                }
            }else{ // k < len
                for (int i = 0; i < len-k; i++){
                    stack2.push(stack.pop());
                }
                while(!stack.isEmpty()){
                    stack2.push(stack.pop() + val);
                }

                while(!stack2.isEmpty()){
                    stack.push(stack2.pop());
                }
            }
        }
    }
    public static void main(String[] args) {
        CustomStack stk = new CustomStack(3); // 栈是空的 []
        stk.push(1);                          // 栈变为 [1]
        stk.push(2);                          // 栈变为 [1, 2]
        stk.pop();                            // 返回 2 --> 返回栈顶值 2，栈变为 [1]
        stk.push(2);                          // 栈变为 [1, 2]
        stk.push(3);                          // 栈变为 [1, 2, 3]
        stk.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
        stk.increment(5, 100);                // 栈变为 [101, 102, 103]
        stk.increment(2, 100);                // 栈变为 [201, 202, 103]
        System.out.println(stk.pop());                            // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
        stk.pop();                            // 返回 202 --> 返回栈顶值 202，栈变为 [201]
        stk.pop();                            // 返回 201 --> 返回栈顶值 201，栈变为 []
        stk.pop();                            // 返回 -1 --> 栈为空，返回 -1

    }
}

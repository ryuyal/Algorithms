package Basic_DS.LinkedList;

import java.util.Scanner;
import java.util.Stack;

public class LeetCode_445 {
    static class ListNode{
        int val;
        ListNode next;
        ListNode(){}
        ListNode(int val){
            this.val = val;
        }
        ListNode(int val, ListNode next){
            this.val = val;
            this.next = next;
        }
    }

    /*
    方式一: 反转链表 之后按照LeetCode 2的方式相加 最后再反转
     */

    /*
    方式二: stack存储元素
     */
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 用栈存储链表元素
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        while(l1 != null){
            stack1.push(l1.val);
            l1 = l1.next;
        }

        while(l2 != null){
            stack2.push(l2.val);
            l2 = l2.next;
        }

        ListNode res = null;
        int flag = 0;
        while(!stack1.isEmpty() || !stack2.isEmpty()){
            int x = stack1.isEmpty() ? 0 : stack1.pop();
            int y = stack2.isEmpty() ? 0 : stack2.pop();

            int sum = x + y + flag;
            if (sum >= 10){
                flag = 1;
            }else{
                flag = 0;
            }

            ListNode tmp = new ListNode(sum % 10); // 新的数字加到链表的前面 （头插法）
            tmp.next = res;
            res = tmp;
        }
        if (flag == 1){ // 最后需要判断是否还有进位
            ListNode tmp = new ListNode(flag);
            tmp.next = res;
            res = tmp;
        }

        return res;

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ListNode head1 = new ListNode();
        ListNode pre1 = head1;

        while(sc.hasNext()){
            int val = sc.nextInt();
            if (val == -1){
                break;
            }
            pre1.next = new ListNode(val);
            pre1 = pre1.next;
        }

        ListNode head2 = new ListNode();
        ListNode pre2 = head2;
        while(sc.hasNext()){
            int val = sc.nextInt();
            if (val == -1){
                break;
            }
            pre2.next = new ListNode(val);
            pre2 = pre2.next;
        }

        ListNode res = addTwoNumbers(head1.next, head2.next);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }
    }
}

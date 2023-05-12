package Basic_DS.LinkedList;

import java.util.Scanner;

public class LeetCode_2 {
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
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2){
        int flag = 0;
        ListNode head = new ListNode();
        ListNode pre = head;
        while(l1 != null || l2 != null){
            int x = l1 != null ? l1.val : 0;
            int y = l2 != null ? l2.val : 0;

            int sum = x + y + flag;
            if (sum >= 10){
                flag = 1;
            }else{
                flag = 0;
            }

            ListNode tmp = new ListNode(sum % 10);
            pre.next = tmp;
            pre = pre.next;

            if (l1 != null){
                l1 = l1.next;
            }

            if (l2 != null){
                l2 = l2.next;
            }
        }

        if (flag == 1){
            pre.next = new ListNode(1);
        }

        return head.next;
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

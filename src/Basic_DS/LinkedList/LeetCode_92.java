package Basic_DS.LinkedList;

import java.util.Scanner;

public class LeetCode_92 {
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
    public static ListNode reverseBetween(ListNode head, int left, int right) {
        if (left >= right){
            return head;
        }

        ListNode newHead = new ListNode(-1);
        newHead.next = head;
        ListNode pre = newHead;
        ListNode cur = head;

        for (int i = 0; i < left-1; i++){
            pre = cur;
            cur = cur.next;
        }

        ListNode start = pre;


        for (int i = left; i <= right; i++){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        start.next.next = cur;
        start.next = pre;

        return newHead.next;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ListNode root = new ListNode();
        ListNode pre = root;

        while(sc.hasNext()){
            int val = sc.nextInt();
            if (val == -1){
                break;
            }
            pre.next = new ListNode(val);
            pre = pre.next;
        }

        int left = sc.nextInt();
        int right = sc.nextInt();

        ListNode res = reverseBetween(root.next, left, right);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }

    }
}

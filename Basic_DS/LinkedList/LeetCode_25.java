package Basic_DS.LinkedList;

import java.util.Scanner;

public class LeetCode_25 {
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

    // 根据92题目 每次翻转 left-right
    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode tmp = head;
        int len = 0;
        while(tmp != null){
            len++;
            tmp = tmp.next;
        }

        int i = 1;
        while((i + k) <= (len+1)){
            head = reverseBetween(head, i, i+k-1);
            i += k;
        }
        return head;
    }

    public static ListNode reverseBetween(ListNode head, int left, int right){
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

        ListNode head = new ListNode();
        ListNode pre = head;

        while(sc.hasNext()){
            int val = sc.nextInt();
            if (val == -1){
                break;
            }
            pre.next = new ListNode(val);
            pre = pre.next;
        }

        int k = sc.nextInt();

        ListNode res = reverseKGroup(head.next, k);

        while(res != null){
            System.out.print(res.val + "->");
            res = res.next;
        }

    }
}

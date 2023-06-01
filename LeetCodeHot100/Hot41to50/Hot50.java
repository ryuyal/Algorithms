package LeetCodeHot100.Hot41to50;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Hot50 {
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
    public static boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        while(head != null){
            if (set.isEmpty()){
                set.add(head);
            }else{
                if (set.contains(head)){
                    return true;
                }else{
                    set.add(head);
                }
            }
            head = head.next;
        }
        return false;
    }
    public static boolean hasCycle2(ListNode head){
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null){
            fast = fast.next;
            if (fast != null){
                fast = fast.next;
            }
            if (fast == slow){
                return true;
            }
            slow = slow.next;
        }
        return false;
    }
    public static void main(String[] args) {
//        ListNode h1 = new ListNode(3);
//        ListNode h2 = new ListNode(2);
//        ListNode h3 = new ListNode(0);
//        ListNode h4 = new ListNode(-4);
//        h1.next = h2;
//        h2.next = h3;
//        h3.next = h4;
//        h4.next = h2;

        Scanner sc = new Scanner(System.in);
        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        ListNode head = new ListNode();
        ListNode pre = head;

        for (int num : nums){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        int pos = sc.nextInt();

        ListNode tail = pre;
        pre = head.next;
        if (pos != -1){
            for (int i = 0; i < pos; i++) {
                pre = pre.next;
            }
            tail.next = pre;
        }

        boolean res = hasCycle2(head.next);
        System.out.println(res);
    }
}

package LeetCodeHot100.Hot61to70;

import java.util.Arrays;
import java.util.Scanner;

public class Hot66_234 {
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
    public static boolean isPalindrome(ListNode head) {
        StringBuilder sb = new StringBuilder();

        while(head != null){
            sb.append(head.val);
            head = head.next;
        }
        String sb1 = sb.toString();
        StringBuilder sb2 = sb.reverse();

        return sb1.contentEquals(sb2);
//        if (sb.reverse()){
//            return true;
//        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        ListNode head = new ListNode();
        ListNode pre = head;
        for (int num : nums){
            pre.next = new ListNode(num);
            pre = pre.next;
        }

        boolean res = isPalindrome(head.next);
        System.out.println(res);
    }
}

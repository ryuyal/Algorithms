package LeetCodeHot100.Hot41to50;

import java.util.HashSet;
import java.util.Set;

public class Hot56_160 {
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

    public static ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        ListNode l1 = headA;
        ListNode l2 = headB;
        while(l1 != l2){
            l1 = (l1 == null) ? headB : l1.next;
            l2 = (l2 == null) ? headA : l2.next;
        }

        return l1;
    }
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> hs = new HashSet<>();

        while(headA != null){
            hs.add(headA);
            headA = headA.next;
        }

        while(headB != null){
            if (hs.contains(headB)){
                return headB;
            }
            headB = headB.next;
        }
        return null;
    }
    public static void main(String[] args) {

    }
}

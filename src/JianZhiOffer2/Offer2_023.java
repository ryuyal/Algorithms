package JianZhiOffer2;

public class Offer2_023 {
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
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ha = headA;
        ListNode hb = headB;

        while(ha != hb){
            ha = ha != null ? ha.next : headB;
            hb = hb != null ? hb.next : headA;
        }

        return ha;
    }
    public static void main(String[] args) {

    }
}

package Basic_Algos.binarySearch;

import java.lang.reflect.Array;
import java.rmi.dgc.VMID;
import java.util.Arrays;
import java.util.Scanner;

public class LeetCode_4 {

    // 二分查找
//    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
//        if(nums1.length > nums2.length){
//            return findMedianSortedArrays(nums2, nums1);
//        }
//        int left = 0;
//        int right = nums1.length;
//        int len = nums1.length + nums2.length;
//
//        while(left <= right){
//            int mid_nums1 = left + (right - left)/2;
//            int mid_nums2 = (len+1) / 2 - mid_nums1; // 注意这里的len+1了
//
//            int nums1_left = mid_nums1==0 ? Integer.MIN_VALUE : nums1[mid_nums1-1];
//            int nums1_right = mid_nums1==nums1.length ? Integer.MAX_VALUE : nums1[mid_nums1];
//            int nums2_left = mid_nums2==0 ? Integer.MIN_VALUE : nums2[mid_nums2-1];
//            int nums2_right = mid_nums2==nums2.length ? Integer.MAX_VALUE : nums2[mid_nums2];
//
////            3  8 | 9  10
////            2  4  6 | 12  18  20
//            if (nums1_left <= nums2_right && nums1_right >= nums2_left){
//                if (len % 2 == 0){
//                    return (double)(Math.max(nums1_left, nums2_left) + Math.min(nums1_right, nums2_right))/2;
//                }else{
//                    return Math.max(nums1_left, nums2_left);
//                }
//            }else if(nums1_right < nums2_left){
//                left = mid_nums1+1;
//            }else{
//                right = mid_nums1-1;
//            }
//        }
//
//        return -1;
//    }

    // YES 边界条件！！！
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length){
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = -1;
        int right = nums1.length;
        int len = nums1.length + nums2.length;

        while(left+1 != right){
            int x = left + (right - left)/2;
            int y = (len+1)/2 - x;

            int xLeft = (x==0) ? Integer.MIN_VALUE : nums1[x-1];
            int xRight = (x==nums1.length) ? Integer.MAX_VALUE : nums1[x];
            int yLeft = (y==0) ? Integer.MIN_VALUE : nums2[y-1];
            int yRight = (y==nums2.length) ? Integer.MAX_VALUE : nums2[y];

            if (xLeft <= yRight && xRight >= yLeft){
                left = x-1;
                right = x;
                break;
            }else if(xLeft > yRight){
                right = x;
            }else{
                left = x;
            }
        }
        // 跳出循环时 left+1 = right

        int left1 = (left==-1) ? Integer.MIN_VALUE : nums1[left];
        int right1 = (right==nums1.length) ? Integer.MAX_VALUE : nums1[right];
        int y2 = (len+1)/2-right;
        int left2 = (y2==0) ? Integer.MIN_VALUE : nums2[y2-1];
        int right2 = (y2==nums2.length) ? Integer.MAX_VALUE : nums2[y2];

        if (len % 2 == 0){
            return (double)(Math.max(left1, left2) + Math.min(right1, right2))/2;
        }else{
            return Math.max(left1, left2);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] nums1 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int [] nums2 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        double res = findMedianSortedArrays(nums1, nums2);

        System.out.println(res);
    }
}

package LeetCodeHot100.Hot1to10;

import java.util.Arrays;
import java.util.Scanner;

public class Hot4 {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int len = len1 + len2;
        int i = 0, j = 0;
        int k = 0;
        if (len % 2 == 1){ // 找到第 (len/2+1) 个元素即可
            while(i < len1 || j < len2)
            {
                if (i == len1){ // 首先要判断两个数组是否有一个已经遍历完
                    k++;
                    if (k == len/2+1){
                        return nums2[j];
                    }
                    j++;
                }else if (j == len2){
                    k++;
                    if (k == len/2+1){
                        return nums1[i];
                    }
                    i++;
                }else {
                    if (nums1[i] < nums2[j]) {
                        k++;
                        if (k == len / 2 + 1) {
                            return nums1[i];
                        }
                        i++;
                    } else if (nums1[i] >= nums2[j]) {
                        k++;
                        if (k == len / 2 + 1) {
                            return nums2[j];
                        }
                        j++;
                    }
                }
            }
        }else{ // 找到第 (len/2) 和 (len/2+1)个 求平均
            int m1 = 0;
            int m2 = 0;
            while(i < len1 || j < len2)
            {
                if (i == len1){
                    k++;
                    if (k == len/2){
                        m1 = nums2[j];
                    }
                    if (k == len/2+1){
                        m2 = nums2[j];
                    }
                    j++;
                }else if (j == len2){
                    k++;
                    if (k == len/2){
                        m1 = nums1[i];
                    }
                    if (k == len/2+1){
                        m2 = nums1[i];
                    }
                    i++;
                }else {
                    if (nums1[i] < nums2[j]) {
                        k++;
                        if (k == len/2){
                            m1 = nums1[i];
                        }
                        if (k == len/2+1){
                            m2 = nums1[i];
                        }

                        i++;
                    } else if (nums1[i] >= nums2[j]) {
                        k++;
                        if (k == len/2){
                            m1 = nums2[j];
                        }
                        if (k == len/2+1){
                            m2 = nums2[j];
                        }
                        j++;
                    }
                }
            }
            return (m1+m2)/2d;
        }
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] nums1 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int[] nums2 = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        double res = findMedianSortedArrays(nums1, nums2);

        System.out.println(res);
    }
}

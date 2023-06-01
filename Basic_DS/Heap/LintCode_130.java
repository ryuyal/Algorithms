package Basic_DS.Heap;

import java.util.Arrays;
import java.util.Scanner;

public class LintCode_130 {
    public static void heapify(int[] a) {
        // write your code here
        for (int i = a.length / 2 ;  i >= 0; i--){
            heapify_helper(a, i);
        }

    }

    public static void heapify_helper(int[] arr, int index){
        int len = arr.length;
        int left = 2 * index + 1; // 左孩子
        int right = 2 * index + 2; // 有孩子

        if (left < len && arr[left] < arr[right] && arr[left] < arr[index]){
            int temp = arr[left];
            arr[left] = arr[index];
            arr[index] = temp;
            heapify_helper(arr, left);
        }else if (right < len && arr[right] < arr[index]){
            int temp = arr[right];
            arr[right] = arr[index];
            arr[index] = temp;
            heapify_helper(arr, right);
        }

    }

//    public void heapify(int[] A) {
//        // 从堆的倒数第二层开始，堆的倒数第一层都是单个node,必须是堆。
//        for (int i = (A.length - 2) / 2; i >= 0; i--) {
//            shiftdown(A, i);
//        }
//    }
//
//    private void shiftdown(int[] A, int index) {
//        int len = A.length;
//        int leftIndex = index * 2 + 1;
//        int rightIndex = leftIndex + 1;
//
//        if (rightIndex < len && A[rightIndex] < A[leftIndex] && A[rightIndex] < A[index]) {
//            swap(A, rightIndex, index);
//            shiftdown(A, rightIndex);
//        } else if (leftIndex < len && A[leftIndex] < A[index]) {
//            swap(A, leftIndex, index);
//            shiftdown(A, leftIndex);
//        }
//    }
//
//    private void swap(int[] A, int a, int b) {
//        int temp = A[a];
//        A[a] = A[b];
//        A[b] = temp;
//    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int [] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        heapify(nums);

        for (int num : nums){
            System.out.println(num );
        }
    }
}

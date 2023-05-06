package JianZhiOffer2;

import java.util.Arrays;
import java.util.Scanner;

public class Offer2_006 {
    public static int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length-1;

        while(left < right){
            if (numbers[left] + numbers[right] == target){
                return new int[]{left, right};
            }else if(numbers[left] + numbers[right] < target){
                left++;
            }else{
                right--;
            }
        }
        return null;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int target = sc.nextInt();

        int [] res = twoSum(nums, target);

        System.out.println(Arrays.toString(res));
    }
}

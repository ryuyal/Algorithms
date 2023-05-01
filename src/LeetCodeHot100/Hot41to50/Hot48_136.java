package LeetCodeHot100.Hot41to50;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Hot48_136 {
    /*
    异或运算: 相同为0 不同为1
    交换律：a ^ b ^ c <=> a ^ c ^ b
    任何数于0异或为任何数 0 ^ n => n
    相同的数异或为0: n ^ n => 0
     */
    public static int singleNumber(int[] nums) {
        int ans = 0;
        for (int num : nums){
            ans ^= num;
        }
        return ans;
    }

    public static int singleNumber2(int[] nums) {
        Set<Integer> hs = new HashSet<>();

        for (int num : nums){
            if (hs.isEmpty()){
                hs.add(num);
            }else{
                if (hs.contains(num)){
                    hs.remove(num);
                }else{
                    hs.add(num);
                }
            }
        }
        for (int num : nums){
            if (hs.contains(num)){
                return num;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] nums = Arrays.stream(
                sc.nextLine().split(" ")
        ).mapToInt(Integer::parseInt).toArray();

        int res = singleNumber(nums);

        System.out.println(res);
    }
}

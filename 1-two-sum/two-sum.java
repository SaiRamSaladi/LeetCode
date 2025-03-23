import java.util.*;

public class Solution {
    public int[] twoSum(int[] nums, int target) { 
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1}; 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter " + n + " integers: ");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        System.out.print("Enter the target value: ");
        int target = scanner.nextInt();

        Solution obj = new Solution(); 
        int[] result = obj.twoSum(nums, target); 

        System.out.println("Indices: [" + result[0] + ", " + result[1] + "]");

        scanner.close();
    }
}

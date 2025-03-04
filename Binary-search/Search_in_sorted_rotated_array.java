import java.util.ArrayList;
/*
 *  Leetcode problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *  Binary Search based solution to the above problem.
 */
public class Search_in_sorted_rotated_array {

    static int search(ArrayList<Integer> arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // if mid points to the target
            if (arr.get(mid) == k)
                return mid;
            
            // To handle the case where input can have duplicates
            if (arr.get(low) == arr.get(mid) && arr.get(mid) == arr.get(high)) {
                low = low + 1;
                high = high - 1;
                continue;
            }
            // if left part is sorted
            if (arr.get(low) <= arr.get(mid)) {
                if (arr.get(low) <= k && k <= arr.get(mid))
                    high = mid - 1;
                else
                    low = mid + 1;
            } else { // if right part is sorted
                if (arr.get(mid) <= k && k <= arr.get(high))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(7);
        arr.add(8);
        arr.add(9);
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        arr.add(5);
        arr.add(6);

        int target = 8;
        int ans = search(arr, target);

        if (ans >= 0)
            System.out.println("Target: " + target + " found at index: " + ans);
        else
            System.out.println("Target: " + target + " not found ");

    }
}

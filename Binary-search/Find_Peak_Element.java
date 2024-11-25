import java.util.ArrayList;
/*
 *  Leetcode problem link: https://leetcode.com/problems/find-peak-element/
 *  Binary Search based solution to the above problem.
 */

public class Find_Peak_Element {
    public static int findPeakElement(ArrayList<Integer> arr) {
        int n = arr.size(); 
        // Edge cases
        if (n == 1) return 0;  
        if (arr.get(0) > arr.get(1)) return 0;   // 0th index is a peak
        if (arr.get(n - 1) > arr.get(n - 2)) return n - 1;   // Last element is a peak.

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr.get(mid - 1) < arr.get(mid) && arr.get(mid) > arr.get(mid + 1))
                return mid;
            if (arr.get(mid) > arr.get(mid - 1)) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
 


    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(2);
        arr.add(1);
        arr.add(3);
        arr.add(5);
        arr.add(6);
        arr.add(4);

        int ans = findPeakElement(arr);
        
        System.out.println("A peak found at index: " + ans);

    }

}

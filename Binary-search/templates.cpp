#include<iostream>
#include<vector>
using namespace std;

// to find the index of target. If duplicates are present in arr, then in could be any one index.
int bsFindTarget(int arr[], int n, int target) {
    int left = 0, right = n-1;

    while(left <= right) {
        int mid = left + (right - left)/2;
        
        if(arr[mid] == target) return mid;

        else if(arr[mid] > target) {
            right = mid - 1;
        }

        else { left = mid + 1; }
    }

    return -1;
}

// to find the index of first element in arr which is just smaller than the given target
int bsFindFirstPossible(int arr[], int n, int target) {
    int ans_index = -1;
    int left = 0, right = n-1;

    while(left <= right) {
        int mid = left + (right - left)/2;
        
        if(arr[mid] <= target) {
            ans_index = mid;
            left = mid + 1;
        }
        else { right = mid - 1; }
    }

    return ans_index;
}

vector<int> bsFindTarget2D(vector<vector<int>> matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m*n) - 1;
    vector<int> ans_index(2, -1);

    while(low <= high) {
            
        int mid = (low + high)/2;
        int elem = matrix[mid / n][mid % n];
        
        if(elem == target) {
            ans_index[0] = mid / n; ans_index[1] = mid % n;
            return ans_index;
        }
        if(elem > target) high = mid - 1;
        else low = mid + 1;
    }

    return ans_index;
}

int main() {
    int n = 10, m = 20;
    int arr[n];

    int target;

    bsFindTarget(arr, n, target);   // to find a particular element (target) in the array

    bsFindFirstPossible(arr, n, target);    // to find the first element in array which satisfies a certain condition wrt target.

    vector<vector<int>> matrix(m, vector<int>(n));

    bsFindTarget2D(matrix, target);
}

class Solution {
public:
    
    int getElement(vector<vector<int>>& mat, int n, int mid) {
        int x = mid / n, y = mid % n;
        
        return mat[x][y];
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = (m*n) - 1;
        
        while(low <= high) {
            
            int mid = (low + high)/2;
            int elem = getElement(mat, n, mid);
            
            if(elem == target) return true;
            if(elem > target) high = mid - 1;
            else low = mid + 1;
            
        }
        
        return false;
    }
};
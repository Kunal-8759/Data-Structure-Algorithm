## Leetcode 153. Find Minimum in Rotated Sorted Array
[LeetCode 153. Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
```cpp

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            ans=min(ans,arr[mid]);
            //both half sorted
            if(arr[low]<=arr[mid] && arr[mid]<=arr[high]){
                high=mid-1;
            }
            //left half sorted
            else if(arr[low]<=arr[mid]) low=mid+1;
            //right half sorted
            else high=mid-1;
        }
        return ans;
    }
};
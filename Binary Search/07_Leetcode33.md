## [LeetCode 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

```cpp

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target) return mid;
            //left sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && target<=arr[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(arr[mid]<=target && target<=arr[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};
## Leetcode 540. Single Element in a Sorted Array
[LeetCode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
```cpp

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        //check that kahin first element hi single element na ho.
        if(arr[0]!=arr[1]) return arr[0];
        //last element single element hone ka condition
        if(arr[n-1]!=arr[n-2]) return arr[n-1];

        int low=1;
        int high=n-2;

        while(low<=high){
            int mid=low+(high-low)/2;
            //kahin jo maine mid nikala yahi to single element nahi.
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];

            //now mid is not the single element
            //ab hme ye check krna hai single element kon se half me lie krta hai.
            //according to that we will eliminate the other half.

            //if the single element lies in right half of the mid.
            if( ( mid%2==1 && arr[mid]==arr[mid-1] ) || ( mid%2==0 &&  arr[mid]==arr[mid+1] ) ){
                low=mid+1;//eliminate the left half
            }
            else{//single element lies in the left half of the mid
                high=mid-1;
            }
        }
        return -1;
    }
};
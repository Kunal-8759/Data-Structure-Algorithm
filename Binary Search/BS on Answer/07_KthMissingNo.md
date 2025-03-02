# Leetcode 1539. Kth Missing Positive Number
[Problem Link](https://leetcode.com/problems/kth-missing-positive-number/)

## Linear Thinking
```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int j=1;
        int missingCount=0;
        int i=0;

        while(i<n){
            if(arr[i]!=j){
                missingCount++;
                j++;
                if(missingCount==k){
                    return --j;
                }
            }else{
                i++;
                j++;
            }
        }
        while(missingCount!=k){
            missingCount++;
            j++;
        }
        return --j;
    }
};
```
## Binary Search
```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            //find out how much missing no are there for idx mid
            int missingNo=arr[mid]-(mid+1);
            if(missingNo<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
    }
};
```
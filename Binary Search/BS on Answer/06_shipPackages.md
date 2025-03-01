# Leetcode 1011. Capacity To Ship Packages Within D Days
[Problem Link](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

```cpp
class Solution {
public:
    vector<int> sumMinofArray(vector<int> &arr){
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        return {maxi,sum};
    }

    int countDayforCapacity(vector<int> &arr,int capacity){
        int count=0;//it will count no. of days required
        int weights=0;
        for(int i=0;i<arr.size();i++){
            if(weights + arr[i] <= capacity){
                weights+=arr[i];
            }else{
                count++;
                weights=arr[i];
            }
        }
        count++;
        return count;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        vector<int> store=sumMinofArray(arr);
        int low=store[0];
        int high=store[1];
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;//mid denotes certain capacity
            int dayRequiredforCapacity=countDayforCapacity(arr,mid);

            if(dayRequiredforCapacity <= days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
```
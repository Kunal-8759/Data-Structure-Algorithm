# Leetcode 1283. Find the Smallest Divisor Given a Threshold
[Problem Link](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)

```cpp
class Solution {
public:
    int findMax(vector<int> &arr){
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    int sumForDivisor(vector<int> &arr,int divisor){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low=1;
        int high=findMax(arr);

        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=sumForDivisor(arr,mid);

            if(sum<=threshold){
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
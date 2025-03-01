# Koko Eating Bananas
# https://leetcode.com/problems/koko-eating-bananas/  

```cpp

class Solution {
public:
    long long int calculateTotalH(vector<int>& arr, int hourly){
        long long int totalhrs=0;
        for(int i=0;i<arr.size();i++){
            totalhrs += ceil( (double)arr[i] / (double)hourly );
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        //find the max number in the array
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }

       int low=1;
       int high=maxi;
       int ans=INT_MAX;
       while(low<=high){
            int mid=low+(high-low)/2;
            long long int totalH=calculateTotalH(arr,mid);

            if(totalH <= h){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
       }
       return ans;
    }
};

```
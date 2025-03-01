# Leetcode 1482. Minimum Number of Days to Make m Bouquets
[Problem Link](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

## Linear solution
```cpp  

class Solution {
public:
    vector<int> findMinMax(vector<int> &arr){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        return {mini,maxi};
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        if(n<m*k) return -1;
        vector<int> store=findMinMax(arr);
        int mini=store[0];
        int maxi=store[1];

        for(int day=mini;day<=maxi;day++){
            int count=0;
            int NoofBoquets=0;

            for(int i=0;i<arr.size();i++){
                if(arr[i]<=day){//ith flower is bloomed
                    count++;
                }else{
                    NoofBoquets += count/k;
                    count=0;
                }
            }
            NoofBoquets+=count/k;

            if(NoofBoquets>=m) return day;
        }
        return -1;
    }
};
```

## Binary Search
```cpp

class Solution {
public:
    vector<int> findMinMax(vector<int> &arr){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        return {mini,maxi};
    }
    int findTotalBoquestonDay(vector<int> &arr,int day,int k){
        int count=0;
        int NoofBoquets=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){//ith flower is bloomed
                count++;
            }else{
                NoofBoquets += count/k;
                count=0;
            }
        }
        NoofBoquets+=count/k;//last me count bacha ho but loops end 

        return NoofBoquets;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        long long totalFlowerReq=(long)m*(long)k;
        if(n<totalFlowerReq) return -1;
        vector<int> store=findMinMax(arr);
        int low=store[0];
        int high=store[1];

        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            int NoofBouquets=findTotalBoquestonDay(arr,mid,k);

            if(NoofBouquets >= m){
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
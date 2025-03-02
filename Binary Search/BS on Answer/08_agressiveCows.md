# Agressive Cows
[Problem Link](https://www.geeksforgeeks.org/problems/aggressive-cows/0)

```cpp

class Solution {
  public:
    int NoCowsPlaced(vector<int> &arr,int dist){
        int cowPlanted=1;
        int lastCordinate=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastCordinate >= dist){
                cowPlanted++;
                lastCordinate=arr[i];
            }
        }
        return cowPlanted;
    }

    int aggressiveCows(vector<int> &arr, int cows) {
        
        sort(arr.begin(),arr.end());
        int low=1;
        int high=arr[arr.size()-1]-arr[0];
        int ans=INT_MIN;
        
        while(low<=high){
            int mid=low+(high-low)/2;//mid denotes the min distance between two cows
            int cowsPlaced=NoCowsPlaced(arr,mid);
            
            if(cowsPlaced>=cows){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        return ans;
        
    }
};
```
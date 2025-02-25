class Solution {
    public:
      int upperBound(vector<int>& arr, int target) {
          // code here
          int low=0;
          int high=arr.size()-1;
          int ans=arr.size();
          
          while(low<=high){//search space
              int mid=low+(high-low)/2;
              if(arr[mid]>target){
                  ans=mid;
                  high=mid-1;
              }else{
                  low=mid+1;
              }
          }
          return ans;
      }
  };
## Find Kth Rotation
[GeeksforGeeks](https://practice.geeksforgeeks.org/problems/rotation4723/1)

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0;
        int high=arr.size()-1;
        
        int minElement=INT_MAX;
        int minIdx=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]<minElement){
                minElement=arr[mid];
                minIdx=mid;
                
            }
            
            //right half sorted
            if(arr[mid]<=arr[high]){
                high=mid-1;
            }
            
            //left half sorted or both half sorted
            
            else{
                low=mid+1;
            }
        }
        return minIdx;
    }
};

## GFG Link
[Count the frequency of a number in an array](https://practice.geeksforgeeks.org/problems/frequency-of-elements-1587115620/1)

class Solution {
  public:
    int firstOccurance(vector<int>& arr,int target){
        int low=0;
        int high=arr.size()-1;
        int firstOccurance=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                firstOccurance=mid;
                high=mid-1;
            }
            else if(target<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        return firstOccurance;
    }

    int lastOccurance(vector<int>& arr,int target){
        int low=0;
        int high=arr.size()-1;
        int lastOccurance=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                lastOccurance=mid;
                low=mid+1;
            }
            else if(target<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        return lastOccurance;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int firstOccuranceIdx=firstOccurance(arr,target);
        int lastOccuranceIdx=lastOccurance(arr,target);
        
        if(firstOccuranceIdx==-1 ) return 0;
        return lastOccuranceIdx-firstOccuranceIdx+1;
    }
};
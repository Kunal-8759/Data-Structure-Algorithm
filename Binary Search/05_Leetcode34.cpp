class Solution {
    public:
        int lowerBound(vector<int>& arr,int target){
            int low=0;
            int high=arr.size()-1;
            int ans=arr.size();
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[mid]>=target){
                    ans=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            return ans;
        }
        int upperBound(vector<int>& arr,int target){
            int low=0;
            int high=arr.size()-1;
            int ans=arr.size();
            while(low<=high){
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
        vector<int> searchRange(vector<int>& arr, int target) {
            int lb=lowerBound(arr,target);
            int ub=upperBound(arr,target);
    
            if(lb==arr.size() || arr[lb]!=target)  return {-1,-1};
            return {lb,ub-1};
        }
    };



    ### Method 2 : 

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
            vector<int> searchRange(vector<int>& arr, int target) {
                return { firstOccurance(arr,target),lastOccurance(arr,target) };
            }
        };
class Solution {
    public:
        int trap(vector<int>& arr) {
            int n=arr.size();
            vector<int> prefixMax(n);
            vector<int> suffixMax(n);
    
            prefixMax[0]=arr[0];
            for(int i=1;i<n;i++){
                prefixMax[i]=max(prefixMax[i-1],arr[i]);
            }
            suffixMax[n-1]=arr[n-1];
            for(int i=n-2;i>=0;i--){
                suffixMax[i]=max(suffixMax[i+1],arr[i]);
            }
    
            int total=0;
            for(int i=0;i<n;i++){
                int leftMax=prefixMax[i];
                int rightMax=suffixMax[i];
                if(leftMax>arr[i] && rightMax>arr[i]){
                    total+=min(leftMax,rightMax)-arr[i];
                }
            }
            return total;
        }
    };
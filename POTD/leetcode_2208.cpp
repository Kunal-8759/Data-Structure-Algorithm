class Solution {
    public:
        int halveArray(vector<int>& nums) {
            priority_queue<double> pq;
            double totalSum=0;
            for(int i=0;i<nums.size();i++){
                totalSum+=nums[i];
                pq.push(nums[i]);
            }
            double currSum=totalSum;
    
            int op=0;
            while(currSum>totalSum/2 && pq.size()>0){
                double value = pq.top()/2;
                currSum-=value;
                pq.pop();
                pq.push(value);
                op++;
            }
            return op;
    
    
        }
    };
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long , vector<long> ,greater<long> > pq;
    
            for(int i=0;i<nums.size();i++){
                pq.push(nums[i]);
            }
            int count=0;
            while(pq.size()>=2 && pq.top()<k){
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                pq.pop();
                long z=min(x,y)*2L + max(x,y);
                pq.push(z);
                count++;
            }
    
            return count;
        }
    };
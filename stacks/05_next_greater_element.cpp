class Solution{
    public:
        vector<int> nge(int n, int arr[]){
            // code here
            stack<int> st;
            vector<int> ans(n);
            for(int i=n-1;i>=0;i--){
                while(st.size()>0 && arr[i]>=st.top()){
                    st.pop();
                }
                if(st.size()==0) ans[i]=-1;
                else ans[i]=st.top();
                
                st.push(arr[i]);
            }
            return ans;
        }
};
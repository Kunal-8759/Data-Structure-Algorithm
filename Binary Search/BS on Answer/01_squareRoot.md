## [Problem Link](https://practice.geeksforgeeks.org/problems/square-root/1#)

### linear search
```cpp

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int ans=1;
        for(int i=1;i<=n;i++){
            if(i*i <= n){
                //might be ans
                ans=i;
            }else{
                break;
            }
        }
        return ans;
    }
};

### Binary Search
```cpp

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low=1;
        int high=n;
        
        int ans=1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            //you are standing at tick .
            //this might be our ans.so store it
            //iske left me ans nhi ho skta hai
            if(mid*mid <= n){
                ans=mid;
                low=mid+1;
            }
            
            //standing at the cross .
            //this never be our ans
            //so right of this can also be never be the ans so eliminate that
            
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};
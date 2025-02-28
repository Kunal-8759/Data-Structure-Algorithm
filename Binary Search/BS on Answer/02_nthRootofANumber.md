# Find nth root of m
## [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1)

## Linear Search

```cpp
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        
        for(int i=1;i<=m;i++){
            // int prod=1;
            // for(int j=1;j<=n;j++){
            //     prod=prod*i;
            // }

            int prod=pow(i,n);

            if(prod==m) return i;
            if(prod>m) break;
        }
        return -1;
    }
};

```

## Binary Search

```cpp
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        
        int low=1;
        int high=m;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int prod=pow(mid,n);
            
            if(prod==m) return mid;
            else if(prod<m){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};
```
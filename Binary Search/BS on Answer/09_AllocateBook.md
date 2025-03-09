
```cpp
vector<int> findMaxiSum(vector<int>& arr){
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
        sum+=arr[i];
    }
    return{maxi,sum};
}
int findNoStudent(vector<int> &arr,int page){
    int student=1;//
    long long pageStudent=0;//currently he is having 0 page for the student 1
    for(int i=0;i<arr.size();i++){
        if(pageStudent+arr[i]<=page){
            pageStudent+=arr[i];
        }else{
            student++;
            pageStudent=arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    vector<int> store=findMaxiSum(arr);
    int low=store[0];
    int high=store[1];

    // for(int page=low;page<=high;page++){
    //     int countStudent=findNoStudent(arr,page);
    //     if(countStudent==m) return page;
    // }

    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int countStudent=findNoStudent(arr,mid);

        if(countStudent>m){
            low=mid+1;
        }
        else if(countStudent<m){
            high=mid-1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
```
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int target) {
	// Write your code here.
	int floor=-1;
	int low=0;
	int high=n-1;

	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]<=target){
			floor=arr[mid];
			low=mid+1;
		}else{
			high=mid-1;
		}
	}

	int ceil=-1;
	low=0;
	high=n-1;

	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=target){
			ceil=arr[mid];
			high=mid-1;
		}else{
			low=mid+1;
		}
	}

	pair<int ,int> p;
	p.first=floor;
	p.second=ceil;

	return p;
}
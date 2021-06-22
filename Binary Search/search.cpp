class Solution {
	public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int pivot = pivotedBinarySearch(nums, 0, n-1);
		if(pivot == -1) return binarySearch(nums, 0, n-1, target);
		if(nums[pivot] == target) return pivot;
		if(nums[0] <= target) return binarySearch(nums, 0, pivot-1, target);
		return binarySearch(nums, pivot+1, n-1, target);
		
	}

	int pivotedBinarySearch(vector<int> arr, int low, int high) {
		if(high < low) return -1;
		if(high == low) return low;
		int mid = low + (high - low)/2;
		
		if(mid > low && arr[mid] < arr[mid-1]) return mid-1;
		if(mid < high && arr[mid] > arr[mid+1]) return mid;
		if(arr[low]>=arr[mid]) return pivotedBinarySearch(arr, low, mid-1);
		return pivotedBinarySearch(arr, mid+1, high);
	}


	int binarySearch(vector<int>arr, int low, int high, int key) {
		if(high < low) return -1;
		int mid = low + (high - low)/2;
		if(arr[mid] == key) return mid;
		if(arr[mid] > key) return binarySearch(arr, low, mid-1, key);
		return binarySearch(arr, mid+1, high, key);
	}
};

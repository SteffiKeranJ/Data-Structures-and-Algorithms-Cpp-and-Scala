int binarySearch(int low, int high, int key, int arr[]) {
    if(low < high) {
    int mid = (low + high)/2;
    if(key <= arr[mid]) return binarySearch(low, mid, key, arr);
    else return binarySearch(mid+1, high, key, arr);
    }
    return low;
}


int binarySearchHi(int low, int high, int key,  int arr[]) {
    if(low < high ) {
    int mid = (low + high)/2;
    
    if(key >= arr[mid]) return binarySearchHi(mid+1, high, key,  arr);
    else return binarySearchHi(low, mid, key, arr);
    }
   return high;
}


vector<int> find(int arr[], int n , int x )
{
    int low = binarySearch(0, n, x, arr);
    int high = binarySearchHi(0, n, x,  arr);
    if(low==high) {
        return vector<int>{-1, -1};
    }
    return vector<int>{low, high-1};
}

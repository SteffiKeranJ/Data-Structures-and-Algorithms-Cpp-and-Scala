long long int binarySearch(long long int low, long long int high, long long int x) {
	if(low > high ) return low-1;
	long long int mid = low + (high - low) / 2;
	long long int midSquare = mid * mid;
	if(midSquare == x) return mid;
	if(midSquare > x) return binarySearch(low, mid -1, x);
	return binarySearch(mid+1, high, x);
}


long long int floorSqrt(long long int x) 
{
    if(x==0 || x==1) return x;
    return binarySearch(0, x, x);
}

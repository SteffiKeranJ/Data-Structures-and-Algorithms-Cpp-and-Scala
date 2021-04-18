#include <iostream>
using namespace std;
 
int minimum(int a, int b) {
	return a > b ? b : a;
}
 
int main()
{
	int d, sumTime;
	int minhours[30];
	int maxhours[30];
	cin >> d >> sumTime;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < d; ++i) {
		cin >> minhours[i] >> maxhours[i];
		sum1 += minhours[i];
		sum2 += maxhours[i];
 	}
 
	if (sum1 <= sumTime && sumTime <= sum2) {
		cout << "YES" << endl;
		for (int j = 0; j < d; ++j) {
			int t = minimum(minhours[j] + sumTime - sum1, maxhours[j]);
			if (j + 1 >= d) {
				cout << t  << endl;
			}
			else {
				cout << t << " ";
			}
			sumTime -= (t - minhours[j]);
		}
	}
	else cout << "NO" << endl;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
	int T;
	string word;
	
	cin >> T;

	while (T > 0) {
		cin >> word;
		if (word.length() <= 10) cout << word << endl;
		else {
			cout << word[0] << to_string(word.size() - 2) << word[word.length() - 1] << endl;
		}
		T--;
	}

	return 0;

}

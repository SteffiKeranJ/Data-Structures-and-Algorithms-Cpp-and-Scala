class Solution{
	public: 
int lengthLongestPath(string input) {
int i = 0, count = 0, level = 1, maxlen = 0; 
bool isFile = false;
int length = input.size();
unordered_map<int, int> levelLength; // hash map
while (i < length) {
	while (input[i]=='\t') { //single quotes for character check
	++i;
	++level;
}
while(i < length && input[i]!='\n') {
// to find if there is a file
if (input[i]=='.') { // single quotes for character check
	isFile = true;
}
++i;
++count;
}
if (isFile) { // no need to check if equal to true for a boolean variable
	maxlen = max(maxlen, count+levelLength[level-1]); //typo
} else {
	levelLength[level] =count+levelLength[level-1] + 1; // typo
}
++i; // iterator was unknowingly set to 1
level = 1; // missed this condition
count = 0;
isFile = false;
}
return maxlen;
}
};

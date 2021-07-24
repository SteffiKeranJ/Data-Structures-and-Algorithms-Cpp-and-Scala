/** 953. Verifying an Alien Dictionary

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
**/

class Solution {
public:
    unordered_map<char, int> hashMap;
    
    bool isSorted(string s1, string s2) {
        int l1 =s1.size();
        int l2 = s2.size();
        int minLength = min(l1, l2);
        for(int i = 0; i < minLength; ++i) {
           
            int rank1 = hashMap[s1[i]];
            int rank2 = hashMap[s2[i]];
            
            if(rank1!=rank2) return rank1 <= rank2;
        }
        return l1 <= l2;
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n == 1) return true;
        int dictSize = order.size();
        int i;
        for(i = 0; i < dictSize; ++i) {
            hashMap[order[i]] = i+1;
        }

        for(i = 0; i < n-1; ++i) {
            if (!isSorted(words[i], words[i+1])) return false;
        }
        
        return true;
    }
};

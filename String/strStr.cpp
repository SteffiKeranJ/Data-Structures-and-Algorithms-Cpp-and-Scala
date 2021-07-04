/**
28. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Approach: Rabin Karp string matching algorithm
**/

  int strStr(string haystack, string needle) {
        if(!haystack.size() && !needle.size()) return 0;
        int base =  256;
        int moduloPrime = 101;
        
        int n = haystack.size();
        int m = needle.size();
        
        int i, j; // iterator
        int h = 1;
        int pHash = 0;
        int sHash = 0;
        // hash function
        for(i = 0; i < m-1; ++i) {
            h = (h *base) % moduloPrime; 
        }
        
        // calculate the hash for pattern and first window of the string
        for(i = 0; i < m; ++i) {
            pHash = (base * pHash + needle[i]) % moduloPrime;
            sHash = (base * sHash + haystack[i]) % moduloPrime;
        }
        
        for(i = 0; i <= n-m; ++i) {
            if(pHash == sHash) {
                // do character by character comparison
                for(j =0 ; j < m; ++j) {
                    if(haystack[i+j]!=needle[j]) break;
                }
            }
            if(j == m) return i; // first occurence is found
            // else compute the hash for next window
            if ( i < n-m ) {
                sHash = (base * (sHash - haystack[i]*h) + haystack[i+m])%moduloPrime;
                if(sHash < 0) sHash += moduloPrime;
            }
            
        }
        
        
        return -1;
    }
};

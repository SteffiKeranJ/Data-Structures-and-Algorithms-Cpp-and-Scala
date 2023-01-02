```
We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false

```
object Solution {
    def detectCapitalUse(word: String): Boolean = {
        val n = word.length()
        if (word.forall(_.isUpper) || (word.forall(_.isLower))) return true
        if((word.take(1)== word.take(1).toUpperCase) && (word.substring(1,n) == word.substring(1,n).toLowerCase)) return true
        return false
    }
}

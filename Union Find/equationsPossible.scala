/**
990. Satisfiability of Equality Equations
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
*/


object Solution {
    val unionFind = new Array[Int](26)
    
    def find(x: Int): Int = if(unionFind(x) == x)  x else find(unionFind(x))
    
    def equationsPossible(equations: Array[String]): Boolean = {
        for( i <- 0 to 25) unionFind(i) = i
        for (e <- equations) {
            if (e(1) == '=') unionFind(find(e(0) - 'a')) = find(e(3) - 'a')
        }
        for (e <- equations) {
            if (e(1) == '!' && find(e(0) - 'a') == find(e(3) - 'a')) return false
        }
        return true
    }
}

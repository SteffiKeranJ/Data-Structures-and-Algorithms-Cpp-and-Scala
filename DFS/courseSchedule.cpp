/** 
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
**/

class Solution {
public:
    bool visited[100001] = {false};
    bool DFS(int v, vector<int> adjList[]) {
        if(visited[v] == true) return false; // cycle is detected
        if(!adjList[v].size()) return true; 
        visited[v] = true;
        for(int i  = 0; i < adjList[v].size(); ++i) {
            if(!DFS(adjList[v][i], adjList)) return false;
        }
        visited[v] = false;
        adjList[v].clear();
        return true;       
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create the adjacency list
        vector<int> adjList[5001];
        int i, n = prerequisites.size();
        for(i = 0; i < n;++i) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(i =0 ; i < numCourses; ++i) {
            if(!DFS(i, adjList)) return false;
        }
        
        return true;
    }
};

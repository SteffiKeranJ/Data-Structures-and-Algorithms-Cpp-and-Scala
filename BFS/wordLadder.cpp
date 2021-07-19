/** 
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

**/

class Solution {
public:
    #define MAX 5001

    vector<int>adj[5001];
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<int> dist(MAX , INT_MAX);
        vector<bool> visited (MAX, false);
          int destinationidx = -1;
          int n = wordList.size();

          for(int i = 0; i < n; ++i) {
            if(distance(endWord, wordList[i]) == 0) destinationidx = i+1;
          }
          if(destinationidx == -1) return 0;
          for(int i = 0; i < n;++i) {
            if(distance(beginWord, wordList[i]) == 1 )
              adj[0].push_back(i+1);
          }

          for(int i = 0; i < n;++i) {
            for(int j = 0; j < n; ++j) {
              if(j!=i && distance(wordList[i], wordList[j])==1) {
                adj[i+1].push_back(j+1);
              }
            }
          }
          queue<int>q;
          q.push(0);
          dist[0] = 0;
          while(!q.empty()) {
            int front =  q.front();
            visited[front] = true;

            q.pop();
            for(int j = 0; j < adj[front].size(); ++j) {
              if(visited[adj[front][j]] == false) {
                if( dist[front] < dist[adj[front][j]]) dist[adj[front][j]] = 1+dist[front];
                q.push(adj[front][j]);

              }
            }
          }

      return dist[destinationidx] == INT_MAX ? 0: dist[destinationidx]+1;
    }
    int distance(string& s1, string& s2) {
      int counter = 0;
      int l1 = s1.size();
      int l2 = s2.size();
      for(int i = 0; i < l1; ++i) {
        if(s1[i] == s2[i]) continue;
        counter++;
      }
      return counter;
    }

};

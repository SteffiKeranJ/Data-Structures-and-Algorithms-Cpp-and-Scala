class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> unique;
      for (auto &e: emails) {
        string temp;
        auto it = e.begin();
        for(; '@'!=*it && '+'!=*it; it++){
          if('.'!=*it) {
        temp+=*it;
      }
    }

    it = find(it, e.end(), '@');
    temp.append(it, e.end());
    unique.insert(temp);
    }
    return unique.size();
    }
  }
};	

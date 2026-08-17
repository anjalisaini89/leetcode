#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string>> memo;
    
    vector<string> backtrack(const string& s, const unordered_set<string>& wordSet) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            
            if (wordSet.find(prefix) != wordSet.end()) {
                string suffix = s.substr(i);
                vector<string> suffixResults = backtrack(suffix, wordSet);
                
                for (const string& subsentence : suffixResults) {
                    if (subsentence.empty()) {
                        result.push_back(prefix);
                    } else {
                        result.push_back(prefix + " " + subsentence);
                    }
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        memo.clear();
        return backtrack(s, wordSet);
    }
};

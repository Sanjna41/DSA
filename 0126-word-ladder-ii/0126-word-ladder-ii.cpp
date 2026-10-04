class Solution {
    unordered_map<string, int> dist;
    vector<vector<string>> ans;

    void dfs(string& word, string& beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> fullPath = path;
            reverse(fullPath.begin(), fullPath.end());
            ans.push_back(fullPath);
            return;
        }

        int curDist = dist[word];
        string temp = word;

        // Try changing each character to find predecessor in the BFS tree
        for (int i = 0; i < temp.size(); i++) {
            char original = temp[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (dist.count(temp) && dist[temp] == curDist - 1) {
                    path.push_back(temp);
                    dfs(temp, beginWord, path);
                    path.pop_back();
                }
            }
            temp[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        dict.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            if (word == endWord) break;

            int curStep = dist[word];
            string nextWord = word;

            for (int i = 0; i < nextWord.size(); i++) {
                char original = nextWord[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    nextWord[i] = ch;
                    if (dict.count(nextWord)) {
                        dist[nextWord] = curStep + 1;
                        dict.erase(nextWord);
                        q.push(nextWord);
                    }
                }
                nextWord[i] = original;
            }
        }
        if (dist.count(endWord)) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path);
        }

        return ans;
    }
};
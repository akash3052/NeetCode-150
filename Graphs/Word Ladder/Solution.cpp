class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end() || beginWord == endWord){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();
            if(word == endWord){
                return steps;
            }
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                // we are exploring all the possible neighbours of the current word 
                // by changing value from 'a' to 'z' for the all the indices of that word.
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    // If that word(temp) after changing character is not present in our wordList, then it is not valid word
                    // we will skip that word otherwise we will add that word in the queue and delete that from wordList
                    if(words.find(temp) != words.end()){
                        q.push({temp, steps + 1});
                        // we are deleting because we if same word come again we will not process that again
                        // otherwise we will form loop 
                        // Without erase, the same word keeps coming back into the queue.
                        // Example: "dot" → "dog" → "dot" cycle.
                        // Example: "lot" → "log" → "lot" cycle.
                        words.erase(temp); 
                    }
                }   
            }
        }
        return 0;
    }
};

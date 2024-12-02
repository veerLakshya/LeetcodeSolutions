class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence = ' ' + sentence;
        searchWord = ' ' + searchWord;
        size_t found = sentence.find(searchWord);
        
        if (found != std::string::npos) {
            int cnt = 0;
            for(int i = 0; i < found; i++){
                if(sentence[i]==' ')cnt++;
            }
            return cnt+1;
        } else {
            return -1;
        }
        return 0;
    }
};
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            
            string word = words[i];
            char firstChar = tolower(word[0]);

            string currentRow;
            if (row1.find(firstChar) != string::npos)
                currentRow = row1;
            else if (row2.find(firstChar) != string::npos)
                currentRow = row2;
            else
                currentRow = row3;

            bool valid = true;

            for (int j = 0; j < word.length(); j++) {
                char c = tolower(word[j]);

                if (currentRow.find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.push_back(word);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<string> results;
    
    void perm(string input, int st) {
        //cout << input.size() << st << endl;
        for (int i=st;i<input.size();i++) {
            if (isalpha(input[i])) {
                //cout << input[i] << endl;
                input[i] = tolower(input[i]);
                //cout << input[i] << endl;
                perm(input, i+1);
                input[i] = toupper(input[i]);
                //cout << input[i] << endl;
                perm(input, i+1);
                return;
            }
        }
        //cout << st << endl;
        results.push_back(input);
        return;
    }
    
    vector<string> letterCasePermutation(string S) {
        perm(S, 0);
        return results;
    }
};

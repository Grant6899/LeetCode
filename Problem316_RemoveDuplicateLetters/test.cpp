/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 22:04:06 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> res;
        vector<int> last(26, 0), pushed(26, 0);

        for(int i = 0; i < s.size(); ++i)
            last[s[i]-'a'] = i;

        for(int i = 0; i < s.size(); ++i){
            
            if(pushed[s[i]-'a'])
                continue;
            
            while(!res.empty() && s[i] < s[res.back()] && i < last[s[res.back()]-'a']){
                pushed[s[res.back()]-'a'] = false;
                res.pop_back();
            }

            res.push_back(i);
            pushed[s[i]-'a'] = true;

            for(int index : res )
                cout << s[index] << " ";
            cout << endl;
        }

        string str = "";
        for(int i : res)
            str += s[i];

        return str;
    }
};

int main(){
    
    Solution s;

    cout << s.removeDuplicateLetters("bbcaac") << endl;


    return 0;
}

/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 22:32:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> map;
        
        int max_count = 0;
        char max_ch;
        
        for(char ch : S)
            map[ch]++;
        
        string current = "";
        bool res = find(0, current, map, S);
        if(res) return current;    
        else return "";
    }
    
    bool find(int index, string& current, unordered_map<char, int>& map, string S){
        if(index == S.size())
            return true;
        
        for(auto ele : map){
            if((current == "" || ele.first != current.back()) && ele.second > 0){
                map[ele.first]--;
                current += ele.first;
                if(find(index+1, current, map, S))
                   return true;
                current.pop_back();
                map[ele.first]++;
            }
        }
        
        return false;
    }
};

int main(){
    Solution s;

    cout << s.reorganizeString("kkkkzrkatkwpkkkktrq") << endl;

    return 0;
}

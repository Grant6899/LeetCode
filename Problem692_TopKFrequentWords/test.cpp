/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 22:43:53 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;

        for(auto ele : words)
            counts[ele]++;

        vector<pair<string, int>> seq;
        for(auto ele : counts)
            seq.push_back(make_pair(ele.first, ele.second));

        nth_element(seq.begin(), 
                    seq.begin() + k, 
                    seq.end(), 
                    [](pair<string, int>& a, pair<string, int>& b){ 
                        if(a.second != b.second)
                            return a.second > b.second;
                        else
                            return a.first > b.first;
                    });

        partial_sort(seq.begin(), 
                     seq.begin() + k, 
                     seq.end(), 
                     [](pair<string, int>& a, pair<string, int>& b){ 
                         if(a.second != b.second)
                             return a.second > b.second;
                         else
                             return a.first > b.first;
                     });
        
        vector<string> res;
        for(int i = 0; i < k; i++)
            res.push_back(seq[i].first);
    
        return res;
    }
};

int main(){
    Solution s;

    vector<string> words {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    
    auto ans = s.topKFrequent(words, 4);

    for (int i = 0;i < ans.size(); ++i)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}

/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:19:19 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> lastR(dominoes.size(), -1), lastL(dominoes.size(), -1), nextL(dominoes.size(), dominoes.size()), nextR(dominoes.size(), dominoes.size());

        int last_R = -1, last_L = -1, next_R = dominoes.size(), next_L = dominoes.size();

        for(int i = 0; i < dominoes.size(); ++i){
            if(dominoes[i] == 'R')
                last_R = i;
            if(dominoes[i] == 'L')
                last_L = i;
            lastR[i] = last_R;
            lastL[i] = last_L;
        }

        for(int i = dominoes.size() - 1; i >= 0; --i){
            if(dominoes[i] == 'L')
                next_L = i;
            if(dominoes[i] == 'R')
                next_R = i;
            nextL[i] = next_L;
            nextR[i] = next_R;
        }
        /*
        cout << "\nlastR: ";
        for(int i = 0; i < dominoes.size(); ++i){
            cout << lastR[i] << " ";
        }

        cout << "\nlastL: ";
        for(int i = 0; i < dominoes.size(); ++i){
            cout << lastL[i] << " ";
        }

        cout << "\nnextR: ";
        for(int i = 0; i < dominoes.size(); ++i){
            cout << nextR[i] << " ";
        }

        cout << "\nnextL: ";
        for(int i = 0; i < dominoes.size(); ++i){
            cout << nextL[i] << " ";
        }
        */

        string res = dominoes;

        for(int i = 0; i < dominoes.size(); ++i){
            if(res[i] == '.'){
                if(lastR[i] == -1){
                    if(nextR[i] > nextL[i])
                        res[i] = 'L';
                    continue;
                }
                if(nextL[i] == dominoes.size()){
                    if(lastL[i] < lastR[i])
                        res[i] = 'R';
                    continue;
                }

                if(lastR[i] < lastL[i] && nextR[i] < nextL[i])
                    res[i] = '.';
                else if(max(lastR[i], lastL[i]) == lastR[i] && min(nextL[i], nextR[i]) == nextR[i])
                    res[i] = 'R';
                else if(max(lastR[i], lastL[i]) == lastL[i] && min(nextL[i], nextR[i]) == nextL[i])
                    res[i] = 'L';
                else{
                    if(i - lastR[i] > nextL[i] - i)
                        res[i] = 'L';
                    else if(i - lastR[i] < nextL[i] - i)
                        res[i] = 'R';
                    else
                        res[i] = '.';
                }
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    cout << s.pushDominoes(".L.R...LR..L..") << endl;
    return 0;
}

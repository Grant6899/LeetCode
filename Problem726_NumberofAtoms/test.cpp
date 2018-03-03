/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 19:34:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        
        map<string, int> res;
        int index = 0;
        res = count(formula, index);

        string str = "";

        for(auto it = res.begin(); it != res.end(); ++it)
            str += it->first + (it->second == 1? "" : to_string(it->second));
        

        return str;
    }

    map<string, int> count(string formula, int& index){
        map<string, int> current;

        while(index < formula.size()){
            if( formula[index] == '(' ){
                index++;
                map<string, int> sub = count(formula, index);
                
                for(auto p : sub)
                    current[p.first] += p.second; 
            }
            else if(formula[index] == ')'){
                if(formula.size() <= index + 1 || !isdigit(formula[index+1]))
                    return current;
                else{

                    string num = formula.substr(++index, 1);
                    index++;
                    while(index < formula.size() && isdigit(formula[index]))
                        num += formula[index++];
                
                    int times = stoi(num);
 
                    for(auto it = current.begin(); it != current.end(); ++it)
                         it->second = it->second * times;
                    return current;
                }
            }
            else{
                    string name = "";
                    name += formula[index++];
                    while(formula[index] <= 'z' && formula[index] >= 'a')
                        name += formula[index++];
                    
                    if(formula.size() <= index || !isdigit(formula[index]))   
                        current[name]++;
                    else{
                        string num = formula.substr(index++, 1);
                        while(index < formula.size() && isdigit(formula[index]))
                            num += formula[index++];
                        
                        current[name] += stoi(num);

                    }
            }
        }
        return current;
    }
};

int main(){
    Solution s;

    //cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;
    cout << s.countOfAtoms("(Cm39)5(Ga28Sb45Rb8)20(Bk13Fr29As)45") << endl;

    return 0;
}

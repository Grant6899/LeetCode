/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb 24 07:13:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;  

//输出最短路径  
void  prn_pass(int j , int k, vector<vector<int>>& Path){  
    if (Path[j][k]!=-1){  
        prn_pass(j,Path[j][k], Path);  
        cout<<"-->"<<Path[j][k];  
        prn_pass(Path[j][k],k, Path);  
    }  
}  

vector<vector<int>> Floyd(vector<vector<int>>& map){
    int n = map.size();    
    vector<vector<int>> res(map);
    vector<vector<int>> Path(n, vector<int>(n, -1));
    
    for (int k = 0;k < n;k++)  
        for (int i = 0;i < n;i++)  
            for (int j = 0;j < n;j++){  
                if (res[i][k] + res[k][j] > 0 && res[i][k] + res[k][j] < res[i][j]){  
                    res[i][j] = res[i][k] + res[k][j];  
                    Path[i][j] = k;  
                }  
            }  

    //输出最短路径和权值  
    for (int i = 0;i < n;i++)  
        for (int j = 0;j < n;j++){  
            if (i!=j)  
            {  
                cout<<i<<"到"<<j<<"的最短路径为:";  
                cout<<i;  
                prn_pass(i,j, Path);  
                cout<<"-->"<<j<<endl;  
                cout<<"最短路径长度为:"<<res[i][j]<<endl;  
            }  
        }  
   return res;
}

int main(){  
    int n = 7, e = 11;  
    vector<vector<int>> map(n, vector<int>(n, INT_MAX));
    vector<vector<int>> paths{{0, 1, 7},
                              {0, 3, 5},
                              {1, 2, 8},
                              {1, 3, 9},
                              {1, 4, 7},
                              {2, 4, 5},
                              {3, 4, 15},
                              {3, 5, 6},
                              {4, 5, 8},
                              {4, 6, 9},
                              {5, 6, 11}};



    for (auto p : paths){  
        map[p[0]][p[1]] = p[2];
        map[p[1]][p[0]] = p[2];
    }  

    auto res = Floyd(map);
    
    return 0;  
}  

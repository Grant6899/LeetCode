/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 21:03:24 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void printNeighbor(UndirectedGraphNode* ptr){
    cout << ptr->label <<"'s neighbors:\n'";
    for(int i = 0; i < ptr->neighbors.size(); ++i)
        cout << ptr->neighbors[i]->label << " ";
    cout << endl;
}


class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return nullptr;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        unordered_set<int> created;
        vector<UndirectedGraphNode*> current{node};
        
        while(!current.empty()){
            vector<UndirectedGraphNode*> current_neighbors;            
            for(int i = 0; i < current.size(); ++i){
                if(created.find(current[i]->label) == created.end()){
                    UndirectedGraphNode* tmp = new UndirectedGraphNode(current[i]->label);
                    map[current[i]] = tmp;
                    created.insert(tmp->label);
                    for(int j = 0; j < current[i]->neighbors.size(); ++j)
                        if(created.find(current[i]->neighbors[j]->label) == created.end())
                            current_neighbors.push_back(current[i]->neighbors[j]);

                }
            }
            current = current_neighbors;
        }

        current.push_back(node);

        while(!current.empty()){
            vector<UndirectedGraphNode*> current_neighbors;            
            for(int i = 0; i < current.size(); ++i){
                if(created.find(current[i]->label) != created.end()){
                    created.erase(current[i]->label);
                    
                    int j_max =  current[i]->neighbors.size();
                    for(int j = 0; j < current[i]->neighbors.size(); ++j){
                        map[current[i]]->neighbors.push_back(map[current[i]->neighbors[j]]);
                        if(created.find(current[i]->neighbors[j]->label) != created.end())
                            current_neighbors.push_back(current[i]->neighbors[j]);
                    }
                }
            }
            current = current_neighbors;
        }

        return map[node];
    }
};


int main(){

    UndirectedGraphNode* n0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* n1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* n2 = new UndirectedGraphNode(2);

    (n0->neighbors).push_back(n1);
    (n0->neighbors).push_back(n2);
    (n1->neighbors).push_back(n0);
    (n1->neighbors).push_back(n2);
    (n2->neighbors).push_back(n0);
    (n2->neighbors).push_back(n1);
    (n2->neighbors).push_back(n2);

    Solution s;
    auto ans = s.cloneGraph(n0);
     
    printNeighbor(ans);
    printNeighbor(ans->neighbors[0]);
    printNeighbor(ans->neighbors[1]);

    return 0;    
}

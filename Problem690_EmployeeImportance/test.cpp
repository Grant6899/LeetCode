/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 18 19:24:18 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
    Employee(int _id, int _impo, vector<int> _sub) : id(_id), importance(_impo), subordinates(_sub){}
};

class Solution {
private:
map<int, int> mapping;

public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto it = employees.begin(); it < employees.end(); ++it){
            mapping[(*it)->id] = it - employees.begin(); 
        }
        return getImportance1(employees, id);
    }

    int getImportance1(vector<Employee*> employees, int id) {
        auto ptr = employees[mapping[id]];
        int result = 0;
        for(auto it = ptr->subordinates.begin(); it < ptr->subordinates.end(); ++it){
            result+= getImportance1(employees, *it);
        }
        result+=ptr->importance;
        return result;
    }
};

int main(){
    Employee* p1 = new Employee(1, 5, {2, 3});
    Employee* p2 = new Employee(2, 3, {});
    Employee* p3 = new Employee(3, 3, {});

    Solution s;
    vector<Employee*> employees {p1, p2 , p3};
    cout << s.getImportance(employees, 1) << endl;

    return 0;
}

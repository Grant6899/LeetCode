/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  8 22:40:26 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(dic.find(key) == dic.end())
			return -1;
		else{
			touch(key);
			return dic[key].first;
		}
		cout << "Freq size: " << freq.size() << endl;
    }
    
    void put(int key, int value) {
        
		if(dic.find(key) == dic.end()){
			if(_capacity == 0)
				if (!evictElement()) return;
			
			if(freq.front().first == 1){
				freq.front().second-> push_front(key);
				dic[key] = make_pair(value, make_pair(freq.begin(), freq.front().second -> begin()));
				_capacity--;
			}
			else{
				list<int>* newlist_p = new list<int>();
				newlist_p -> push_front(key);
				freq.push_front(make_pair(1, newlist_p));
				dic[key] = make_pair(value, make_pair(freq.begin(), freq.front().second -> begin()));
				_capacity--;
			}
		}
		else{
			dic[key].first = value;
			touch(key);
		}
		cout << "Freq size: " << freq.size() << endl;
    }
	
private:

    typedef list<pair<int, list<int>*>> FREQ;
    
    
	//[key, [val, [feq::iterator, list::iterator]]]
	unordered_map<int, pair<int, pair<FREQ::iterator, list<int>::iterator>>> dic;
	
	// [freq, list*]
	FREQ freq;
	int _capacity;

	void touch(int key){
		auto freq_it = dic[key].second.first;
		auto ele_it = dic[key].second.second;
		int new_freq = freq_it->first + 1;
		auto new_freq_it = next(freq_it);
		
		if(new_freq_it == freq.end() || new_freq_it -> first != new_freq){
			list<int>* temp = new list<int>;
			new_freq_it = freq.insert(new_freq_it, make_pair(new_freq, temp));
		}

		new_freq_it->second->push_front(key);
		freq_it->second->erase(ele_it);
		dic[key].second.first = new_freq_it;
		dic[key].second.second = new_freq_it->second->begin();
		
		if(freq_it->second->empty())
			freq.erase(freq_it);
		
	}
	
	bool evictElement(){
		if(freq.empty() || freq.front().second->empty())
			return false;
		dic.erase(freq.front().second-> back());
		freq.front().second-> pop_back();
		if(freq.front().second->empty())
			freq.pop_front();
		_capacity++;
		return true;
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(){
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> result;
		unordered_map<int, int> hash;
		int maxcount = -1;
		findsubtreesum(root, hash, maxcount);
		for (auto element : hash) {
			if (element.second == maxcount)
				result.push_back(element.first);
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	int findsubtreesum(TreeNode* root, unordered_map<int,int>& hash, int& maxcount) {
		if (!root)
			return 0;

		int leftsub = findsubtreesum(root->left, hash, maxcount);
		int rightsub = findsubtreesum(root->right, hash, maxcount);
		
		int sum = leftsub + rightsub + root->val;

		if (hash.find(sum) != hash.end()) {
			hash[sum]++;
			if (hash[sum] > maxcount)
				maxcount = hash[sum];
		}
		else {
			hash.insert({ sum, 1 });
			if (hash[sum] > maxcount)
				maxcount = hash[sum];
		}

		return sum;
	}
};

TreeNode* createTree(const vector<int>& src, int i) {
	if (src[i] == -1)
		return NULL;

	TreeNode* current = new TreeNode(src[i]);
	if (i * 2 + 1 < src.size())
		current->left = createTree(src, i * 2 + 1);
	else
		current->left = NULL;

	if (i * 2 + 2 < src.size())
		current->right = createTree(src, i * 2 + 2);
	else
		current->right = NULL;
	return current;
}


int main() {
	Solution s;



	vector<int> src{ 5,2,-3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.findFrequentTreeSum(root);

	return 0;
}
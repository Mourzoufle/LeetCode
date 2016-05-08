class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;						// the resulting groups of anagrams
		unordered_map<string, int> str2idx;				// mapping each group of anagrams to its index in the array
		sort(strs.begin(), strs.end());					// sort the strings to make the anagrams follow the lexicographic order in each group
		for (int i = 0; i < strs.size(); i++) {
			string str = strs[i];
			sort(str.begin(), str.end());				// anagrams become the same after sorting their characters
			if (str2idx.find(str) == str2idx.end()) {	// a new anagram
				res.resize(res.size() + 1);
				res.back().push_back(strs[i]);
				str2idx[str] = res.size() - 1;
			}
			else										// an existing anagram
				res[str2idx[str]].push_back(strs[i]);
		}
		return res;
	}
};
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> indices;																		// the resulting starting indices of substrings
		if (s.empty() || words.empty())
			return indices;
		int length_word = words[0].size();
		int tail_str = s.size() - words.size() * length_word;										// the last index that needs to be checked
		if (tail_str < 0)																			// s is not long enough - no indices found
			return indices;

		unordered_map<string, int> word2idx;														// map each unique word to its index
		int *counts_word = new int[words.size()];													// count of each unique word
		for (int i = 0; i < words.size(); i++) {
			if (word2idx.find(words[i]) == word2idx.end()) {										// the word is seen for the first time
				word2idx[words[i]] = i;
				counts_word[i] = 1;
			}
			else																					// ...or the word already exists - increase its count
				counts_word[word2idx[words[i]]]++;
		}
		int *indices_word = new int[s.size() - length_word + 1];									// index of the word starting by each character in s - -1 if it is not a word in the list
		for (int i = s.size() - length_word; i >= 0; i--) {
			string word = s.substr(i, length_word);
			indices_word[i] = (word2idx.find(word) == word2idx.end() ? -1 : word2idx[word]);
		}

		int *counts_word_in_str = new int[words.size()];											// count of each word in the current substring that is under checking
		for (int i = 0; i <= tail_str; i++) {
			for (int j = 0; j < words.size(); j++)
				counts_word_in_str[j] = 0;
			bool is_substr = true;
			for (int j = 0; j < words.size(); j++) {
				int idx_word = indices_word[i + j * length_word];
				if ((idx_word < 0) || (++counts_word_in_str[idx_word] > counts_word[idx_word])) {	// current word is not in the list, or it is repeated too many times - this substring is invalid
					is_substr = false;
					break;
				}
			}
			if (is_substr)
				indices.push_back(i);
		}
		return indices;
	}
};
class Trie {
public:
	class TrieNode {
		bool isWord;
		TrieNode *children[26];
	
		TrieNode () {
			this->isWord = false;
			for (int i = 0; i < 26; i++) {

				this->children[i] = NULL;
			}
		}
	}

	void addWord(string word) {

	}	
	
	
	bool hasWord(string word) {
	
	}
	
	// remove word from Trie data structure
	void removeWord(string word) {

	}
	
	// return all of strings having prefix
	vector<string> enumerateWords(string prefix) {


	}

}

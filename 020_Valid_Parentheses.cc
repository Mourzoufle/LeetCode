class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;									// stack of existing left brackets
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '(':										// found a left bracket - push it into the stack
			case '[':
			case '{':
				stack.push(s[i]);
				break;
			case ')':
				if (stack.empty() || (stack.top() != '('))	// cannot match with '(' - invalid
					return false;
				stack.pop();								// or pop the matched '('
				break;
			case ']':
				if (stack.empty() || (stack.top() != '['))	// cannot match with '[' - invalid
					return false;
				stack.pop();								// or pop the matched '['
				break;
			case '}':
				if (stack.empty() || (stack.top() != '{'))	// cannot match with '{' - invalid
					return false;
				stack.pop();								// or pop the matched '{'
			}
		}
		return stack.empty();								// if there are still left brackets in the stack - invalid
	}
};
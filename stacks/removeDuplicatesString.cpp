string removeDuplicates(string toCleanUp) {
    
    stack<char> chStack;
    chStack.push(toCleanUp[0]);

    for (int i = 1; i < toCleanUp.length(); i++) {
        char currentChar = toCleanUp[i];

        if (!chStack.empty() && currentChar == chStack.top()) {
            chStack.pop();
        }
        else {
            chStack.push(currentChar);
        }
    }
    string result;
    while(!chStack.empty()) {
        char ch = chStack.top();
        chStack.pop();
        
        result.insert(result.begin(), 1, ch);

    }
    return result;
}
int countBracketReversals(char input[]){
	// Write your code here
    Stack<char> brac;
    int i = 0;
    while(input[i] != '\0') {
        if(input[i] == '}' && !brac.isEmpty()) {
            if(brac.top() == '{')
                brac.pop();
            else
                brac.push(input[i]);
        }
        else
            brac.push(input[i]);
        i++;
    }
    if(i % 2) {
        return -1;
    }
    int reduced = brac.size();
    int openingBracCount = 0;
    while(!brac.isEmpty() && brac.top() == '{') {
        brac.pop();
        openingBracCount++;
    }
    
    return (reduced/2 + openingBracCount%2);
}

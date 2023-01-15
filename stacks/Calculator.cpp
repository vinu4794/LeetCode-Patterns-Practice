int Calculator(string expression) {

    int number = 0;
    int sign = 1;
    int result = 0;

    stack<int> calculatorStack;
    
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (isdigit(ch)) {
            number = number * 10 + int(ch) - 48;
        }
        else if (ch == '(') {
            calculatorStack.push(result);
            calculatorStack.push(sign);
            result = 0;
            sign = 1;
        }
        else if (ch == '-' || ch == '+') {
            result += number * sign;
            if (ch == '-') {
                sign = -1;
            } else {
                sign = 1;
            }
            number = 0;
        }
        else if (ch == ')') {
            result += sign * number;
            int popSignValue = calculatorStack.top();
            calculatorStack.pop();
            
            int temp = result;
            result *= popSignValue;
            
            int secondVal = calculatorStack.top();
            calculatorStack.pop();
            result += secondVal;
            number = 0;
        }
    }
    return result + number * sign;
}
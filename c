function infixToPostfix(exp) {
  const precedence = {
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
  };

  const isOperator = (ch) => ['+', '-', '*', '/'].includes(ch);
  const isParenthesis = (ch) => ['(', ')'].includes(ch);
  const isOpeningParenthesis = (ch) => ch === '(';
  const isClosingParenthesis = (ch) => ch === ')';
  
  let s = []; // Stack for operators and parentheses
  let res = ''; // Result (postfix expression)
  
  for (let i = 0; i < exp.length; i++) {
    const char = exp[i];

    if (/\d/.test(char)) {
      res += char; // If it's a number, add it to the result
    } else if (isOperator(char)) {
      while (s.length > 0 && !isOpeningParenthesis(s[s.length - 1]) && precedence[s[s.length - 1]] >= precedence[char]) {
        res += s.pop(); // Pop operators of higher precedence
      }
      s.push(char); // Push current operator onto stack
    } else if (isOpeningParenthesis(char)) {
      s.push(char); // Push opening parenthesis onto stack
    } else if (isClosingParenthesis(char)) {
      while (s.length > 0 && !isOpeningParenthesis(s[s.length - 1])) {
        res += s.pop(); // Pop operators until matching opening parenthesis
      }
      s.pop(); // Pop the opening parenthesis
    }
  }

  while (s.length > 0) {
    res += s.pop(); // Pop any remaining operators
  }

  return res;
}

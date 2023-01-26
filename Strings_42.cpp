// class Solution {
// public:
//     bool isValid(string s) {     // string and stack mixed implementation
//         stack<int> st;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='(' || s[i]=='{' || s[i]=='[')
//                 st.push(s[i]);
//             else{
//                 if(st.empty())
//                     return false;
//                 char c = st.top();
//                 st.pop();
//                 if((s[i]==')' && c=='(') || (s[i]=='}' && c=='{') || (s[i]==']' && c=='['))
//                     return true;
//                 else return false;
//             }

//         }
//         if(st.empty()){
//             return false;
//         }
//         return false;
//     }
// };

// // T.C = O(N)       S.C = O(N)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;   // taking stack for keep tracking the order of the brackets..
        for (auto it : s) // iterate over each and every elements
        {
            if (it == '(' or it == '{' or it == '[')
                st.push(it); // if current element of the string will be opening bracket then we will just simply push it into the stack
            else             // if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if (st.empty() or (st.top() == '(' and it != ')') or (st.top() == '{' and it != '}') or (st.top() == '[' and it != ']'))
                    return false;
                st.pop(); // if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty(); // at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
};
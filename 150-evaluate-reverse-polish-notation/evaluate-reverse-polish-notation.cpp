#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string c : tokens){
            if(c=="+"||c=="-"||c=="/"||c=="*"){
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                switch (c[0]){
                    case '+':
                        s.push(t1+t2);
                        break;
                    case '-':
                        s.push(t2-t1);
                        break;
                    case '*':
                        s.push(t1*t2);
                        break;
                    case '/':
                        s.push(t2/t1);  
                        break;          
                }   
            }else{
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
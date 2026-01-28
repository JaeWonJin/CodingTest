// https://school.programmers.co.kr/learn/courses/30/lessons/12909
#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> Stack;
    for (char c : s)
    {
        if (Stack.empty()) Stack.push(c);
        else
        {
            if (Stack.top() == '(' && c == ')')
            {
                Stack.pop();
            }
            else
            {
                Stack.push(c);
            }

        }
    }

    return Stack.empty();
}
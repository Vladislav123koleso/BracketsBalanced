#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool BracketsBalanced(string expr) {
    stack<char> bracketsStack;

    for (char& c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            bracketsStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (bracketsStack.empty()) {
                return false; // �� ���� ����������� ������
            }
            char top = bracketsStack.top();
            bracketsStack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; // ������ �� ������������� ���� �����
            }
        }
    }

    return bracketsStack.empty(); // ���� ���� ����, ������ ��������������
}

int main() {
    string expr1 = "[()]{}{[()()]()}";
    string expr2 = "[(])";

    cout << "1: " << (BracketsBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << "2: " << (BracketsBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
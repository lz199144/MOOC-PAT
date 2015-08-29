#include <iostream.h>
#include <list>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;

class node {
    public:
        double val;
        char op;
        bool is_op;
};
void parse(list<node*>&);
bool calc(list<node*> &tokens, double &result);
double calcx(double a, double b, char op);
void clear(list<node*> &tokens);
int main() {
    list<node*> tokens;
    parse(tokens);
    double res = 0.0;
    if (calc(tokens,res)) {
        printf("%.1f\n", res);
    } else {
        cout<<"ERROR"<<endl;
    }
    clear(tokens);
    //system("pause");
}

void clear(list<node*> &tokens) {
    list<node*>::iterator iter = tokens.begin();
    for(; iter != tokens.end(); iter++) {
        delete *iter;
    }
    tokens.clear();
}

double calcx(double a, double b, char op) {
    switch(op) {
        case '+':return a+b;break;
        case '-':return a-b;break;
        case '*':return a*b;break;
        case '/':return a/b;break;
        default:return 0;
    }
}

bool calc(list<node*> &tokens, double &result) {
    stack<double> nums;
    list<node*>::iterator iter = tokens.begin();
    for (; iter != tokens.end(); iter++) {
        node* n = *iter;
        if (n->is_op) {
            if (nums.size() < 2) {
                return false;
            } else {
                double a = nums.top();
                nums.pop();
                double b = nums.top();
                nums.pop();
                if (n->op == '/' && b == 0) return false;
                nums.push(calcx(a, b, n->op));
            }
        } else {
            nums.push(n->val);
        }
    }
    if (nums.size() != 1) {
        return false;
    } else {
        result = nums.top();
        return true;
    }
}
bool is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
void parse(list<node*> &tokens) {
    char buf[30];
    stringstream stream;
    double value = 0;
    while(cin>>buf) {
        node* n = new node();
        if (buf[1] == 0 && is_op(buf[0])) { //  operator
            n->is_op = true;
            n->op = buf[0];
        } else { // number
            stream.clear();
            stream<<buf;
            stream>>value;
            n->val = value;
            n->is_op = false;
        }
        tokens.push_front(n);
    }
}

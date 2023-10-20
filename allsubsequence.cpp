#include <bits/stdc++.h>
using namespace std;

void solve(string in, string op)
{
    if (in == "")
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += in[0];
    in.erase(in.begin() + 0);
    solve(in, op1);
    solve(in, op2);
    return;
}
int main()
{
    string in;
    cin >> in;
    string op = "";
    solve(in, op);
}
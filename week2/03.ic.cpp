#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    int n, i, num;
    char opr[4];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> opr;
        if (strcmp(opr, "li") == 0){
            cin >> num;
            l.push_front(num);
        }
        else if (strcmp(opr, "ri") == 0){
            cin >> num;
            l.push_back(num);
        }
        else if (strcmp(opr, "lr") == 0){
            l.push_back(l.front());
            l.pop_front();
        }
        else if (strcmp(opr, "rr") == 0){
            l.push_front(l.back());
            l.pop_back();
        }
    }
    for (auto i = l.begin(); i != l.end(); i++)
    {
        cout << *i << endl;
    }
}
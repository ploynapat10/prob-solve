#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l1;
    list<int> l2;
    int n, m, i, num, success = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        l1.push_back(num);
    }
    l1.sort();

    for (i = 0; i < m; i++)
    {
        cin >> num;
        l2.push_back(num);
    }

    while (1)
    {   
        for (auto j = l1.begin(); j != l1.end(); j++)
        {
            for(auto j = l2.begin(); j != l2.end(); j++){
                if (l2.front() <= *j)
            {
                cout << l2.front() << *j;
                l1.erase(j);
                l2.pop_front();
                success++;
                cout << "count" << success << endl;
                cout << "size" << l1.size() << endl;
                cout << "size" << l2.size() << endl;
                break;
            }
            }
        }
        break;
    }
    cout << success;
}
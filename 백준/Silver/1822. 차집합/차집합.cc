#include <iostream>
#include <set>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    int a, b; cin >> a >> b;
    set<int> s;
    set<int>::iterator iter;

    for (int i = 0; i < a; i++) {
        int temp; cin >> temp;
        s.insert(temp);
    }
    for (int i = 0; i < b; i++) {
        int temp; cin >> temp;
        if (s.find(temp) != s.end()) s.erase(temp);
    }
    cout << s.size() << '\n';
    for (iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << " ";
   
    return 0;
}
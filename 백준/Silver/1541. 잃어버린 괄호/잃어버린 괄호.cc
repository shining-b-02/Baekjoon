// 잃어버린 괄호 - 실버2
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int ans = 0;
    bool flag = false;
    int temp;
    string s, s2 = "";
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            s2 += s[i];
        }
        if(i == s.length() - 1 || !isdigit(s[i])){

            temp = stoi(s2);
            s2 = "";

            if(flag == false){
                ans += temp;
            }
            else if(flag == true){
                ans -= temp;
            }

            if(s[i] == '-'){
                flag = true;
            }
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int cnt_11[100005], cnt_10[100005], cnt_21[100005], cnt_20[100005];
int line_1[100005], line_2[100005];
int anss;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s1, s2, t1, t2;
        cin >> s1 >> s2 >> t1 >> t2;
        anss = 0;
        cnt_11[0] = (s1[0] == '1');
        cnt_10[0] = (s1[0] == '0');
        cnt_21[0] = (s2[0] == '1');
        cnt_20[0] = (s2[0] == '0');
        line_1[0] = line_2[0] = 0;
        for (int i = 1; i < n;i++){
            line_1[i] = ((t1[i - 1] == '1' && t1[i] == '1') ? (line_1[i - 1]) : (i));
            line_2[i] = ((t2[i - 1] == '1' && t2[i] == '1') ? (line_2[i - 1]) : (i));
            cnt_11[line_1[i]] += (s1[i] == '1');
            cnt_10[line_1[i]] += (s1[i] == '0');
            cnt_21[line_2[i]] += (s2[i] == '1');
            cnt_20[line_2[i]] += (s2[i] == '0');
        }
        for (int i = 0; i < n;i++){
            if(cnt_11[line_1[i]] && cnt_21[line_2[i]]){
                anss++;
                cnt_11[line_1[i]]--, cnt_21[line_2[i]]--;
            }else if(cnt_10[line_1[i]] && cnt_20[line_2[i]]){
                anss++;
                cnt_10[line_1[i]]--, cnt_20[line_2[i]]--;
            }else if(cnt_11[line_1[i]]){
                cnt_11[line_1[i]]--, cnt_20[line_2[i]]--;
            }else{
                cnt_10[line_1[i]]--, cnt_21[line_2[i]]--;
            }
        }
        cout << anss << '\n';
    }
}
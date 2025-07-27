#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, int> sr;

int main(){
    int n, po, score;
    string name;
    cin >> n;
    while(n--){
        cin >> po;
        if(po==1){
            cin >> name>>score;
            sr[name] = score;
            cout << "OK\n";
        }else if(po==2){
            cin >> name;
            if(sr.find(name)!=sr.end()){
                cout << sr[name] << endl;
            }else{
                cout << "Not found\n";
            }
        }else if(po==3){
            cin >> name;
            if(sr.find(name)!=sr.end()){
                sr.erase(sr.find(name));
                cout<<"Deleted successfully"<<endl;
            }else{
                cout<<"Not found\n";
            }
        }else{
            cout<<sr.size()<<endl;
        }
    }
    return 0;
}
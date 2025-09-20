#include <iostream>
#include <string>
using namespace std;

bool y_n(string y, string n, string word) {
    if (word == y) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    string name[n], a, mjjname;
    int qm[n], class_[n], lunwen[n], jj[n] = { 0 }, mjj = 0, njj = 0;
    bool ganbu[n], xibu[n];
    for (int i = 0; i < n;i++) {
        cin >> name[i] >> qm[i] >> class_[i];
        cin >> a;
        ganbu[i] = y_n("Y", "N", a);
        cin >> a;
        xibu[i] = y_n("Y", "N", a);
        cin >> lunwen[i];
        if (qm[i] > 80 && lunwen[i] > 0) {
            jj[i] += 8000;
        }
        if (qm[i] > 85 && class_[i] > 80) {
            jj[i] += 4000;
        }
        if (qm[i] > 90) {
            jj[i] += 2000;
        }
        if (qm[i] > 85 && xibu[i] == true) {
            jj[i] += 1000;
        }
        if (class_[i] > 80 && ganbu[i] == true) {
            jj[i] += 850;
        }
        njj += jj[i];
        mjjname = jj[i] > mjj ? name[i] : mjjname;
        mjj = jj[i] > mjj ? jj[i] : mjj;
    }
    cout << mjjname << endl
        << mjj << endl
        << njj;
    return 0;
}
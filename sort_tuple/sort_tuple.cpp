#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    vector<tuple<int, int, int>> vt;
    vt.push_back(make_tuple(1, 2, 35));
    vt.push_back(make_tuple(20,15, 30));
    vt.push_back(make_tuple(30,11, 10));
    sort(vt.begin(), vt.end());
    for (int i=0; i < vt.size(); ++i)
        cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i]) << endl;
    sort(vt.begin(), vt.end(), [](auto& t1, auto& t2){ return get<1>(t1) < get<1>(t2); });
    for (int i=0; i < vt.size(); ++i)
        cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i]) << endl;
    sort(vt.begin(), vt.end(), [](auto& t1, auto& t2){ return get<2>(t1) < get<2>(t2); });
    for (int i=0; i < vt.size(); ++i)
        cout << get<0>(vt[i]) << " " << get<1>(vt[i]) << " " << get<2>(vt[i]) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int BIT[200001];

struct queries {
    char type;
    int value;
} q[200000];

void update(int index, int value, int size) {
    for( ; index <= size; index += index&(-index)) {
        BIT[index] += value;
    }
}

int get(int index) {
    int sum = 0;
    for( ; index > 0; index -= index&(-index)) {
        sum += BIT[index];
    }
    return sum;
}

int main() {
    map<int, int> input_data;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> q[i].type >> q[i].value;
        if(q[i].type == 'I') {
            input_data[q[i].value]++;
        }
    }

    // make map of previously provided insertions
    // to get unique elements
    //int j = 0;
    // while(q[j].type == 'I') {
    //     input_data[q[j].value]++;
    //     j++;
    // }

    // get unique insertions.
    vector<int> unique_elements;
    map<int, int>::iterator it = input_data.begin();
    for( ; it != input_data.end(); it++) {
        unique_elements.push_back(it -> first);
    }

    // sort the unique elements
    sort(unique_elements.begin(), unique_elements.end());

    // make indexes corresponding to each unique elements.
    map<int, int> index;
    for(int i = 0; i != unique_elements.size(); i++) {
        index[unique_elements[i]] = i+1;
    }
    
    // it = index.begin();
    // for( ; it != index.end(); it++) {
    //     cout << it -> first << " " << it-> second << "\n";
    // }

    int n = unique_elements.size();
    vector<int>::iterator vecIter;
    int mid, start, end, ans, temp;

    for(int i = 0; i < Q; i++) {
        switch(q[i].type) {
            case 'I':   if(get(index[q[i].value]) == get(index[q[i].value] - 1)) {
                            update(index[q[i].value], 1, n);
                        }
                        break;

            case 'D':   if(get(index[q[i].value]) != get(index[q[i].value] - 1)) {
                            update(index[q[i].value], -1, n);
                        }
                        break;

            case 'C':   vecIter = lower_bound(unique_elements.begin(), unique_elements.end(), q[i].value);
                        vecIter--;
                        if(*vecIter == q[i].value) {
                            cout << get(index[*vecIter]-1) << "\n";
                        } else {
                            cout << get(index[*vecIter]) << "\n";
                        }
                        break;

            case 'K':   if(get(n) < q[i].value) {
                            cout << "invalid\n";
                        }
                        else {
                            start = 1;
                            end = n;
                            while(start <= end) {
                                mid = (start + end) / 2;
                                temp = get(mid);
                                if(temp < q[i].value) {
                                    start = mid+1;
                                } else {
                                    if(temp == q[i].value) {
                                        ans = mid;
                                    }
                                    end = mid - 1;
                                }
                            }
                            cout << unique_elements[ans - 1] << "\n";
                        }
                        break;
        }
    }

    return 0;
}
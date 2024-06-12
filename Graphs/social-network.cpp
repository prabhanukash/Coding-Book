#include <bits/stdc++.h>
using namespace std;

class SocialNetworkConnectivity {
private:
    int nonConnected;
    vector<int> network;
    vector<int> sz;

    void validate(int p) {
        if (p < 0 || p >= network.size()) {
            throw invalid_argument("input index " + to_string(p) + " is not between 0 and " + to_string(network.size() - 1));
        }
    }

    int root(int i) {
        validate(i);
        while (i != network[i]) {
            network[i] = network[network[i]];  // path compression
            i = network[i];
        }
        return i;
    }

public:
    SocialNetworkConnectivity(int n) {
        if (n <= 0) 
            throw invalid_argument("the number of friends in the network should be greater than 0");
        nonConnected = n;
        network.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            network[i] = i;
        }
    }

    bool isAllConnected() {
        return nonConnected == 1;
    }

    bool isConnected(int i, int j) {
        validate(i);
        validate(j);
        return root(i) == root(j);
    }

    void formFriendship(int i, int j) {
        validate(i);
        validate(j);
        int rootI = root(i);
        int rootJ = root(j);
        if (rootI == rootJ) return;
        if (sz[rootI] < sz[rootJ]) {
            network[rootI] = rootJ;
            sz[rootJ] += sz[rootI];
        } else {
            network[rootJ] = rootI;
            sz[rootI] += sz[rootJ];
        }
        nonConnected--;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    int n;
    file >> n;
    SocialNetworkConnectivity snc(n);
    int timestamp, i, j;
    auto start = chrono::high_resolution_clock::now();
    int line = 0;

    while (file >> timestamp >> i >> j) {
        line++;
        snc.formFriendship(i, j);
        if (snc.isAllConnected()) {
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            cout << "file: " << argv[1]
                      << "\ntimestamp: " << timestamp
                      << "\nline: " << line
                      << "\n(elapsed time: " << elapsed.count() << "s)" << endl;
            break;
        }
    }

    file.close();
    return 0;
}

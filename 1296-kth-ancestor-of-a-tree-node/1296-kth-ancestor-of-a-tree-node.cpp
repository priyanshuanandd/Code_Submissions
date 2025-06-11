class TreeAncestor {
public:
    vector<vector<int>> sparsetable;
    vector<int> d;
    TreeAncestor(int n, vector<int>& parent) {
        sparsetable.assign(n, vector<int>(30, -1));
        d = vector<int>(n);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            sparsetable[i][0] = parent[i];
        }

        for(auto i : d){
            cout << i << " ";
        }
        cout << "\n";
        for (int j = 1; j < 30; j++) {
            for (int i = 0; i < n; i++) {
                if(sparsetable[i][j-1] == -1)
                {
                    sparsetable[i][j]  = -1; 
                    continue;   
                }
                sparsetable[i][j] = sparsetable[sparsetable[i][j - 1]][j - 1];
                
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int i = 0; i < 32; i++) {
            if (k & (1 << i)) {
                node = sparsetable[node][i];
                if(node == -1)
                {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
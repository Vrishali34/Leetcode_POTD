class Solution {
public:
    int leafCount;
    vector<char> edgeLeft, edgeRight;
    vector<int> prefLen, sufLen, bestLen;

    void buildTree(int node, int lo, int hi, string &s) {
        if (lo == hi) { edgeLeft[node]=edgeRight[node]=s[lo]; prefLen[node]=sufLen[node]=bestLen[node]=1; return; }
        int mid = (lo+hi)/2;
        buildTree(2*node, lo, mid, s); buildTree(2*node+1, mid+1, hi, s);
        pullUp(node, lo, mid, hi);
    }

    void pullUp(int node, int lo, int mid, int hi) {
        int L=2*node, R=2*node+1;
        edgeLeft[node]=edgeLeft[L]; edgeRight[node]=edgeRight[R];
        prefLen[node]=prefLen[L];
        if (prefLen[L]==mid-lo+1 && edgeRight[L]==edgeLeft[R]) prefLen[node]+=prefLen[R];
        sufLen[node]=sufLen[R];
        if (sufLen[R]==hi-mid && edgeLeft[R]==edgeRight[L]) sufLen[node]+=sufLen[L];
        bestLen[node]=max(bestLen[L],bestLen[R]);
        if (edgeRight[L]==edgeLeft[R]) bestLen[node]=max(bestLen[node], sufLen[L]+prefLen[R]);
    }

    void pointUpdate(int node, int lo, int hi, int pos, char ch) {
        if (lo == hi) { edgeLeft[node]=edgeRight[node]=ch; return; }
        int mid = (lo+hi)/2;
        if (pos <= mid) pointUpdate(2*node, lo, mid, pos, ch);
        else pointUpdate(2*node+1, mid+1, hi, pos, ch);
        pullUp(node, lo, mid, hi);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        leafCount = s.size();
        int sz = 4*leafCount;
        edgeLeft.resize(sz); edgeRight.resize(sz); prefLen.resize(sz); sufLen.resize(sz); bestLen.resize(sz);
        buildTree(1, 0, leafCount-1, s);
        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            pointUpdate(1, 0, leafCount-1, queryIndices[i], queryCharacters[i]);
            ans[i] = bestLen[1];
        }
        return ans;
    }
};

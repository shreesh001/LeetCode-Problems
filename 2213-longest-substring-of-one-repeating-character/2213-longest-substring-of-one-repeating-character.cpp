class Solution {
public:
    struct Node{
        int maxlen=0;
        int leftlen=0;
        int rightlen=0;
        char leftch=0;
        char rightch=0;
    };

    vector<Node>segtree;
    Node merge(Node& leftNode, Node& rightNode,int llen,int rlen){
        Node root;
        root.leftch=leftNode.leftch;
        root.rightch=rightNode.rightch;

        root.leftlen=leftNode.leftlen;
        if (leftNode.leftlen==llen && leftNode.rightch==rightNode.leftch){
            root.leftlen+=rightNode.leftlen;
        }

        root.rightlen=rightNode.rightlen;
        if (rightNode.rightlen==rlen && rightNode.leftch==leftNode.rightch){
            root.rightlen+=leftNode.rightlen;
        }

        root.maxlen=max(leftNode.maxlen,rightNode.maxlen);
        if (leftNode.rightch==rightNode.leftch){
            root.maxlen=max(root.maxlen,leftNode.rightlen+rightNode.leftlen);
        }
        return root;
    }
    void buildsegtree(int ind,int l,int r,string &s){
        if (l==r){
            segtree[ind]=Node{1,1,1,s[l],s[r]};
            return;
        }
        int mid=(l+r)/2;
        buildsegtree(2*ind+1,l,mid,s);
        buildsegtree(2*ind+2,mid+1,r,s);

        segtree[ind]=merge(segtree[2*ind+1],segtree[2*ind+2],mid-l+1,r-mid);
    }

    void update(int ind,int l,int r,int pos,char ch){
        if (l==r){
            segtree[ind]=Node{1,1,1,ch,ch};
            return;
        }

        int mid=(l+r)/2;
        if (pos<=mid){
            update(2*ind+1,l,mid,pos,ch);
        }
        else update(2*ind+2,mid+1,r,pos,ch);

        segtree[ind]=merge(segtree[2*ind+1],segtree[2*ind+2],mid-l+1,r-mid);

    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        segtree.resize(4*n);
        buildsegtree(0,0,n-1,s);

        vector<int>res;
        for (int i=0;i<queryIndices.size();i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];

            update(0,0,n-1,pos,ch);

            res.push_back(segtree[0].maxlen);
        }

        return res;
    }
};
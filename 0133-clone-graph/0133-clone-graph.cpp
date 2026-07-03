/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* clone_node, Node* node, map<Node*,Node*>&mpp){

        for (Node*adjnode:node->neighbors){

            if (mpp.find(adjnode)==mpp.end()){
                Node* clone=new Node(adjnode->val);
                mpp[adjnode]=clone;
                clone_node->neighbors.push_back(mpp[adjnode]);
                dfs(clone,adjnode,mpp);
            }
            else{
                clone_node->neighbors.push_back(mpp[adjnode]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node==nullptr) return nullptr;

        map<Node*,Node*>mpp;
        Node* clone_node=new Node(node->val);
        mpp[node]=clone_node;

        // dfs(clone_node,node,mpp);
        // return clone_node;

        // solve using bfs

        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* ori_node=q.front();
            Node* clone_node=mpp[ori_node];
            q.pop();
            for (Node* adjnode: ori_node->neighbors){

                if (mpp.find(adjnode)==mpp.end()){
                    Node* clone = new Node(adjnode->val);
                    mpp[adjnode]=clone;
                    clone_node->neighbors.push_back(clone);
                    q.push(adjnode);
                }
                else{
                    clone_node->neighbors.push_back(mpp[adjnode]);
                }
            }
        }

        return clone_node;
    }
};
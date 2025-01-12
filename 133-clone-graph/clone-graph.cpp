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
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(!node->neighbors.size()) return new Node(node->val);
        map<Node*, Node*> nodeMap;
        map<Node*, bool> vis;
        queue<Node*> q;
        q.push(node);
        clone(node, nodeMap, vis, q);
        return nodeMap[node];
    }

    void clone(Node* node, map<Node*, Node*> &nodeMap, map<Node*, bool> &vis, queue<Node*> &q){
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            if(!vis[n]){
                Node* newNode;
                if(!nodeMap[n]){
                    newNode = new Node(n->val);
                    nodeMap[n] = newNode;
                }else{
                    newNode = nodeMap[n];
                }
                for(Node* neighbor: n->neighbors){
                    if(!nodeMap[neighbor]){
                        Node* temp = new Node(neighbor->val);
                        nodeMap[neighbor] = temp;
                    }
                    newNode->neighbors.push_back(nodeMap[neighbor]);
                    q.push(neighbor);
                }
                vis[n] = true;
            }
        }
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> node_map;
    Node* getNode(Node* node) {
        Node* n = NULL;
        if (node_map.find(node) != node_map.end()) {
            n = node_map[node];
        } else {
            n = new Node(node->val);
            node_map[node] = n;
        }
        //cout << node_map[node] <<endl;
        return n;
    }
    Node* copyRandomList(Node* head) {
        Node* node = head;
        Node* prev = NULL;
        Node* new_head = NULL;
        Node* n = NULL;
        Node* rn = NULL;
        while (node) {
            //cout << node->val <<"@" << node->next << node->random << endl;
            n = getNode(node);
            if (prev) {
                prev->next = n;
            } else {
                new_head = n;
            }
            if (node->random) {
                rn = getNode(node->random);
            } else {
                rn = NULL;
            }
            n->random = rn;
            prev = n;
            node = node->next;
        }
        //cout << new_head;
        return new_head;
    }
};

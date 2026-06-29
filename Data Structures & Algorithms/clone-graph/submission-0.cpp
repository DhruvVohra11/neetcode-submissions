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
        // Base case: if the graph is empty
        if (!node) return nullptr;

        // Map to store the mapping from original node to its clone
        unordered_map<Node*, Node*> visited;

        // Clone the root node and place it in the map
        visited[node] = new Node(node->val);

        // Queue for BFS traversal
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate through all the neighbors of the current node
            for (Node* neighbor : curr->neighbors) {
                // If the neighbor hasn't been cloned yet
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor and store it in the map
                    visited[neighbor] = new Node(neighbor->val);
                    // Push the original neighbor to the queue to visit its neighbors later
                    q.push(neighbor);
                }
                // Add the cloned neighbor to the cloned current node's neighbors list
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        // Return the clone of the original starting node
        return visited[node];
    }
};
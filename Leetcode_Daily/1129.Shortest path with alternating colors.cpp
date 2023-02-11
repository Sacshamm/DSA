class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n+1];

        //storing red ones
        for(auto nodes:redEdges){
            adj[nodes[0]].push_back({nodes[1],1});//adjNodes and red=1
        }
        //storing blue ones
        for(auto nodes:blueEdges){
            adj[nodes[0]].push_back({nodes[1],2});//adjNodes and blue=2
        }

        vector<int>dist(n,-1);

        queue<vector<int>>q;
        q.push({0,0,-1});//neighbourNode,distance,edgeColor

        while(!q.empty()){
            auto currNode = q.front();
            q.pop();

            int srcNode = currNode[0];
            int edgeColor = currNode[2];

            //if not visited earlier then update distance
            if(dist[srcNode]==-1) {
                dist[srcNode] = currNode[1];
            }

            //traversing for neighbouring nodes
            for(auto &adjNode : adj[srcNode]){
                    int childNode = adjNode.first;
                    int childColor = adjNode.second;

                    //if not yet visited && (for {0,0,-1} vala case || color should not be same)
                    if(childNode != -1 && (edgeColor == -1 || edgeColor != childColor)){
                        //push childnodes , incrment distance and color
                        q.push({childNode, currNode[1]+1, childColor});
                        adjNode.first = -1;//mark that node visited
                    }
                }
            }
        return dist;
    }
};

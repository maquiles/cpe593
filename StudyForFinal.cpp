#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>

using namespace std;

//HASHING======================================================================================
//linear chaining
//*********************************************************************************************
class HashMap{
    private:
        class LinearChain {
            private:
                vector<string> chain;
                int chainSize;
            public:
                LinearChain() {chainSize = 0;}
                ~LinearChain(){}

                void incChainSize(){ chainSize++; }
                void addToChain(stirng str){ chain.push_back(str); }
                int getChainSize(){ return chainSize; }

                bool foundInChain(String str){
                    for (int i = 0; i < chainSize; i++){
                        if(str == chain[i]){
                            return true;
                        }
                    }
                    return false;
                }
        };

        LinearChain **map;
        unsigned long int mapSize;

    public:
        HashMap(unsigned long int s){
            mapSize = s;
            map = new LinearChain*[mapSize];
            for (unsigned long int i = 0; i < mapSize; i++){
                map[i] = new LinearChain();
            }
        }
        ~HashMap(){
            for (int i = 0; i < mapSizel i++){
                if(map[i] != nullptr)
                    delete map[i];
                delete[] map;
            }
        }

        int hash(string str){
            int sum = 0;
            for (unsigned int i = 0; i < str.size(); i++){
                sum += str[i];
            }
            int hash = sum % mapSize;
            return hash;
        }

        void put(string str){
            int h = hash(str);
            map[h]->addToChain(str);
            map[h]->incChainSize();
        }

        string get(string str){
            int h = hash(str);
            if(,ap[h]->foundInChain(str) == true){
                return str;
            }
            else{
                return "not found";
            }
        }

        bool found(string str){
            int h = hash(str);
            return map[h]->foundInChain(str);
        }

        void displayHistogram(){
            cout<< "\ninsert\tcount\n";
            for (undigned long int i = 0; i < mapSize; i++){
                cout<< "\t";
                cout<< map[i]->getChainSize()<< "\n";
            }
        }
};

//linear probing
//**********************************************************************************************
class HashMap2 {
private:
    class HashEntry {
    private:
        int key;
        int collisions;
    public:
        HashEntry(int k, int c) : key(k), collisions(c) {}
        int getCollisions() { return collisions; }
        int getKey() { return key; }
    };

    HashEntry ** table;
    int tableSize;
public:
    HashMap2(int ts) {
        tableSize = ts*2;
        table = new HashEntry*[tableSize];
        for (int i = 0; i < tableSize; i++){
            table[i] = nullptr;
        }
    }
    ~HashMap2(){
        for (int i = 0; i < tableSize; i++)
            if (table[i] != nullptr)
                delete table[i];
         delete[] table;
    }

    int get(int key){
        int hash = (key % tableSize);
        while (table[hash] != nullptr && table[hash]->getKey() ! = key)
            hash = (hash +1) % tableSize;
        if(table[hash] == nullptr)
            return -1;
        else
            return table[hash]->getKey();
    }

    void put(int key){
        int hash = (key % tableSize);
        int c = 1;
        while (table[hash] != nullptr && table[hash]->getKey() != key){
            hash = (hash +1) % tableSize;
            c++;
        }
        table[hash] = new HashEntry(key, c);
    }

    void displayHistogram(){
        int* histogram = new int[51];
        
        for (int i = 1; i < tableSize; i++){
            if(table[i] != nullptr){
                int x = table[i]->getCollisions();

                if( x > 50){
                    histogram[50]++;
                }
                else{
                    histogram[x]++;
                }
            }
            else{
                histogram[0]++;
            }
        }

        for (int j = 0; j < 51; j++){
            cout<< j<< "\t"<< histogram[j]<< "\n";
        }
        cout<< ">50\t"<< histogram[50]<< "\n";
        delete[] histogram;
    }
};

//perfect hashing
//**************************************************************************************************************
//not writing the code for this right now, but its when you make it so that everything is in its own bucket and search is O(1)
//mod numbers by table size and then in those buckets make another chain of the smallest size possible so that there are no collisions

/**
//TREES ================================================================================================================================
	Binary trees - la di da
                 10
               /   \
              8     12
             / \   /  \
            4   9 11   13

		inorder - 4 8 9 10 11 12 13
        preorder - 10 8 4 9 12 11 13 (top down)
        postorder - 4 9 8 11 13 12 10 (bottom up)

	Balanced Binary Trees	
		Def of RB Tree - type of self balancing tree where each node has an extra bit (red or black)
                        -define that the number of red nodes is always the same from top to bottom of tree
                        -never allow node to have same color child
                 g
               /   \
                    p
                   /  \
                  11   n
            root = p
            p.parent = null
            g.right = p.left
            p.left = g

        rotate_left - (technically ccw)
            void rotate_left(struct node *n){
                struct node *nnew = n->right;
                n->right = nnew->left;
                nnew->left = n;
                nnew->parent = n->parent;
                n->parent = nnew;
                // (the other related parent and child links would also have to be updated)
            }
        rotate_right - (technically clockwise)
            void rotate_right(struct node *n) {
                struct node *nnew = n->left;
                n->left = nnew->right;
                nnew->right = n;
                nnew->parent = n->parent;
                n->parent = nnew;
                // (the other related parent and child links would also have to be updated)
            }
		*/

//Trie
class Trie {
private:
    class Node {
    public:
        bool isWord;
        Node* next[26];
    };

    Node* root;

public:
    Trie() { initNode(root); }

    void initNode(Node*& n){
        n = new Node();
        n->isWord = false;
        for (int i = 0; i < 26; i++){
            n->next[i] = nullptr;
        }
    }

    Node* endOfString(string s, bool insert){
        Node* curr = root;
        Node* nxt = root;
        for (unsigned int i = 0; i < s.length(); i++){
            if(isalpha(s[i]) == true){
                int letter = (tolower(s[i]) - 'a');
                nxt = curr->next[letter];
                if(nxt == nullptr){
                    if(insert == false){
                        return nullptr;
                    }

                    initNode(nxt);
                    curr->next[letter] = nxt;
                }
                curr = curr->next[letter];
            }
        }
        return curr;
    }

//insert
    void insert(string s){
        Node* curr = endOfString(s, true);
        curr->isWord = true;
    }

//contains
    bool findWord(string s){
        Node* curr = endOfString(s, false);
        if(curr == nullptr){
            return false;
        }
        else{
            return curr->isWord;
        }
    }

//contains prefix
    bool findPrefix(string s){
        Node* curr = endOfString(s, false);
        if(curr == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
};

//GRAPHS===============================================================================================================
/**	Representation: 
 * bad edge list
 * **/
class BadEdgeListGraph {
private:
    class Edge{
        int from, to;
        double w;
    }
    List<Edge> edges;
public:
    bool isAdjacent(int i , int j){//O(V^2)
        if(i < j)
            return isAdjacent(j, i);
        return m[i][j];
    }
    bool[] adjacent(int i){//O(V^2)

    }
}

//matrix ********************************************************************************************************
class MatrixGraph {
private:
    double[] w;
    private int V;
public:
    bool isAdjacent(int i, int j){ //O(1)
        return w[i * V + j];
    }

    bool[] adjacent(int v){//O(V)

    }
}

/**
 * good edge  list (each vertex has a list of edges)********************************************************************************************************
 * **/
class EdgeListGraph {
private:
    class Edge{
        int to;
        double w;
    }
    LinkedList<Edge>[] v;
public:
    bool isAdjacent(int i, int j){//O(V)

    }
    bool[] adjacent(int i){//O(V)

    }
}

/**Depth First Search (DFS) ********************************************************************************************************
//recursive
g.DFS(v)
    visited <- [false, false, false, ...] //O(V)
    g.DFS2(visited, v)
end

g.DFS2(visited, v)
    visited[v] <- true
    for i = 0 ... v-1
        if isAdjacent(v, i) and not visited[v]
            g.DFS2(visited, i)
        end
    end
end

//using BadEdgeList
g.DFS(visited, v)
    visited[v] <- true
    a <- g.adjacencies(v) //O(E) == O(V^2)
    for i=0 ... v-1
        if a[i] and not visited[v]
            g.DFS2(visited, i)
        end
    end
end
*/
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

/*
//iterative
g.DFS(v)
  visited[*]← false  //O(V)
  stack.push(v)
  visited[v] ← true
  while (NOT stack.empty())
    v ← stack.pop()
    print v
    foreach n← neighbor(v)
      if NOT visited[n] 
        stack.push(n)
        visited[n] ← true
      end
    end
  end
end
*/
void Graph::DFS(int x, int required){
    stack s;
    bool *visited = new bool[n+1];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    if(x == required) return;
    while(!s.isEmpty()){
        int k = s.pop();
        if(k == required) break;
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
    }
    delete [] visited;
} 

/*
//Breadth First Search (BFS) (iterative)********************************************************************************************************
g.BFS(v)
  visited[*]← false
  queue.enqueue(v)
  visited[v] ← true
  while NOT queue.isEmpty() // O(V)
    v← queue.dequeue()
        foreach n← neighbor(v) // O(V) omega(1) if using edge list implementation
          if NOT visited[n]
            queue.enqueue(n)
            visited[n] ← true
         end
    end
  end
end
*/
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty()){
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

/*
//isConnected********************************************************************************************************
g.isConnected(v)
  visited[*]← false
  stack.push(v)
  visited[v] ← true
  count ← 1
  while (NOT stack.empty())
    v ← stack.pop()
    foreach n← neighbor(v)
      if NOT visited[n] 
        stack.push(n)
        visited[n] ← true
	    count++
      end
    end
  end
  return count == v
end

//using dfs
bool ← g.isConnected()	//O(V^2)
   visited← g.DFS(r)		//O(V^2)
   for i← 0 to V
      if NOT visited[i]
        return false
   end
   return true
end
*/
bool Graph::isConnected()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
             return false;

    //flip it and check DFS the opposite way
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++)
        visited[i] = false;
    gr.DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
             return false;
    return true;
}

/*
//Bellman-Ford	(no pseudocode) O(V^3) = O(EV)********************************************************************************************************
//algorithm that computes the shortest paths from a signel source vertex to all of the other vertices in a weighted digraph
-initialize all dinstances as infinite
- do v-1 iterations
- examine all edges on each iteration (look at each node)
- update table untill there are no changes and then you should have the shortest path to each node
- if prof kruger has us write out a table i think he is going to want to see it for each node cause that what the notes are
*/

//Floyd-Warshall (yes pseudocode)********************************************************************************************************
//initialize each nodes path to itself as 0
//add it weights for edges
//nested for loop for 
void floydWarshall (int graph[][V]){//O(V^3)
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // Print the shortest distance matrix
}

/*
//Prim********************************************************************************************************
Prim(v)
	visited ←new Vector(V, false)
	visited[v] ← true
	for i ← 1 to V-1
        for a ← // for all edges out of the visited set (V, 2V, 3V, …) 0 to V-1
                min ← ∞
                if isAdjacent(v, a) and NOT visited[a]
                    if getWeight(v,a) < min
                        min ← getWeight(v,a)
                        minA ← a
                    end
                end
        end
        visited[minA] ← true
        v ← minA
    end
end
*/
void primMST(int graph[V][V]){
    int parent[V]; //store constructed mst
    int key[V]; //key values used to pick minimum weight edge in cut
    bool mstSet[v]; //to represent set of vertices not yet included in mst

    //initialize all keys as infinite
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0]; //make 0 key so that this vertex is picket as first vertex
    parent[0] = -1; //first node is always root of MST

    //the mst will have V vertices
    for (int count = 0; count < V-1; count++){
        //pick minimum key vertex from the set of verticies not yet included in mst
        int u = minKey(key, mstSet);
        mstSet[u] = true; //add the picked vertex to the mst set

        for (int v = 0; v < V; v++){
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
        }
    }
    //print the constructed mst here
}

//Kruskal********************************************************************************************************
// Initialize result
mst_weight = 0

// Create V single item sets
for each vertex v
	parent[v] = v;
	rank[v] = 0;

Sort all edges into non decreasing 
order by weight w

for each (u, v) taken from the sorted list  E
    do if FIND-SET(u) != FIND-SET(v)
        print edge(u, v)
        mst_weight += weight of edge(u, v)
        UNION(u, v)
**/
int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result
 
    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());
 
    // Create disjoint sets
    DisjointSets ds(V);
 
    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
 
        int set_u = ds.find(u);
        int set_v = ds.find(v);
 
        // Check if the selected edge is creating a cycle or not (Cycle is created if u and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST so print it
            cout << u << " - " << v << endl;
 
            // Update MST weight
            mst_wt += it->first;
 
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
 
    return mst_wt;
}
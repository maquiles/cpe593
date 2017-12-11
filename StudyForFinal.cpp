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
        preorder - 10 8 4 9 12 11 13
        postorder - 4 9 8 11 13 12 10

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

    }
    bool[] adjacent(int i){//O(V^2)

    }
}

//matrix
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
 * good edge  list (each vertex has a list of edges)
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

/**Depth First Search (DFS)
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


//Breadth First Search (BFS) (iterative)
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

//isConnected
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

//Bellman-Ford	(no pseudocode)
need an explination of what this is

//Floyd-Warshall (yes pseudocode)


//Prim
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

//Kruskal
**/
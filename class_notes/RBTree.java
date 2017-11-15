public class RBTree{
    private static class Node {
        private int val;
        private Node left, right, parent;
        private enum Color{ RED, BLACK}

        public Node(int v, Node L, Node R){
            val = v;
            left = L;
            right = R;
        }
        
        Node grandparent() {
            if(parent == null){
                return null;
            }
            return parent.parent;
        }

        Node sibling() {
            if(parent == null){
                return null;
            }
            if(parent.left == this){
                return parent.right;
            }
            else{
                return parent.left;
            }
        }

        Node uncle() {
            Node g = grandparent();
            if(g == null){
                return null;
            }
            return parent.sibling();
        }
    }

    private Node root;
    public RBTree(){
        root = null;
    }

    public void repairTree(){
        if(n.parent == null){
            insert_case1(n);
        }
        else if(n.parent.color == Color.BLACK){

        }
        else if(n.uncle.color == Color.RED){
            insert_case3(n);
        }
        else{
            insert_case4(n);
        }
    }

    private void insert_case1(Node n){
        if(n.parent == null){
            n.color = Color.BLACK;
        }
    }

    private void insert_case3(Node n){
        n.parent.color = Color.BLACK;
        n.uncle.color = Color.BLACK;
        Node g = n.grandparent();
        g.color = Color.RED;
        repairTree(g);
    }

    private void insert_case4(Node n){
        Node p = n.parent;
        Node g = n.grandparent();

        if(n == g.left.right){
            rotate_left(p);
            n = n.left;
        }
        else if(n == g.right.left){
            rotate_right(p);
            n = n.right;
        }
        insert_case4step2(n);
    }

    private void insert_case4b(Node n){
        Node p = n.parent;
        Node g = n.grandparent();

        if(n == p.left)

        ///ugh im not typing this out anymore
    }

    //rotate left and right
    private void rotate_left(Node n){
        Node nnew = n.right;
        assert(nnew != null);
        n,right = nnew.left;
        nnew.left = n;
        nnew.parent = n.parent;
        n.parent = nnew;
    }

    private void rotate_right(Node n){
        Node nnew = n.left;
        assert(nnew != null);
        n,right = nnew.right;
        nnew.right = n;
        nnew.parent = n.parent;
        n.parent = nnew;
    }

    void add(int v){
        if(root == null){
            root = new Node(v, null, null);
            return;
        }

        Node p = root;
        while (true){
            if( p.val > v){
                if(p.left == null){
                    p.left = new Node(v, null, null);
                    repairTree(p.left);
                    return;
                }
                p = p.left;
            }
            else{
                if(p.right == null){
                    p.right = new Node(val, null, null);
                    repairTree(p.right);
                    return;
                }
                p = p.right;
            }
        }
    }

    public void inorder(){
        root.inorder();
    }
    public void preorder() {
        root.preorder();
    }
    public void postorder() {
        root.postorder();
    }
}
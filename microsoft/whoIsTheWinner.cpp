//SOL - 1 - Using LikedList
class Solution {

    class Node{

        public:
            int val;
            Node* next;

            Node(int x){
                this->val = x;
                next = NULL;
            }

    };

public:
    int findTheWinner(int n, int k) {
        
        int cnt = n;
        if(n == 1)
            return 1;
        if(k == 1)
            return n;

        Node* head = new Node(1);
        Node* it = head;
        Node* prev = NULL;
        for(int i = 2 ; i <= n ; i++){
            it->next = new Node(i);
            prev = it;
            it = it->next;
        }

        it->next = head;
        Node* curr = head;


        while(cnt != 1){

            for(int i = 1 ; i < k ; i++){
                prev = curr;
                curr = curr->next;
            }

            cnt--;
            curr = curr->next;
            prev->next = curr;

        }
        return curr->val;
        return -1;

    }
};

//SOL - 2 - Using Josephus Problem Solution
class Solution {

    int for0(int n , int k){

        if(n == 1)
            return 0;

        int ans = for0(n-1 , k);
        return (ans + k)%n;

    }

public:
    int findTheWinner(int n, int k) {
        return for0(n , k) + 1;
    }
};
class solution {
public:
    long long multiplyTwoLists (Node* l1, Node* l2) {
        //Do variables ko initialize karte hain
        long long a = 0;
        long long b = 0;
        Node* t1 = l1;
        Node* t2 = l2;
        
        // Jab tak dono linked lists khatam nahi ho jati, tab tak loop chalate hain
        while(t1 || t2){
            // Agar t1 null nahi hai, toh uska data 'a' mein add karte hain
            if(t1 != NULL){
                a = (a*10)%1000000007 + t1->data;
                t1 = t1->next;
            }
            // Agar t2 null nahi hai, toh uska data 'b' mein add karte hain
            if(t2 != NULL){
                b = (b*10)%1000000007 + t2->data;
                t2 = t2->next;
            }
        }
        
        // 'a' aur 'b' ko multiply karke return karte hain
        return (a*b)%1000000007;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        // Agar linked list mein sirf ek node hai toh usko return kar dete hain
        if(head->next==NULL)return head;
        
        vector<int> v;
        Node* a = head;
        
        // Linked list ke saare elements ko vector 'v' mein store kar lete hain
        while(a!=NULL)
        {
            v.push_back(a->data);
            a=a->next;
        }
        
        vector<int> st;
        
        // Har element ke liye, agar uske right mein koi bada element hai toh use skip kar dete hain
        for(int i=0;i<v.size();i++)
        {
            bool flag=false;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag=true;
                    break;
                }
            }
            // Agar right mein koi bada element nahi hai toh use 'st' vector mein daal dete hain
            if(!flag)
            {
                st.push_back(v[i]);
            }
        }
        
        // 'st' vector ke elements se nayi linked list banate hain
        Node* ans = new Node(st[0]);
        Node* b = ans;
        for(int i=1;i<st.size();i++)
        {
            b->next  = new Node(st[i]);
            b=b->next;
        }
        
        // Nayi linked list return kar dete hain
        return ans;
    }
};

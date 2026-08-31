/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> v;

        ListNode* temp=head;

        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }

        if(v.size()==2) return {-1,-1};
        vector<int> indices;

        for(int i=1;i<v.size()-1;i++){
            if(v[i]<v[i+1] && v[i]<v[i-1]) indices.push_back(i);
            else if(v[i]>v[i+1] && v[i]>v[i-1]) indices.push_back(i);
        }

        if(indices.size()<2){
            return {-1,-1};
        }
        vector<int> res(2);
        res[0]=INT_MAX;
        res[1]=indices[indices.size()-1] - indices[0];

        for(int i=0;i<indices.size()-1;i++){
            res[0]=min(res[0],indices[i+1]-indices[i]);
        }

        return res;
    }
};
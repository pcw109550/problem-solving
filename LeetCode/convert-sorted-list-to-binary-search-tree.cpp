// 109. Convert Sorted List to Binary Search Tree
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<ListNode *> L;
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            // O(N)
            if (head == NULL)
                return NULL;
            auto it = head;
            while (it != NULL) {
                L.push_back(it);
                it = it->next;
            }
            int N = L.size();
            int mid = N / 2;
            TreeNode *result = new TreeNode(L[mid]->val);
            traversal(result, 0, N - 1, mid);
            return result;
        }
    
        void traversal(TreeNode *node, int start, int end, int mid) {
            if (start < mid) {
                node->left = new TreeNode(L[(start + mid) / 2]->val);
                traversal(node->left, start, mid - 1, (start + mid) / 2);
            }
            if (mid < end) {
                int idx = (mid + end) / 2 + 1;
                node->right = new TreeNode(L[idx]->val);
                traversal(node->right, mid + 1, end, idx);
            }
        }
};

int main(void) {
    Solution s;
}
// https://leetcode.com/problems/add-two-numbers/
class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode() : val(0){};
    ListNode(int v) : val(v){};
    ListNode(int v, ListNode *next) : val(v), next(next){};
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1(l1), *p2(l2), *result = new ListNode();
    ListNode *result_cur(result);

    int v;
    while (p1 || p2 || v) {
        v += (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
        result_cur->next = new ListNode(v % 10);
        result_cur = result_cur->next;

        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
        v /= 10;
    }

    return result->next;
}
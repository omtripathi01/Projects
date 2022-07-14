#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode *next) : val(value), next(next) {}
};

// worst brute force
// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {

//     ListNode *result = new ListNode(0);
//     string num_one = "";
//     string num_two = "";

//     while (l1 != NULL)
//     {
//         num_one += to_string(l1->val);
//         cout << l1->val << " ";
//         l1 = l1->next;
//     }
//     cout << num_one << endl;
//     while (l2 != NULL)
//     {
//         num_two += to_string(l2->val);
//         cout << l2->val << " ";
//         l2 = l2->next;
//     }
//     cout << num_two << endl;
//     reverse(num_one.begin(), num_one.end());
//     reverse(num_two.begin(), num_two.end());
//     string res = to_string(stoi(num_one) + stoi(num_two));
//     cout << "\n"
//          << res << endl;
//     reverse(res.begin(), res.end());

//     ListNode *temp = result;
//     for (char i : res)
//     {
//         temp->next = new ListNode(i - '0');
//         temp = temp->next;
//     }

//     return result->next;
// }

// best solution
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return dummyHead->next;
}

ListNode *createLinkedList(vector<int> &arr)
{

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main()
{

    // ListNode *l1 = new ListNode(2, new ListNode(4));
    // l1->next->next = new ListNode(5);
    // ListNode *l2 = new ListNode(5, new ListNode(6));
    // l2->next->next = new ListNode(5);

    // vector<int>list1 = {9,9,9,9,9,9,9};
    // vector<int>list2 = {9,9,9,9};

    // failing test case :
    //   terminate called after throwing an instance of 'std::out_of_range'
    //   what():  stoi
    vector<int> list1 = {9};
    vector<int> list2 = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    ListNode *l1 = createLinkedList(list1);
    ListNode *l2 = createLinkedList(list2);
    ListNode *res = addTwoNumbers(l1, l2);

    cout << "\nFinal result: " << endl;
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
}
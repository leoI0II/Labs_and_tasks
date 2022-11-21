#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<limits>


// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int numL1 = parseList(l1), numL2 = parseList(l2);
        return solve(numL1 + numL2);
    }

    int parseList(ListNode* list)
    {
        // std::vector<int> vals;
        ListNode* current_node = list;
        int node_num = 0, result_num = 0;
        while (current_node){
            // vals.push_back(current_node->val);
            result_num += std::pow(10, node_num++) * current_node->val;
            current_node = current_node->next;
        }
        // std::reverse(vals.begin(), vals.end());
        // std::for_each(vals.begin(), vals.end(), [&](int& el){ result_num += std::pow(10, node_num++) * el;});
        return result_num;
    }

    ListNode* solve(int sum_res)
    {
        ListNode* res, *tmp = new ListNode(sum_res%10);
        sum_res /= 10;
        res = tmp;
        while(sum_res){
            tmp->next = new ListNode(sum_res%10);
            tmp = tmp->next;
            sum_res /= 10;
        }
        return res;
    }

};
//////////////////////////////////////////
///////////***NOT OPTIMAL***//////////////
//////////////////////////////////////////
int main(){

    std::cout << "Unsigned long " << sizeof(uint64_t) << std::endl;
    std::cout << "Unsigned long long " << sizeof(long double) << std::endl;
    std::cout << std::numeric_limits<unsigned long long>::max() << std::endl;
    std::cout << std::numeric_limits<unsigned long>::max() << std::endl;


    /*
    std::vector<int> vals{1, 2, 3};
    int pow_num = 0;

    std::for_each(vals.begin(), vals.end(), [&](int& el){ el = std::pow(10, pow_num++) * el;});

    // std::for_each(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, " "));
    std::copy(vals.begin(), vals.end(), std::ostream_iterator<int>(std::cout, " "));
    */

    return 0;
}

















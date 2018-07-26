//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 307 Range Sum Query - Mutable
// https://leetcode.com//problems/range-sum-query---mutable/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 112 ms
// This solution defeats 7.42% cpp solutions

struct segmentTree {
  int val;
  int low;
  int high;
  segmentTree* left;
  segmentTree* right;
};

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    if (nums.empty()) {
      root = nullptr;
    } else {
      root = buildsegTree(nums, 0, nums.size() - 1);
    }
  }

  void update(int i, int val) { updateTree(root, i, val); }

  int sumRange(int i, int j) { return queryseg(root, i, j); }
  segmentTree* buildsegTree(vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
      segmentTree* root = (segmentTree*)malloc(sizeof(segmentTree));
      root->val = nums[lo];
      root->low = lo;
      root->high = hi;
      root->left = nullptr;
      root->right = nullptr;
      return root;
    }
    int mid = lo + (hi - lo) / 2;
    segmentTree* root = (segmentTree*)malloc(sizeof(segmentTree));
    root->low = lo;
    root->high = hi;
    root->left = buildsegTree(nums, lo, mid);
    root->right = buildsegTree(nums, mid + 1, hi);
    root->val = root->left->val + root->right->val;
    return root;
  }
  void updateTree(segmentTree* root, int index, int val) {
    int mid = (root->low + root->high) / 2;
    segmentTree* p = root;
    stack<segmentTree*> path;
    path.push(root);
    while (p) {
      if (p->low == index && p->high == index) {
        break;
      }
      int mid = (p->low + p->high) / 2;
      if (index <= mid) {
        p = p->left;
      } else {
        p = p->right;
      }
      path.push(p);
    }
    int gap = val - p->val;
    while (!path.empty()) {
      path.top()->val += gap;
      path.pop();
    }
  }
  int queryseg(segmentTree* root, int i, int j) {
    segmentTree* p = root;
    if (p == nullptr) {
      return 0;
    }
    if (i == p->low && p->high == j) {
      return p->val;
    }
    if (i > p->high || j < p->low) {
      cout << p->low << " " << p->high << endl;
      return 0;
    }
    int mid = (p->low + p->high) / 2;
    if (i > mid) {
      return queryseg(root->right, i, j);
    }
    if (j <= mid) {
      return queryseg(root->left, i, j);
    }
    return queryseg(root->left, i, mid) + queryseg(root->right, mid + 1, j);
  }
  segmentTree* root;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
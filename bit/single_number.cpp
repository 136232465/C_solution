class Solution {
public:
    int singleNumber(int A[], int n) {
              int ones = 0;//记录只出现过1次的bits
        int twos = 0;//记录只出现过2次的bits
        int threes = 0;
        for(int i = 0; i < n; i++){
            twos |= ones&A[i];//要在更新ones前面更新twos
            ones ^= A[i];
            threes = ones&twos;//ones和twos中都为1即出现了3次
            ones &= ~threes;//抹去出现了3次的bits
            twos &= ~threes;
        }
        return ones;
    }
};

//leetcode singleNumber II

ones 记录出现过一个的bit
twos 记录出现过两次的bit
按每个位置上出现bit的次数来消除出现三次的数，因为出现了三次的数的每一位上的bit肯定都出现了3次。
而出现了一次的数则只能存在于ones中不存在twos中
两个一样的数相与还是原来的数。
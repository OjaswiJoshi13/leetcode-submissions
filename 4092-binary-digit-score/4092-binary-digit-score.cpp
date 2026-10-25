class Solution {
public:
    int calculateScore(int a, int b) {
        int n=__builtin_popcount(a);
        int m=__builtin_popcount(b);

        return n>=m ? n*m : m/n ;
    }
};
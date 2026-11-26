class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool alice = true;

        while (n >= x) {
            n -= x;
            x--;

            alice = !alice;
        }

        return !alice;
    }
};
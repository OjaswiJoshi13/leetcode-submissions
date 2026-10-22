class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {

        if(target > x+y) return false;

        if(target == x or target == y) return true;

        return target%gcd(x,y)==0;

    }
};


class Solution {
public:

    bool isbiggest(int n){
        vector<int> digits;

        int a = n;

        while(a>0){
            digits.push_back(a%10);
            a/=10;
        }

        sort(digits.begin(),digits.end());

        long long val = 0;

        for(int i=0;i<digits.size();i++){
            val+= (digits[i] * (pow(10,i)));
        }

        if(val == n) return true;
        
        return false;
    }

    long long rearrange(int n){
        vector<int> digits;

        int a = n;

        while(a>0){
            digits.push_back(a%10);
            a/=10;
        }

        sort(digits.begin(), digits.end(), greater<int>());

        long long val = 0;

        for (int i = 0; i < digits.size(); i++) {
            val = val * 10 + digits[i];
        }

        return val;
    }

    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(),nums.end(),greater<int>());

        vector<long long> gains;
        long long sum=0;

        for(auto num : nums){
            long long x = rearrange(num);
            sum+=num;
            gains.push_back(x-num);
        }

        sort(gains.begin(), gains.end(), greater<long long>());

        for (int i = 0; i < k && gains[i] > 0; i++) {
            sum += gains[i];
        }

        return sum;
    }
};
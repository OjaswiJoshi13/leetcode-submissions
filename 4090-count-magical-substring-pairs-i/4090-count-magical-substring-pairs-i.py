class Solution:
    def countMagicalPairs(self, s: str) -> int:
        n=len(s)
        distinct=[[0]*(n) for _ in range(n)]
        for i in range(n):
            seen=set()
            for j in range(i,n):
                seen.add(s[j])
                distinct[i][j]=len(seen)
    
        count=0 
        for i in range(n):
            for j in range(i,n-1):
                count_s1=distinct[i][j]
                count+=bisect.bisect_right(distinct[j+1],count_s1)-bisect.bisect_left(distinct[j+1],count_s1)
        return count

        

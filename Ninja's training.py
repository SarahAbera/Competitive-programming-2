from typing import *
  
def ninjaTraining(n: int, points: List[List[int]]) -> int:
    memo = [[-1]*4 for _ in range(n)]
    def recursion(days,prev_idx):
        if memo[days][prev_idx] != -1: return memo[days][prev_idx]
        if days == 0:
            maxi = 0
            for i in range(3):
                if i != prev_idx:
                    maxi = max(maxi,points[0][i])
            return maxi

        ans = 0
        for i in range(3):
            if i != prev_idx:
                cur_point = points[days][i] + recursion(days-1,i)
                ans = max(ans,cur_point)

        memo[days][prev_idx] = ans
        return memo[days][prev_idx]

    return recursion(n-1,3)

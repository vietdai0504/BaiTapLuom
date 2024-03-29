def max_sum_without_three_consecutive(nums,n):
    if n == 0:
        return 0
    if n == 1:
        return nums[0]
    if n == 2:
        return max(nums[0], nums[1])

    dp = [0] * n
    dp[0] = nums[0]
    dp[1] = nums[0] + nums[1]
    dp[2] = max(dp[1], nums[0] + nums[2], nums[1] + nums[2])

    for i in range(3, n):
        dp[i] = max(dp[i-1], dp[i-2] + nums[i], dp[i-3] + nums[i] + nums[i-1])

    return dp[-1]

# Ví dụ với một dãy số
with open('BOTTLES.inp','r') as files:
    list = files.read().split()
    n = int(list[0])
    del list[0]
    list = [int(i) for i in list]
print("Tổng lớn nhất của các số không có 3 số nào liên tiếp:", max_sum_without_three_consecutive(list,n))

#ChatGpt
def max_sum_without_three_consecutive(nums):
    n = len(nums)
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

    prev_positions = [None] * n
    prev_positions[0] = [0]
    prev_positions[1] = [0, 1]
    prev_positions[2] = [0, 1]

    for i in range(3, n):
        if dp[i-1] > dp[i-2] + nums[i]:
            dp[i] = dp[i-1]
            prev_positions[i] = prev_positions[i-1]
        else:
            dp[i] = dp[i-2] + nums[i]
            prev_positions[i] = prev_positions[i-2] + [i]

        if nums[i] + nums[i-1] > nums[i] + nums[i-2]:
            if dp[i] < dp[i-2] + nums[i] + nums[i-1]:
                dp[i] = dp[i-2] + nums[i] + nums[i-1]
                prev_positions[i] = prev_positions[i-2] + [i-1, i]

    return dp[-1], prev_positions[-1]

# Ví dụ với một dãy số
nums = [6,10,10,13,10,10]
max_sum, positions = max_sum_without_three_consecutive(nums)
print("Tổng lớn nhất của các số không có 3 số nào liên tiếp:", max_sum)
print("Vị trí các số tạo ra tổng lớn nhất:", positions)

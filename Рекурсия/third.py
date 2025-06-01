pre_prev = 1
prev = 3
odd_cnt = 2
while (odd_cnt < 40):
  cur, pre_prev = 5 * prev + pre_prev, prev
  prev = cur
  if cur % 2 == 1:
    odd_cnt += 1

print(cur)
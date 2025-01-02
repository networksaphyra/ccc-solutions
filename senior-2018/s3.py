from sys import stdin, stdout
from collections import deque

dirs = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}

n, m = map(int, stdin.readline().strip().split())
A = [stdin.readline().strip() for _ in range(n)]

vis = [[False] * m for _ in range(n)]
end = [[(-1, -1)] * m for _ in range(n)]

def in_bound(row, col):
  return 0 <= row < n and 0 <= col < m

def find_end(row, col):
  if in_bound(row, col) == False or A[row][col] == 'W' or A[row][col] == 'C':
    return (-1, -1)
  elif vis[row][col]:
    return end[row][col]
  elif A[row][col] == '.' or A[row][col] == 'S':
    return (row, col)

  vis[row][col] = True
  dir = dirs[A[row][col]]
  ans = find_end(row + dir[0], col + dir[1])
  end[row][col] = ans
  return ans

def mark_cameras(row, col):
  vis[row][col]=True
  for dir in dirs.values():
    cur_row, cur_col = row + dir[0], col + dir[1]
    while in_bound(cur_row, cur_col) and A[cur_row][cur_col] != 'W':
      if not A[cur_row][cur_col] in dirs:
        vis[cur_row][cur_col] = True
      cur_row+=dir[0]
      cur_col+=dir[1]

for i in range(n):
  for j in range(m):
    if A[i][j] in dirs and not vis[i][j]:
      find_end(i, j)


# invalidate bad cells
vis = [[False] * m for _ in range(n)]
start = (0, 0)

for i in range(n):
  for j in range(m):
    if A[i][j] == 'C':
      mark_cameras(i, j)
    elif A[i][j] == 'W':
      vis[i][j] = True
    elif A[i][j] in dirs and end[i][j][0]==-1:
      vis[i][j] = True
    elif A[i][j] == 'S':
      start = (i, j)

# for i in range(n):
#   for j in range(m):
#     print(vis[i][j], end=' ')
#   print()

# for i in range(n):
#   for j in range(m):
#     print(end[i][j], end=' ')
#   print()

q = deque()
dist = [[-1] * m for _ in range(n)]
if not vis[start[0]][start[1]]:
  q.append(start)
  dist[start[0]][start[1]] = 0
  vis[start[0]][start[1]] = True

while len(q):
  row, col = q.popleft()

  for dir in dirs.values():
    cur_row = row + dir[0]
    cur_col = col + dir[1]

    if in_bound(cur_row, cur_col) == False or vis[cur_row][cur_col]:
      continue

    if A[cur_row][cur_col] in dirs:
      end_row, end_col = end[cur_row][cur_col]
      if in_bound(end_row, end_col) and not vis[end_row][end_col]:
        dist[end_row][end_col] = dist[row][col] + 1
        q.append((end_row, end_col))
        vis[end_row][end_col] = True

    else:
      q.append((cur_row, cur_col))
      dist[cur_row][cur_col] = dist[row][col] + 1
      vis[cur_row][cur_col] = True

for i in range(n):
  for j in range(m):
    if A[i][j]=='.':
      stdout.write(f"{dist[i][j]}\n")

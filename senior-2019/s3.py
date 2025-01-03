from sys import stdin, stdout

mn, mx=-1_000_000, 1_000_000

def find_value(B):
  a, b, c=B
  if a=='X':
    return int(b) - (int(c) - int(b))
  elif b=='X':
    return (int(a) + int(c)) // 2
  elif c=='X':
    return int(b) + (int(b) - int(a))

def bad(B):
  for i in range(3):
    for j in range(3):
      if B[i][j]=='X': continue
      if not mn<=int(B[i][j])<=mx:
        return True
  return False

def good(B):
  for row in B:
    if not is_arithmetic_sequence(row):
      return False
  for j in range(3):
    col=[B[i][j] for i in range(3)]
    if not is_arithmetic_sequence(col):
      return False
  return True

def is_arithmetic_sequence(B):
  a, b, c=B
  return int(b)-int(a)==int(c)-int(b)

def fill(B):
  changed = False
  for i in range(3):
    if B[i].count('X')==1:
      changed = True
      B[i][B[i].index('X')]=str(find_value(B[i]))
  for j in range(3):
    col=[B[i][j] for i in range(3)]
    if col.count('X')==1:
      changed = True
      B[col.index('X')][j]=str(find_value(col))
  return changed

def dfs(A):
  while fill(A): pass
  if bad(A):
    return None
  if all(char!='X' for row in A for char in row):
    if good(A):
      return A
    return None

  for i in range(3):
    for j in range(3):
      if A[i][j]!='X': continue
      row=A[i]
      col=[A[k][j] for k in range(3)]
      vals=[0]
      for val in row+col:
        if val=='X': continue
        vals.append(val)

      for val in vals:
        B=[row[:] for row in A]
        B[i][j]=str(val)
        res=dfs(B)
        if res!=None: return res
  return None

A=[stdin.readline().strip().split() for _ in range(3)]
res=dfs(A)

if res!=None:
  for i in range(3):
    for j in range(3):
      stdout.write(f"{res[i][j]} ")
    stdout.write("\n")
else:
  stdout.write("your trash kid\n")

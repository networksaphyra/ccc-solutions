def main() -> None:
  n=int(input())
  ans=[]
  for _ in range(n):
    line=input().split()
    a, b, c=map(int, line[1:])
    ans.append([2*a + 3*b + c, line[0]])

  ans.sort()
  if n==0:
    return
  if n==1:
    print(ans[-1][1])
  else:
    if ans[-1][0]==ans[-2][0]:
      cnt=0
      for i in ans:
        if cnt==2:
          return
        if i[0]==ans[-1][0]:
          print(i[1])
          cnt+=1
    else:
      print(ans[-1][1])
      for i in ans:
        if i[0]==ans[-2][0]:
          print(i[1])
          return

if __name__ == "__main__":
  main()

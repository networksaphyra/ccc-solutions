import sys

def main():
  s=input()
  t=input()

  genes=[]
  p=0

  while p<len(s):
    if s[p]!=t[p]:
      genes.append("*")
    else:
      genes.append(s[p])
    p+=2

  n=int(input())
  for _ in range(n):
    cur=input()
    ok=True

    for i in range(len(cur)):
      if genes[i]=="*":
        continue
      if genes[i]!=cur[i]:
        ok=False

    if ok:
      print("Possible baby.")
    else:
      print("Not their baby!")


main()

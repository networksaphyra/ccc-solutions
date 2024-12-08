def main() -> None:
  n = int(input())

  for _ in range(n):
    words = []
    for _ in range(3):
      words.append(input())

    words.sort()

    a, b, c = words
    if a in b or a in c:
      print("No")
      continue

    if b in c:
      print("No")
      continue

    print("Yes")

if __name__ == "__main__":
  main()

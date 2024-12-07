def main():
  n = int(input())

  vowels = ['a', 'e', 'i', 'o', 'u']

  for _ in range(n):
    lines = [] # Will have four lines
    for _ in range(4):
      lines.append(input().lower())

    answer = []

    for line in lines:
      last_word = line.split()[-1]
      current = ""
      for j in last_word[::-1]:
        current += j
        if j in vowels:
          break

      answer.append(current[::-1])

    first, second, third, fourth = answer
    if first == second == third == fourth:
      print("perfect")
    elif first == second and third == fourth:
      print("even")
    elif first == third and second == fourth:
      print("cross")
    elif first == fourth and second == third:
      print("shell")
    else:
      print("free")



if __name__ == "__main__":
  main()

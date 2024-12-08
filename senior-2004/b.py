def main() -> None:
  n, k = map(int, input().split())
  scores = [0] * n
  worst_rank = [1] * n

  for _ in range(k):
    current_scores = list(map(int, input().split()))

    rankings = set()
    for i in range(n):
      scores[i] += current_scores[i]
      rankings.add(scores[i])

    array = list(rankings)
    array.sort()
    mp = dict()
    for i in range(len(array)):
      mp[array[i]]=len(array)-i

    for i in range(n):
      worst_rank[i] = max(worst_rank[i], mp[scores[i]])

  mx = 0
  for i in range(n):
    if scores[i] > mx:
      mx=scores[i]

  for i in range(n):
    if scores[i]==mx:
      print(f"Yodeller {i+1} is the TopYodeller: score {mx}, worst rank {worst_rank[i]}")

main()

def orientation(a, b, c):
  val=(a[1]-b[1]) * (c[0]-b[0]) - (a[0]-b[0]) * (c[1]-b[1])
  if val==0:
    return val
  elif val > 0:
    return 1
  else:
    return 2

def on_segment(p, q, r):
  return (
    min(p[0], r[0]) <= q[0] <= max(p[0], r[0]) and
    min(p[1], r[1]) <= q[1] <= max(p[1], r[1])
  )

def intersect(seg1, seg2):
  p1, q1=seg1
  p2, q2=seg2

  o1=orientation(p1, q1, q2)
  o2=orientation(p1, q1, q1)
  o3=orientation(p2, q2, q1)
  o4=orientation(p2, q2, q2)

  if o1!=o2 and o3!=o4:
    return True


def do_segments_intersect(seg1, seg2):
    p1, q1 = seg1
    p2, q2 = seg2

    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    if o1!=o2 and o3!=o4:
        return True

    if o1==0 and on_segment(p1, p2, q1):
        return True
    if o2==0 and on_segment(p1, q2, q1):
        return True
    if o3==0 and on_segment(p2, p1, q2):
        return True
    if o4==0 and on_segment(p2, q1, q2):
        return True

    return False

def solve():
    # Read Romy and Jules' window coordinates
    xr, yr, xj, yj = map(int, input().split())

    # Line of sight segment
    line_of_sight = ((xr, yr), (xj, yj))

    # Number of buildings
    n = int(input())

    # Count blocked buildings
    blocked_buildings = 0

    # Process each building
    for _ in range(n):
        # Read building corners
        building_input = list(map(int, input().split()))
        corners_count = building_input[0]
        corners = [(building_input[i], building_input[i+1])
                   for i in range(1, len(building_input), 2)]

        # Check each building edge against line of sight
        building_blocks = False
        for i in range(corners_count):
            # Create an edge from current corner to next corner (wrapping around)
            edge = (corners[i], corners[(i+1) % corners_count])

            # Check if this edge intersects line of sight
            if do_segments_intersect(line_of_sight, edge):
                building_blocks = True
                break

        # Increment blocked buildings if any edge intersects
        if building_blocks:
            blocked_buildings += 1

    # Output result
    print(blocked_buildings)

# Run the solution
solve()

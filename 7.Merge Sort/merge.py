def merge_sort(orders):
    if len(orders) > 1:
        mid = len(orders) // 2  # Find midpoint
        left_half = orders[:mid]
        right_half = orders[mid:]

        # Recursive sorting of both halves
        merge_sort(left_half)
        merge_sort(right_half)

        # Merge the sorted halves
        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i][1] <= right_half[j][1]:  # Compare by delivery time
                orders[k] = left_half[i]
                i += 1
            else:
                orders[k] = right_half[j]
                j += 1
            k += 1

        # Copy remaining elements
        while i < len(left_half):
            orders[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            orders[k] = right_half[j]
            j += 1
            k += 1


# ---------------- MAIN PROGRAM ----------------
orders = [
    ("Order #101", 45),
    ("Order #102", 15),
    ("Order #103", 30),
    ("Order #104", 10),
    ("Order #105", 25)
]

print("Before Sorting (by delivery time):")
for order in orders:
    print(order)

merge_sort(orders)

print("\nAfter Sorting (by delivery time - quickest first):")
for order in orders:
    print(order)

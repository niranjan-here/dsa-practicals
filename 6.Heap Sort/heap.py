def heapify(arr, n, i):
    """Ensure the subtree rooted at index i satisfies the max-heap property"""
    largest = i       # Initialize largest as root
    left = 2 * i + 1  # Left child index
    right = 2 * i + 2 # Right child index

    # If left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # If right child exists and is greater than current largest
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not the root, swap and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)

    # Step 1: Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Step 2: Extract elements one by one
    for i in range(n - 1, 0, -1):
        # Swap current root (max element) with the last element
        arr[i], arr[0] = arr[0], arr[i]

        # Heapify the reduced heap
        heapify(arr, i, 0)


# ---------------- MAIN PROGRAM ----------------
arr = [45, 12, 89, 33, 25, 78, 10]

print("Original Array:")
print(arr)

heap_sort(arr)

print("\nSorted Array (Ascending Order):")
print(arr)

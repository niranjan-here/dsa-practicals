# Function to get maximum profit using Fractional Knapsack
def fractional_knapsack(weights, profits, capacity):
    n = len(weights)

    # Calculate profit/weight ratio for each parcel
    ratio = []
    for i in range(n):
        ratio.append((profits[i] / weights[i], weights[i], profits[i]))  # (ratio, weight, profit)

    # Sort parcels by ratio in descending order (most profitable first)
    ratio.sort(reverse=True)

    total_profit = 0.0
    remaining_capacity = capacity

    print("\nSelected Parcels:")
    for r, w, p in ratio:
        if remaining_capacity == 0:
            break

        if w <= remaining_capacity:
            # Take the full parcel
            total_profit += p
            remaining_capacity -= w
            print(f"  Took full parcel (weight={w}, profit={p})")
        else:
            # Take fractional part of parcel
            fraction = remaining_capacity / w
            total_profit += p * fraction
            print(f"  Took {fraction*100:.1f}% of parcel (weight={w}, profit={p})")
            remaining_capacity = 0

    return total_profit


# ---------------- MAIN PROGRAM ----------------
weights = [10, 40, 20, 30]   # Parcel weights
profits = [60, 40, 100, 120] # Parcel profits
capacity = 50                # Truck weight capacity

print("Parcel weights:", weights)
print("Parcel profits:", profits)
print("Truck capacity:", capacity)

max_profit = fractional_knapsack(weights, profits, capacity)
print(f"\nMaximum Profit that can be obtained = {max_profit:.2f}")

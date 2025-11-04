def naive_string_match(text: str, pattern: str) -> list:
    """
    Return a list of all starting indices i where text[i:i+m] == pattern
    using the naive string matching algorithm.
    If pattern is empty (m == 0), returns all indices 0..n (inclusive).
    """
    n = len(text)
    m = len(pattern)
    matches = []

    # Edge-case: empty pattern matches at every position 0..n
    if m == 0:
        return list(range(n + 1))

    # For each possible alignment i of pattern with text
    for i in range(n - m + 1):
        j = 0
        # compare characters one by one
        while j < m and text[i + j] == pattern[j]:
            j += 1
        if j == m:
            matches.append(i)

    return matches


# ---------------- Example usage ----------------
if __name__ == "__main__":
    txt = "ABABDABACDABABCABAB"
    pat = "ABABCABAB"
    result = naive_string_match(txt, pat)
    print("Matches at indices:", result)  # expected: [10]

    # Edge cases
    print(naive_string_match("aaaaa", "aa"))   # [0,1,2,3]
    print(naive_string_match("abc", ""))       # [0,1,2,3]  (empty pattern)
    print(naive_string_match("", ""))          # [0]
    print(naive_string_match("", "a"))         # []

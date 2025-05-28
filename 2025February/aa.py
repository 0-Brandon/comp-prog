def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx])
    idx += 1
    a = list(map(int, input[idx:idx+N]))
    idx += N
    c = list(map(int, input[idx:idx+N]))
    
    sum_total = sum(c)
    
    sum_c = [0] * (N + 1)  # sum_c[s] for s from 1 to N
    for x in range(N):
        s = a[x]
        sum_c[s] += c[x]
    
    # Compute minimal singleton cost
    minimal_single = float('inf')
    for s in range(1, N+1):
        current = sum_total - sum_c[s]
        if current < minimal_single:
            minimal_single = current
    
    # Compute S0: original fixed points
    S0 = set()
    for s in range(1, N+1):
        if a[s-1] == s:
            S0.add(s)
    
    if S0:
        cost0 = 0
        for x in range(N):
            current_s = x + 1
            if current_s not in S0:
                ax = a[x]
                if ax not in S0:
                    cost0 += c[x]
        answer = min(minimal_single, cost0)
    else:
        answer = minimal_single
    
    print(answer)

if __name__ == "__main__":
    main()
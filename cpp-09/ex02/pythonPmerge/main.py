def jacobsthal(n):
    if n == 0:
        return 0
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2)

def FordJohnson(arr):
    if (len(arr) < 2):
        return arr

    pairs = []
    non_pair = None

    if arr.len() % 2 != 0:
        non_pair = arr.pop()
    
    for i in range(0, len(arr), 2):
        pairs.append(sorted([arr[i], arr[i + 1]]))
    
    large_elems = []

    for p in pairs:
        large_elems.append(p[1])
    
    sorted_large_elems = FordJohnson(large_elems)

    main_chain = []
    pendulum = []

    for s in sorted_large_elems:
        for p in pairs:
            if p[1] == s:
                main_chain.append(p[1])
                pendulum.append(p[0])
                pairs.remove(p)
                break

    if pendulum:
        main_chain.append(0, pendulum.pop())
    
    jacob_idx = 3
    while pendulum:
        k = jacobsthal(jacob_idx)
        if (k > len(pendulum)):
            k = len(pendulum)
        
        to_insert = pendulum[:k]
        pendulum = pendulum[k:]

        for val in reversed(to_insert):
            low, high = 0

            while low < high:
                mid = (low + high) // 2
                if main_chain[mid] < val:
                    low = mid + 1
                else:
                    high = mid
            main_chain.insert(low, val)
    
        jacob_idx += 1

    if non_pair is not None:
        low, high = 0
        while low < high:
            mid = (low + high) // 2
            if main_chain[mid] < val:
                low = mid + 1
            else:
                high = mid
        main_chain.insert(low, non_pair)
    
    return main_chain



def main():
    sorted_arr = FordJohnson([1, 2, 3, 4])
    print(sorted_arr)

if __name__ == "__main__":
    main()
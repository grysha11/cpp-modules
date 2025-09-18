import sys

def jacobsthal(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2)

def FordJohnson(arr):
    if (len(arr) < 2):
        return arr

    pairs = []
    non_pair = None

    if len(arr) % 2 != 0:
        non_pair = arr.pop()
    
    for i in range(0, len(arr), 2):
        pairs.append(sorted([arr[i], arr[i + 1]]))
    
    large_elems = []

    original_pairs = list(pairs)

    for p in pairs:
        large_elems.append(p[1])
    
    sorted_large_elems = FordJohnson(large_elems)

    main_chain = []
    pendulum = []

    for s in sorted_large_elems:
        for p in original_pairs:
            if p[1] == s:
                main_chain.append(p[1])
                pendulum.append(p[0])
                original_pairs.remove(p)
                break

    if pendulum:
        main_chain.insert(0, pendulum[0])
    
    last_insert_idx = 1
    jacob_idx = 3
    while last_insert_idx < len(pendulum):
        k = jacobsthal(jacob_idx)
        end_idx = min(last_insert_idx + k, len(pendulum))
        for i in range(end_idx - 1, last_insert_idx - 1, -1):
            val = pendulum[i]
            partner = sorted_large_elems[i]
            limit = main_chain.index(partner)
            low, high = 0, limit
            while low < high:
                mid = (low + high) // 2
                if main_chain[mid] < val:
                    low = mid + 1
                else:
                    high = mid
            main_chain.insert(low, val)
        last_insert_idx = end_idx
        jacob_idx += 1

    if non_pair is not None:
        low, high = 0, len(main_chain)
        while low < high:
            mid = (low + high) // 2
            if main_chain[mid] < non_pair:
                low = mid + 1
            else:
                high = mid
        main_chain.insert(low, non_pair)
    
    return main_chain



def main():
    if len(sys.argv) < 2:
        print("Usage: python3 ford_johnson.py <numbers...>")
        return
    arr = [int(x) for x in sys.argv[1:]]
    to_sort = list(arr)
    print("Input: ", to_sort)
    sorted_arr = FordJohnson(to_sort)
    print("Sorted:", sorted_arr)
    if sorted_arr == sorted(arr):
        print("everything is correct")

if __name__ == "__main__":
    main()
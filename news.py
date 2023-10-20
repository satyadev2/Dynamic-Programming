# Function to read input and return the list of test cases
def read_input():
    t = int(input())
    test_cases = []
    for i in range(t):
        X, Y = map(int, input().split())
        N = int(input())
        circles = []
        for j in range(N):
            cxi, cyi, ri = map(int, input().split())
            circles.append((cxi, cyi, ri))
        test_cases.append((X, Y, N, circles))
    return test_cases

# Function to print the output for each test case


def print_output(test_cases):
    for can_reach in test_cases:
        if can_reach:
            print("YES")
        else:
            print("NO")

# Main function to run the program


def main():
    test_cases = read_input()
    results = []
    for test_case in test_cases:
        X, Y, N, circles = test_case
        can_reach = can_reach_destination(X, Y, N, circles)
        results.append(can_reach)
    print_output(results)


if __name__ == "__main__":
    main()

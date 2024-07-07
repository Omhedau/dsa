#include <vector>
#include <string>
using namespace std;

//backtracking.....

// Key Concepts:
// Choice: At each step, make a choice out of several possibilities.
// Constraint: Check if the choice leads to a solution.
// Backtrack: If the choice doesn’t lead to a solution, undo the choice and try another.

// Patterns:
// Subset Generation: Generate all subsets of a set.
// Permutation Generation: Generate all permutations of a set.
// Combinatorial Problems: Solve problems like Sudoku, N-Queens, etc.


//generate all binary string with non adjecant '0' 
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string sb;
        generateStrings(result, sb, n, -1);
        return result;
    }

private:
    void generateStrings(vector<string>& result, string& sb, int n, int lastChar) {
        if (sb.length() == n) {
            result.push_back(sb);
            return;
        }

        // Add '1' to the string
        sb.push_back('1');
        generateStrings(result, sb, n, 1);
        sb.pop_back();

        // Add '0' to the string, only if the last character was not '0'
        if (lastChar != 0) {
            sb.push_back('0');
            generateStrings(result, sb, n, 0);
            sb.pop_back();
        }
    }
};
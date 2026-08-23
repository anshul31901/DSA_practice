// CSES - Grid Path (lexicographically minimal string from top-left to bottom-right)
//
// COMMIT MESSAGE:
// Solve CSES Grid Path with diagonal-wise DP + greedy elimination, O(n^2)
//
//   Naive DP (dp[i][j] = best string ending at (i,j)) is O(n^3) since each
//   state stores/compares a string of length up to 2n -> TLE for n=3000.
//   Instead, exploit that every cell on diagonal d = i+j holds a prefix of
//   the same length (d+1). Process diagonal by diagonal, keep only a
//   boolean "alive" flag per row (column is implied: j = d - i), and at
//   each diagonal only cells matching that diagonal's minimum letter
//   survive to the next one. This reduces the state from "a string per
//   cell" to "1 bit per cell", giving O(n) work per diagonal x O(n)
//   diagonals = O(n^2) total.
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

// Returns true if index i is a valid row/column index for an n x n grid.
// Used to bounds-check both the current cell and its two possible parents
// (the cell one "down" move or one "right" move away).
bool isValid(int i, int n ){
    return (i>=0 && i<n);
}

struct project{
    int st;
    int ed;
    long long val;
};
static bool comp(project &a , project &b){
    return a.ed<=b.ed;
}

void solve(int n ){
    vector<string>v(n);
    for(int i = 0 ; i <n ; i++){
        cin>>v[i];
    }

    // Diagonals are numbered d = i + j, d = 0 .. 2n-2, so there are
    // D = 2n-1 diagonals in total (this also equals the length of the
    // final answer string).
    const int D = 2*n -1;

    // dp[d][i] = 1  <=>  cell (i, d-i) can be part of SOME optimal
    //                    (lexicographically smallest) prefix of length d+1
    //          = 0  <=>  cell (i, d-i) has been eliminated: appending its
    //                    letter would make the string worse than best[d],
    //                    so no path through it can ever be optimal again.
    //
    // Column j is never stored explicitly -- it's always recovered as
    // j = d - i, since every cell on diagonal d satisfies i + j = d.
    vector<vector<bool>>dp(D,vector<bool>(n,0));

    // best[d] = the d-th character of the final answer = the smallest
    // letter among all cells still alive (dp[d][i]==1) on diagonal d.
    string best(D, ' ');

    // ---- Base case ----
    // Diagonal 0 has exactly one cell: (0,0). It's trivially alive and
    // trivially optimal (there's nothing to compare it against yet).
    best[0]= v[0][0];
    dp[0][0] = 1;

    // ---- Main loop: derive diagonal d from diagonal d-1 ----
    // For each d, two things happen in order:
    //   Phase A: fully populate dp[d][*] using dp[d-1][*] and best[d-1]
    //            (this is the ELIMINATION step)
    //   Phase B: scan the now-complete dp[d][*] to compute best[d]
    // best[d] is NEVER precomputed ahead of time -- it only exists once
    // dp[d] itself is fully known.
    for(int d = 1; d<D ; d++){

        // ---------- Phase A: populate dp[d] ----------
        for(int i = 0 ; i <n ; i++){
            int prev = d-1;

            // "left" = this cell's RIGHT-move parent: same row i,
            // column one less (i.e. parent sits at (i, prev-i) on
            // diagonal prev = d-1). Valid only if that parent was alive
            // AND its letter matched best[prev] (i.e. it wasn't
            // eliminated on the previous diagonal).
            bool left = 0;
            if(isValid(prev-i,n)&&dp[prev][i]&&v[i][prev-i]==best[prev]){
                left = 1;
            }

            // "up" = this cell's DOWN-move parent: row i-1, same
            // column as this cell (parent sits at (i-1, j) where
            // j = prev-(i-1), which is on diagonal prev = d-1 too).
            // Valid only if that parent was alive AND matched best[prev].
            bool up = 0;
            if(i>=1){
                int j = prev - (i-1);
                if(isValid(j,n)&&dp[d-1][i-1]&&v[i-1][j]==best[prev]){
                    up = 1;
                }
            }

            // Cell (i, d-i) is alive now if EITHER parent produced it
            // via a legal, non-eliminated move.
            dp[d][i] = left||up;
        }

        // ---------- Phase B: compute best[d] from the finished dp[d] ----------
        char optimal = 'Z'+1;
        for(int i = 0 ; i <n ; i++){
            if(!dp[d][i])continue;             // skip dead cells
            if(isValid(d-i,n)){
                optimal = min(optimal,v[i][d-i]);
            }
        }
        best[d]=optimal;
    }

    cout << best;
}

int main() {
    int n ;
    cin>>n;
    solve(n);
}

/* -----------------------------------------------------------------------
   WORKED EXAMPLE (n = 3)

   Grid, each cell labelled letter[diagonal]:

        A[0]  A[1]  A[2]
        A[1]  B[2]  A[3]
        A[2]  C[3]  A[4]

   (diagonal d = row + col, e.g. the 'B' is at row 1, col 1 -> d = 2)

   dp[d][i] table as it fills in (1 = alive, . = doesn't exist / dead):

                i=0   i=1   i=2
        d=0      1     .     .
        d=1      1     1     .
        d=2      1     1     1
        d=3      .     1     1
        d=4      .     .     1

   best[d] for each diagonal:
        d:     0    1    2    3    4
        best:  A    A    A    A    A

   Reading:
     - d=0: only (0,0)='A' alive -> best[0]='A'.
     - d=1: both (0,1)='A' and (1,0)='A' alive (tie) -> best[1]='A',
            BOTH kept alive (neither eliminated, since both match).
     - d=2: (0,2)='A', (1,1)='B', (2,0)='A' all alive (inherited from
            d=1's two survivors) -> best[2]=min(A,B,A)='A'.
            (1,1)='B' does NOT match 'A', so it is eliminated here --
            it will produce no children on d=3.
     - d=3: only (1,2)='A' and (2,1)='C' alive (note (0,*) branch is
            gone: row 0 has no valid cell in bounds at d=3) -> best[3]=
            min(A,C)='A'. (2,1)='C' eliminated, produces no children.
     - d=4: only (2,2)='A' alive -> best[4]='A'.

   Final answer: "AAAAA"
   ----------------------------------------------------------------------- */

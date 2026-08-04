https://leetcode.com/problems/stone-game/description/?envType=daily-question&envId=2026-08-04
/*
 * Key insight: n is even, so piles split cleanly into two groups —
 * even-indexed piles and odd-indexed piles (n/2 each).
 * Since total sum is odd, these two groups can NEVER have equal sums,
 * so one group is strictly larger.
 *
 * Alice can force herself to get ALL piles of whichever group is larger:
 *   - The two ends always start as (even index, odd index) — different parity.
 *   - Alice always takes the end matching her target parity.
 *   - Removing an end shifts the parity of the new end at that side,
 *     so the two ends are always opposite parity again before Bob's turn.
 *   - This forces Bob into the other parity every single turn.
 *
 * Result: Alice gets exactly the larger-sum group, Bob gets the smaller.
 * So Alice always wins — answer is unconditionally true.
 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

1418C --- Mortal Kombat Tower
- Platform: Codeforces
- Contest: Educational Codeforces Round 95 (Rated for Div. 2)
- Problem: 1418C --- Mortal Kombat
  Tower
- Rating: 1500
- Tags: Dynamic Programming, Greedy, Graphs, Shortest Paths
- Language: GNU C++23
1. Problem summary
There are (n) bosses, processed in their original order. Each boss is
either easy ((a_i=0)) or hard ((a_i=1)).

The friend acts first, followed by the player, and they alternate
sessions. In each session, its participant must defeat either one or two
consecutive bosses, provided bosses remain.

The player can defeat every boss without cost. The friend cannot defeat
a hard boss without spending one skip point. The task is to minimise the
total number of skip points spent by the friend.
2. DP state
Let

\(dp\[i\)\(j\) ]

be the minimum number of skip points required to defeat bosses from
index (i) through (n-1), given the current session status encoded by
(j).

The four states describe whose session is active and whether that
participant may still defeat one more boss in the same session:
  State                               Meaning
  j = 0                             Player's session; the player may
defeat one or two bosses.

  j = 1                             Player's session; the player must
finish after defeating one boss.

  j = 2                             Friend's session; the friend may
defeat one or two bosses.
j = 3                             Friend's session; the friend must
finish after defeating one boss.
The initial state is dp[0][2], because the friend takes the first
session and may defeat one or two bosses.

If all bosses have been defeated, no further skip points are needed:

\(dp\[i\)\(j\)=0 \quad {=tex}`\text{when }`{=tex} i`\ge `{=tex}n. ]
3. Transitions
State 0: Player may defeat one or two bosses
The player pays nothing.
- If the player defeats one boss, the same session continues with
  state 1.
- If the player defeats two bosses, the friend's session begins with
  state 2.
Therefore,

\(dp\[i\)\(0\)=`\min`{=tex}(dp\(i+1\)\(1\),dp\(i+2\)\(2\)). ]
State 1: Player must finish after one boss
The player defeats the current boss for free. The friend's session then
begins:

\(dp\[i\)\(1\)=dp\(i+1\)\(2\). ]
State 2: Friend may defeat one or two bosses
The friend must spend one skip point if the current boss is hard. The
cost of defeating the current boss is therefore (a_i).
- If the friend defeats one boss, the same session continues in state
  3.
- If the friend defeats two bosses, the player's session begins in
  state 0.
Thus,

\(dp\[i\)\(2\)=a_i+`\min`{=tex}(dp\(i+1\)\(3\),dp\(i+2\)\(0\)). ]
State 3: Friend must finish after one boss
The friend defeats the current boss and then the player's session
begins. The friend pays (a_i) if this boss is hard:

\(dp\[i\)\(3\)=a_i+dp\(i+1\)\(0\). ]
4. Correctness proof
We prove that (dp\(i\)\(j\)) gives the minimum number of skip points
needed to defeat all remaining bosses from index (i), under the session
condition represented by state (j).

Base case. If (i`\ge `{=tex}n), every boss has already been
defeated. No additional skip points are necessary, so the optimal cost
is zero. This agrees with the base case.

Inductive hypothesis. Assume that for every index greater than (i),
all four DP states correctly give the minimum additional cost from that
index onward.

Inductive step. Consider the four possible states at index (i).
- In state 0, the player may defeat either one or two bosses. These
  are the only legal choices. Both choices cost zero immediately, and
  they lead respectively to states 1 and 2. By the inductive
  hypothesis, the corresponding DP values are the optimal remaining
  costs. Taking their minimum is therefore optimal.
- In state 1, the player must defeat exactly one boss before the
  friend's session begins. This costs zero and leads to state 2. The
  inductive hypothesis makes dp[i+1][2] the optimal remaining cost.
- In state 2, the friend may defeat either one or two bosses.
  Defeating the current boss costs exactly (a_i): zero for an easy
  boss and one for a hard boss. The two legal choices lead
  respectively to states 3 and 0. By the inductive hypothesis,
  taking the minimum of their continuation costs gives the optimal
  choice.
- In state 3, the friend must defeat exactly one boss. The immediate
  cost is (a_i), after which the player's session begins in state 0.
  The inductive hypothesis gives the optimal continuation cost.
Every legal action is considered in the relevant state, and no illegal
action is included. Each recurrence therefore selects the minimum cost
among all possible legal continuations.

By induction, all DP states are correct. Since the first session belongs
to the friend and the friend may defeat one or two bosses, the required
answer is

\(`\boxed{dp[0][2]}`{=tex}.\)
5. Complexity analysis
There are (n) positions and four states per position. Each state is
computed once, and each transition performs only a constant amount of
work.
- Time complexity: (O(n)) per test case.
- DP memory complexity: (O(n)), since four values are stored for
  each index.
- Auxiliary recursion-stack space: (O(n)) in the worst case,
  because the memoised implementation is recursive.
Across all test cases, the total time is (O(\sum {=tex}n)), and the
total DP storage for one test case is (O(n)). The problem guarantees
(\sum {=tex}n`\le 2`{=tex}`\cdot10`{=tex}^5).
6. Implementation notes
- The implementation uses memoisation: -1 marks a state that has not
  yet been computed.
- The answer is obtained from f(f, 0, 2).
- The recurrence uses i + 1 and i + 2; the base case i >= n
  safely handles transitions beyond the final boss.
- The recursive implementation has depth (O(n)). For large (n), an
  iterative bottom-up implementation avoids relying on the process
  stack.
7. Key takeaway
The important modelling idea is to represent not only the current index,
but also the participant and the remaining choice within the current
session. Once the session status is encoded in four states, every
decision has only two possible transitions, producing a linear-time
dynamic programming solution.
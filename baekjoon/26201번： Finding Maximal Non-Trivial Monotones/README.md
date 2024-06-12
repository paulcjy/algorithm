# 26201번: Finding Maximal Non-Trivial Monotones - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26201)


<p>In this problem we will be dealing with character sequences, often called <em>strings</em>. A sequence is <em>non-trivial</em> if it contains at least two elements.</p>

<p>Given a sequence $s$, we say that a chunk $s_i , \dots , s_j$ is <em>monotone</em> if all its characters are equal, and we say that it is <em>maximal</em> if this chunk cannot be extended to left or right without losing the monotonicity.</p>

<p>Given a sequence composed only of characters “<code>a</code>” and “<code>b</code>”, determine how many characters “<code>a</code>” occur in non-trivial maximal monotone chunks.</p>



## 입력


<p>The input consists of two lines. The first line contains a single integer $N$, where $1 ≤ N ≤ 10^5$. The second line contains a string with exactly $N$ characters, composed only of the characters “<code>a</code>” and “<code>b</code>”.</p>



## 출력


<p>Print a single line containing an integer representing the total number of times the character “<code>a</code>” occurs in non-trivial maximal monotone chunks.</p>



## 소스코드

[소스코드 보기](Finding%20Maximal%20Non-Trivial%20Monotones.cpp)
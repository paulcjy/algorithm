# 17499번: 수열과 시프트 쿼리 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17499)


<p>백준 온라인 저지를 여행하다 보면 하나의 수열이 주어지고 여기에 여러 가지 연산을 하는 문제들을 만나볼 수 있습니다.</p>

<p>진수는 백준 온라인 저지에서 문제를 풀다 다음과 같은 문제를 찾았습니다.</p>

<p>길이가 <em>N</em>인 정수 수열 [<em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, ..., <em>a<sub>N</sub></em>] 이 주어진다. 다음과 같은 연산들을 수행한 후 수열을 출력하는 프로그램을 작성하시오.</p>

<ul>
<li><code>1 i x</code> : <em>a<sub>i</sub></em>에 정수&nbsp;<em>x</em>만큼 더한다.</li>
<li><code>2 s</code> : 수열을 오른쪽으로 <em>s</em>칸 시프트한다.</li>
<li><code>3 s</code> : 수열을 왼쪽으로 <em>s</em>칸 시프트한다.</li>
</ul>

<p>수열을 오른쪽으로 한 칸 시프트하면 수열 [<em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, …, <em>a<sub>N-1</sub></em>, <em>a<sub>N</sub></em>] 은 [<em>a<sub>N</sub></em>, <em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, …, <em>a<sub>N-1</sub></em>] 이 되고</p>

<p>수열을 왼쪽으로 한 칸 시프트하면 수열 [<em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, …, <em>a<sub>N-1</sub></em>, <em>a<sub>N</sub></em>] 은 [<em>a<sub>2</sub></em>, …, <em>a<sub>N-1</sub></em>, <em>a<sub>N</sub></em>, <em>a<sub>1</sub></em>] 이 된다.</p>

<p>진수는 빠르게 코딩하여 제출하였는데 '<span style="color:#e74c3c;">시간 초과</span>' 판정을 받았습니다.</p>

<p>진수가 작성한 코드는 시프트 연산을 수행할 때마다 반복문이 N번 실행되어 너무 느리기 때문입니다.</p>

<p>진수는 이 문제를 풀어 '<span style="color:#009F6B;"><strong>맞았습니다!!</strong></span>' 를 띄워줄 누군가를 기다리고 있습니다.</p>



## 입력


<p>첫 번째 줄에 수열의 길이 <em>N</em> (2 ≤ <em>N</em> ≤ 200,000) 과 연산의 개수 <em>Q</em> (1 ≤ <em>Q</em> ≤ 200,000) 가 주어집니다.</p>

<p>두 번째 줄에는 정수&nbsp;<em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, ..., <em>a<sub>N</sub></em> (-10,000 ≤ <em>a<sub>i</sub></em> ≤ 10,000) 이 주어집니다.</p>

<p>다음 <em>Q</em>개의 줄에는 각 줄 마다 연산이 주어집니다.&nbsp;</p>



## 출력


<p>첫 번째 줄에 <em>Q</em>개의 연산을 차례대로 수행한 후&nbsp;<em>a<sub>1</sub></em>, <em>a<sub>2</sub></em>, …, <em>a<sub>N</sub></em>&nbsp;을 공백을 사이에 두고 출력합니다.</p>



## 소스코드

[소스코드 보기](수열과%20시프트%20쿼리.cpp)
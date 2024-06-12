# 24993번: KIARA is a Recursive Acronym - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24993)


<p>A recursive acronym is an acronym in which one of its letters stands for the acronym itself. For instance, the first word in the title of this problem is a recursive acronym of the full title. Another example is “BOB”, which is an acronym of “Beware of Bob”.</p>

<p>Given a list of words, you must decide whether there exists a word in the list which is a recursive acronym of a phrase that can be formed using words in the list. Since the first letter of any word can stand for the whole word, it is enough to decide whether there exists a word in the list which can be formed using the first letter of some words in the list.</p>



## 입력


<p>The first line contains a positive integer N indicating the number of words in the list. Each of the next N lines contains a non-empty string made of uppercase letters representing a word in the list. The sum of the lengths of all the strings is at most 10<sup>6</sup>.</p>



## 출력


<p>Output a single line with the uppercase letter “<code>Y</code>” if there exists a word in the list which is a recursive acronym of a phrase that can be formed using words in the list, and the uppercase letter “<code>N</code>” otherwise.</p>



## 소스코드

[소스코드 보기](KIARA%20is%20a%20Recursive%20Acronym.cpp)
// https://leetcode.com/discuss/interview-question/991036/Flipkart-or-OA-or-Special-substring/802613
// https://codeforces.com/blog/entry/83878

/*
Problem Statement
The Cytes Lottery is the biggest lottery in the world. On each ticket, there is a string of a-z letters. The company produces a draw string S. A person wins if his/her ticket string is a special substring of the draw string. A special substring is a substring which can be formed by ignoring at most K characters from drawString. For example, if draw string = "xyzabc" and tickets are [ac zb yhja] with K=1 then the winning tickets will be 2 i.e ac (won by ignoring "b" in drawstring) and zb (won by ignoring "a" in drawstring).
Now some people change their ticket strings in order to win the lottery. To avoid any kind of suspicion, they can make the following changes in their strings.
They can change character 'o' to character 'a' and vice versa They can change character 't' to character 'l' and vice versa They can erase a character from anywhere in the string Note that they can ignore at most 'K' characters from the draw string to get a match with the ticket string.
Write an algorithm to find the number of people who win the lottery (either honestly or by cheating).
Input:
The first line of the input consists of an integer — numTickets, representing the number of tickets (N). The second line consists of a string — drawString, representing the draw string (S). The third line consists of N space-seperated strings — tickets1, tickets2,........., ticketsN representing the tickets.
The last line consists of an integer-tolerance, representing the maximum number of characters that can be deleted from the drawString(K).
Output:
An integer representing the number of winning tickets (either fairly or by cheating).
Constraints:
0 <= numTickets <= 1000 0 <= length of drawString <= 200 0 <= length of tickets[i] <= 200 0 <= tolerance <= 1000 Note:
The drawString contains lowercase English alphabets
Example:
Input:
3 aabacd abcde aoc actld 1 Output:
2
*/



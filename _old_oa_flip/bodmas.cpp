#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string apply(string operator_Keyword,string op1,string op2)
{
	int a = stoi(op1), b = stoi(op2);
	return to_string("A" == operator_Keyword ? a + b : ("S" == operator_Keyword ? a - b : a * b));
}

vector<string> applyAll(vector<string> tokens, string operator_Keyword)
{
	vector<string> res;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (operator_Keyword == tokens[i])
		{
			res[res.size() - 1] = apply(operator_Keyword, res[res.size() - 1], tokens[++i]);
		}
		else
		{
			res.push_back(tokens[i]);
		}
	}
	return res;
}

int evaluate(vector<string> tokens, string order)
{
	for (int i = 0; i < order.length(); i++)
	{
		tokens = applyAll(tokens, order.substr(i, 1));
	}
	return stoi(tokens[0]);
}

vector<string> tokenize(string s)
{
	vector<string> res;
	string sb;
	for (auto c : vector<char>(s.begin(), s.end()))
	{
		if (c == '+' || c == '-' || c == '*')
		{
			res.push_back(sb);
			sb="";
			res.push_back(c == '+' ? "A" : (c == '-' ? "S" : "M"));
		}
		else
		{
			sb=sb+c;
		}
	}
	res.push_back(sb);
	return res;
}

int gradeMarks(string expression, vector<int> studentAnswers)
{
	vector<string> tokens = tokenize(expression);
	int correctAnswer = evaluate(tokens, "MAS");
	vector<string> incorrectOrders = {"MSA", "AMS", "ASM", "SAM", "SMA"};
	unordered_set<int> closeAnswers;
	for (auto order : incorrectOrders)
	{
		int answer = evaluate(tokens, order);
		if (answer != correctAnswer)
		{
			closeAnswers.insert(answer);
		}
	}
	int sum = 0;
	for (auto studentAnswer : studentAnswers)
	{
		sum += studentAnswer == correctAnswer ? 5 : (closeAnswers.find(studentAnswer)!=closeAnswers.end() ? 2 : 0);
	}
	return sum;
}

int main(){
	// n = 5
	// s = "15*4-3*2"
	// arr = [11,14,54,300,1000,0]
	// score(arr, s, n)
	vector<int> a={11,14,54,300,1000,0};
	cout<<gradeMarks("15*4-3*2",a);
	return 0;
}












// class Solution {
// 	private String apply(String operator, String op1, String op2) {
// 		int a = Integer.parseInt(op1), b = Integer.parseInt(op2);
// 		return String.valueOf("A".equals(operator) ? a + b : ("S".equals(operator) ? a - b : a * b));
// 	}
// 	private List<String> applyAll(List<String> tokens, String operator) {
// 		List<String> res = new ArrayList<>();
// 		for(int i = 0; i < tokens.size(); i++) {
// 			if(operator.equals(tokens.get(i))) {
// 				res.set(res.size() - 1, apply(operator, res.get(res.size() - 1), tokens.get(++i)));
// 			} else {
// 				res.add(tokens.get(i));
// 			}
// 		}
// 		return res;
// 	}
// 	private int evaluate(List<String> tokens, String order) {
// 		for(int i = 0; i < order.length(); i++) {
// 			tokens = applyAll(tokens, order.substring(i, i + 1));
// 		}
// 		return Integer.parseInt(tokens.get(0));
// 	}
// 	private List<String> tokenize(String s) {
// 		List<String> res = new ArrayList<>();
// 		StringBuilder sb = new StringBuilder();
// 		for(char c: s.toCharArray()) {
// 			if(c == '+' || c == '-' || c == '*') {
// 				res.add(sb.toString());
// 				sb.setLength(0);
// 				res.add(c == '+' ? "A" : (c == '-' ? "S" : "M"));
// 			} else {
// 				sb.append(c);
// 			}
// 		}
// 		res.add(sb.toString());
// 		return res;
// 	}
// 	public int gradeMarks(String expression, int[] studentAnswers) {
// 		List<String> tokens = tokenize(expression);
// 		int correctAnswer = evaluate(tokens, "MAS");
// 		String[] incorrectOrders = {"MSA", "AMS", "ASM", "SAM", "SMA"};
// 		Set<Integer> closeAnswers = new HashSet<>();
// 		for(String order: incorrectOrders) {
// 			int answer = evaluate(tokens, order);
// 			if(answer != correctAnswer) {
// 				closeAnswers.add(answer);
// 			}
// 		}
// 		int sum = 0;
// 		for(int studentAnswer: studentAnswers) {
// 			sum += studentAnswer == correctAnswer ? 5 : (closeAnswers.contains(studentAnswer) ? 2 : 0);
// 		}
// 		return sum;
// 	}
// }
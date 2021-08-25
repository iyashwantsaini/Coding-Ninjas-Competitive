class Solution {
	private String apply(String operator, String op1, String op2) {
		int a = Integer.parseInt(op1), b = Integer.parseInt(op2);
		return String.valueOf("A".equals(operator) ? a + b : ("S".equals(operator) ? a - b : a * b));
	}
	private List<String> applyAll(List<String> tokens, String operator) {
		List<String> res = new ArrayList<>();
		for(int i = 0; i < tokens.size(); i++) {
			if(operator.equals(tokens.get(i))) {
				res.set(res.size() - 1, apply(operator, res.get(res.size() - 1), tokens.get(++i)));
			} else {
				res.add(tokens.get(i));
			}
		}
		return res;
	}
	private int evaluate(List<String> tokens, String order) {
		for(int i = 0; i < order.length(); i++) {
			tokens = applyAll(tokens, order.substring(i, i + 1));
		}
		return Integer.parseInt(tokens.get(0));
	}
	private List<String> tokenize(String s) {
		List<String> res = new ArrayList<>();
		StringBuilder sb = new StringBuilder();
		for(char c: s.toCharArray()) {
			if(c == '+' || c == '-' || c == '*') {
				res.add(sb.toString());
				sb.setLength(0);
				res.add(c == '+' ? "A" : (c == '-' ? "S" : "M"));
			} else {
				sb.append(c);
			}
		}
		res.add(sb.toString());
		return res;
	}
	public int gradeMarks(String expression, int[] studentAnswers) {
		List<String> tokens = tokenize(expression);
		int correctAnswer = evaluate(tokens, "MAS");
		String[] incorrectOrders = {"MSA", "AMS", "ASM", "SAM", "SMA"};
		Set<Integer> closeAnswers = new HashSet<>();
		for(String order: incorrectOrders) {
			int answer = evaluate(tokens, order);
			if(answer != correctAnswer) {
				closeAnswers.add(answer);
			}
		}
		int sum = 0;
		for(int studentAnswer: studentAnswers) {
			sum += studentAnswer == correctAnswer ? 5 : (closeAnswers.contains(studentAnswer) ? 2 : 0);
		}
		return sum;
	}
}
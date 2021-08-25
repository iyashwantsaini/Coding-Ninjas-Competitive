allpath = [] # Storing all possible answers

def operation(sign,val1, val2):
    if sign == '+':return val1 + val2
    if sign == '-':return val1 - val2
    if sign == '*':return val1 * val2
    
def eveluate(expresionArray):
    res = 0
    while(len(expresionArray) > 2):
        valueOne = expresionArray.pop()
        sign = expresionArray.pop()
        valueTwo = expresionArray.pop()
        expresionArray.append(operation(sign, valueTwo, valueOne))
    if len(expresionArray) == 1:
        return expresionArray[0]
    return None

def recurr(st,i,curr):
    global allpath
    if i==len(st):
        allpath.append(eveluate([*curr]))
        return 
    if st[i] in ('+', '-', '*') or len(curr)== 0:
        curr.append(st[i])
        recurr(st,i+1, curr)
    elif(len(curr)>1 and curr[-1]  in ('+', '-', '*')):
        sign = curr.pop()
        val1 = curr.pop()
        ans = operation(sign, val1, st[i])
        recurr(st, i+1, curr + [ans])
        if i != len(st)-1:
            curr.append(val1)
            curr.append(sign)
            curr.append(st[i])
            recurr(st, i+1, curr)
            
    
def strToarray(string):
    temp_s = [*string]
    array = []
    pre = temp_s[0]
    for i in range(1,len(s)):
        if temp_s[i].isdigit():
            pre += temp_s[i]
        else:
            array.append(int(pre))
            array.append(temp_s[i])
            pre  =  ""
    if len(pre):
        array.append(int(pre))
    return array

def solve(s):
    st = strToarray(s)   #Conversition  "15*4-3*2" to [15, '*', 4 ,  '-'. 3, '*', 2]
    i,curr = 0,[]
    recurr(st,i,curr)

def score(arr, string, n):
    global allpath
    solve(string)
    correct = eval(string) [#Finding](https://leetcode.com/problems/finding-the-users-active-minutes) correct answer of expression
    print("correct answer: ", correct)
    d = Counter(allpath)
    ans = 0
    for res in arr:
        if res == correct:
            ans += 5
        elif(d[res]):
            ans += 2
    return ans
                
n = 5
s = "15*4-3*2"
arr = [11,14,54,300,1000,0]
score(arr, s, n)
/*
XML parse plus series computation

Evaluate an expression given in XML format. Keys will be Expr- contains the entire expression. Elem – contains the digit, sum, Prod- contains two or more keys whose evaluation needs to be summed or multiplied respectively. Sub will contain 2 keys or more, where the second key onwards will have to be subtracted from the first one. Div- will contain 2 keys in which first key will need to be divided by second.

SAMPLE INPUT:

<expr>

<sum>

<elem>4</elem>

<elem>6</elem>

<elem>7</elem>

<elem>3</elem>

</sum>

</expr>

SAMPLE OUTPUT:
20

EXPLANATION:

Input will be xml file through standard input. End of xml file marked by </expr>.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}


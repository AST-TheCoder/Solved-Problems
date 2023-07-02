#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1'00'000, "n"); inf.readSpace();
    int k = inf.readInt(1, 10'000, "k"); inf.readEoln();
 
    for (int i = 0; i < n; i++)
    {
        inf.readInt(1, 1'00'000, format("a[%d]", i));
 
        if (i + 1 < n)
            inf.readSpace();
    }
    inf.readEoln();
 
    inf.readEof();
}

/*
<#list 2..21 as s>
    gen1 2 ${s} > $
</#list>
<#list 22..41 as s>
    gen2 22 ${s} > $
</#list>
<#list 42..61 as s>
    gen3 42 ${s} > $
</#list>
<#list 62..81 as s>
    gen4 62 ${s} > $
</#list>
*/

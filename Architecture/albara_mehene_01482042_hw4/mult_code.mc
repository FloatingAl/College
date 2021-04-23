80:tir := tir + tir; if n then goto 110;          { 1111 1111 1x = DIV,HALT }
81:alu := tir + tir; if n then goto 103;          { 1111 1111 01 = RSHIFT }
82:a := lshift(1);                                { 1111 1111 00 = MULT }
83:a := lshift(a + 1);
84:a := lshift(a + 1);
85:a := lshift(a + 1);
86:a := lshift(a + 1);
87:a := a + 1;
88:b := band(ir, a);              { build 6 bit mask and put multiplier in b }
89:mar := sp; rd;
90:rd;
91:a := mbr;                          { get multiplicand (Mcnd) and put in a }
92:c := (-1);       { set c to -1, if it's still -1 at the end result is neg }
93:d := 0;                             { zero d, use as accumulating counter }
94:alu := a; if n then goto 97;                { if Mcnd is negative goto 97 }
95:c := c + 1; goto 97;             { if Mcnd is pos + 1 to c (c==0) goto 97 }
96:alu := c; if z then goto 100;      { if Mcnd is pos, this is OF, goto 100 }
97:b := b + (-1); if n then goto 101; { dec loop counter b, if done goto 101 }
98:d := d + a; if n then goto 96;  { add multiplicand to counter, OF goto 96 }
99:alu := c; if z then goto 97;        { if Mcnd is pos keep adding, goto 97 }
100:ac := (-1); goto 0;                 { OF error here, set AC = -1, return }
101:mar := sp; ac := 0;     { success AC = 0, replace Mcnd with sum on stack }
102:mbr := d; wr; goto 10;   { put sum into MBR and write, goto 10 to finish }


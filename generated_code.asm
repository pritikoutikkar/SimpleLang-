LOAD R1, 10      ; x = 10
LOAD R2, 5       ; y = 5
CMP R1, R2       ; if (x > y)
JLE ELSE_LABEL
SUB R1, R2       ; x = x - y
JMP END_IF
ELSE_LABEL:
SUB R2, R1       ; y = y - x
END_IF:
ADD R1, 1        ; x = x + 1
ADD R2, 1        ; y = y + 1
HALT

LOAD R1, 10      ; x = 10
STORE R1, x
LOAD R2, 5       ; y = 5
STORE R2, y
LOAD R1, x
LOAD R2, y
CMP R1, R2       ; if (x > y)
JLE ELSE_LABEL
SUB R1, R2       ; x = x - y
STORE R1, x
JMP END_IF
ELSE_LABEL:
LOAD R1, y
SUB R1, x        ; y = y - x
STORE R1, y
END_IF:
LOAD R1, x
ADD R1, 1        ; x = x + 1
STORE R1, x
LOAD R2, y
ADD R2, 1        ; y = y + 1
STORE R2, y
HALT

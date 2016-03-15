SMALL MACRO-EXPANDER WRITTEN IN LUA

LEGEND:
#: any alphanumeric, hexadecimal, or binary number
X: represent any string or block of strings
(): represents a block

RULES:
LEAVE SPACES BETWEEN EVERYTHING 

Repetiton: anytime TIMES is seen, prints X # of times
.TIMES # , X .ENDTIMES

Define: defines X as Y
.DEF X Y .ENDEF

Macro: creates macro X with arguments ... that inserts Y
.MAC X (..) Y .ENDMAC




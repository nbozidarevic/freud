grammar SimpleC;

program
  : Print+
  ;

Print
  : 'printf' '(' String ')' ';'
  ;

String
  : '"' Char* '"'
  ;

Char
  : ~["\\\r\n]
  ;

Whitespace
  : [ \t]+
    -> skip
  ;

Newline
  : ('\r'
  | '\n'
  | '\r\n')
    -> skip
;

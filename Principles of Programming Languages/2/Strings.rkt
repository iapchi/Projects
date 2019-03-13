(define (Handler node lineNumber)
  (cond
    ((equal? "S" (car node)) (set! lineNumber (handlerStatementNode node lineNumber)))
    ((equal? "W" (car node)) (set! lineNumber (handlerWhileNode node lineNumber)))
    (else (set! lineNumber (handlerTwoOperandNode node lineNumber))))
  lineNumber)

(define (handlerWhileNode node lineNumber)
  (define localIncrement lineNumber)
  (set! lineNumber (iterateList (car (cdr node)) lineNumber))
  (display lineNumber)
  (display ": bne $00000000")(newline)
  (set! lineNumber (+ 1 lineNumber))
  (set! lineNumber (iterateList (car (cdr (cdr node))) lineNumber))
  (display lineNumber)
  (display ": jmp $" )
  (display localIncrement)
  (set! lineNumber (+ 1 lineNumber)))

(define (handlerStatementNode node lineNumber)
  (set! lineNumber (iterateList (car (cdr node)) lineNumber))
  lineNumber)


(define (handlerTwoOperandNode node lineNumber)
  (define instruction (number->string lineNumber))
  (cond
    ((equal? "+" (car node)) (set! instruction (string-append instruction ": add")))
    ((equal? "-" (car node)) (set! instruction (string-append instruction ": sub")))
    ((equal? "*" (car node)) (set! instruction (string-append instruction ": mul")))
    ((equal? "/" (car node)) (set! instruction (string-append instruction ": div")))
    (else (display "Operation unsupported")))
  (set! instruction (string-append instruction " " (toStringOperand (car (cdr node)))))
  (set! instruction (string-append instruction "," (toStringOperand (car (cdr (cdr node))))))
  (display instruction)(newline)
  (set! lineNumber (+ 1 lineNumber))
  lineNumber)

(define (toStringOperand operand)
  (define operandValue "")
  (cond
    ((equal? "R" (car operand)) (set! operandValue (string-append operandValue "R")))
    ((equal? "A" (car operand)) (set! operandValue (string-append operandValue "$")))
    (else
     (display "Operand unsupported")))
  (set! operandValue (string-append operandValue (number->string (car (cdr operand)))))
  operandValue)

(define (iterateList List lineNumber)
  (cond
    ((not (null? List))
      (set! lineNumber (Handler (car List) lineNumber))
      (set! lineNumber (iterateList (cdr List) lineNumber))))
  lineNumber)

(define tree '("S" (
    ("-" ("A" 3333) ("A" 4444))
        ("W" (
          ("+" ("R" 0) ("R" 1))
          ("+" ("R" 1) ("R" 2))
          ("+" ("R" 2) ("R" 3))
          ("+" ("R" 3) ("R" 4))
          ("+" ("R" 4) ("R" 5)))
         (("-" ("R" 0) ("R" 1))
          ("-" ("R" 1) ("R" 2))
          ("-" ("R" 2) ("R" 3))
          ("-" ("R" 3) ("R" 4))
          ("-" ("R" 4) ("R" 5))
          ("-" ("A" 1000) ("A" 2000)))))))

(Handler tree 0)
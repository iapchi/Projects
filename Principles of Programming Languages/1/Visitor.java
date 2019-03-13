import java.util.*;

public class Visitor {

 public static void Visit(Node base) {
  StatementsNode root = (StatementsNode) base;
  
  HashMap<Character, String> charMap = new HashMap();
  charMap.put('+', "add");
  charMap.put('-', "sub");
  charMap.put('*', "mul");
  charMap.put('/', "div");
  
  recurse(root, 0, charMap);
 }

 private static void recurse(StatementsNode root, int i, HashMap cMap) {
  if (root.children.peek() == null) {
   return;
  }
  
  Node node = root.children.poll();
  
  
  switch (node.GetType()) {
  case 's':
   StatementsNode tmpS = (StatementsNode) node;
   break;
  case 'w':
   WhileNode tmpW = (WhileNode) node;
   int x = recurseWhile(tmpW, i, cMap);
   i += x;
   break;
  case '+':
  case '-':
  case '*':
  case '/':
   TwoOperandNode tmpT = (TwoOperandNode) node;
   System.out.print(i + ": " + cMap.get(node.GetType()) + " ");
   
   switch(tmpT.operand1.GetType()) {
   case 'R':
    System.out.print("R" + ((RegisterOperand) tmpT.operand1).GetRegister() + ",");
    break;
   case 'A':
    System.out.print("$" + ((AddressOperand) tmpT.operand1).GetAddress() + ",");
    break;
   default:
    System.out.println("Unknown operand type");  
   }
   
   switch(tmpT.operand2.GetType()) {
   case 'R':
    System.out.println("R" + ((RegisterOperand) tmpT.operand2).GetRegister());
    break;
   case 'A':
    System.out.println("$" + ((AddressOperand) tmpT.operand2).GetAddress());
    break;
   default:
    System.out.println("Unknown operand type");
   }
   
   break;
  default:
   System.out.println("Unknown node type");
  }   
  
  i++;
  
  recurse(root, i, cMap);
 }

 private static int recurseWhile(WhileNode tmpW, int i, HashMap cMap) {
  int a = tmpW.conditions.children.size();
  int b = tmpW.statements.children.size();
    
  processConditions(tmpW, i, cMap);
    
  System.out.println(i + a + ": bne $00000000");
  
  processStatements(tmpW, i + a + 1, cMap);
  
  System.out.println(i + a + b + 1 + ": jmp $" + i);
  
  return a + b;
   
 }

 private static void processStatements(WhileNode tmpW, int i, HashMap cMap) {
  if (!tmpW.statements.children.isEmpty()) {
   Node tmp = tmpW.statements.children.poll();
   processStatement(tmp, i, cMap);
   processStatements(tmpW, i + 1, cMap);
   return;
  }
  
 }

 private static void processConditions(WhileNode tmpW, int i, HashMap cMap) {
  if (!tmpW.conditions.children.isEmpty()) {
   Node tmp = tmpW.conditions.children.poll();
   processStatement(tmp, i, cMap);
   processConditions(tmpW, i + 1, cMap);
  }
  
  return;
  
 }

 private static void processStatement(Node tmp, int i, HashMap cMap) {
   TwoOperandNode tmpT = (TwoOperandNode) tmp;
   System.out.print(i + ": " + cMap.get(tmpT.GetType()) + " ");
   
   switch(tmpT.operand1.GetType()) {
   case 'R':
    System.out.print("R" + ((RegisterOperand) tmpT.operand1).GetRegister() + ",");
    break;
   case 'A':
    System.out.print("$" + ((AddressOperand) tmpT.operand1).GetAddress() + ",");
    break;
   default:
    System.out.println("Unknown operand type");  
   }
   
   switch(tmpT.operand2.GetType()) {
   case 'R':
    System.out.println("R" + ((RegisterOperand) tmpT.operand2).GetRegister());
    break;
   case 'A':
    System.out.println("$" + ((AddressOperand) tmpT.operand2).GetAddress());
    break;
   default:
    System.out.println("Unknown operand type");
   }
  
 }

}
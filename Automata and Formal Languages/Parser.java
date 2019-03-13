

package JsonValidator;

import java.util.LinkedList;


public class Parser {
    
    LinkedList<Token> tokens;
    Token currentToken;
    Token nextTok;
    
    public void parse(LinkedList<Token> toks){
        
        this.tokens = (LinkedList<Token>) toks.clone();
        nextTok = this.tokens.getFirst();
        
        if(jsonText()){
            System.out.println("JSON Accepted");
            
        }
        else{
            System.out.println("JSON Rejected");
                
            //for(Token t : tokens){
            //    System.out.print("TN:" + t.token + " " + t.sequence + " ");
            //}
            //System.out.println("");
        }
        
        if(nextTok.token != Token.EOF){
            throw new ParserException("Unexpected symbol found");
        }
    }
    
    
    private void nextToken(){
        
        tokens.pop();
        
        if(tokens.isEmpty()){
            nextTok = new Token(Token.EOF, "");
        }
        
        else{
            nextTok = tokens.getFirst();  
        }
    }
    
    private boolean jsonText(){
        if(value()){
            return nextTok.token == Token.EOF;
        }
        return false;
    }
    
    private boolean value(){
        if(jsonString()||
                jsonNumber()||
                object()||
                array()
                ){
            return true; 
        }
      
        if(nextTok.token == Token.TRUE ||
                nextTok.token == Token.FALSE||
                nextTok.token == Token.NULL){ 
            
            nextToken();
            return true;
        }
        
        return false;       
    }
    
    private boolean jsonString(){
        if(nextTok.token == Token.JSONSTRING){
            nextToken();
            return true;
        }
        else return false;
    }
    
    private boolean jsonNumber(){ 
       if(nextTok.token == Token.INTEGER_LEAD_ZERO ||
               nextTok.token == Token.INTEGER_NO_LEAD_ZERO){
           
           nextToken();
           if(nextTok.token == Token.FRAC){
               nextToken();
               if(nextTok.token == Token.EXP){
                   nextToken();
                   return true;
               }
           } else if(nextTok.token == Token.EXP){
               nextToken();
               return true;
           }
           return true;
       } else return false;
    }
    
   
    
    private boolean object(){
        if(nextTok.token == Token.OPEN_BRACE){
           nextToken();
           if(nextTok.token == Token.CLOSE_BRACE){
                nextToken();
                return true;
            }
           
            for( ; ; ){
                if(jsonString()){            
                    if(nextTok.token == Token.COLON){
                        nextToken();
                        if(value()){                
                            if(nextTok.token == Token.COMMA){
                                nextToken();  
                            } else break;
                        } else return false;
                    } else return false;
                } else return false;     
            }
        } else return false; 
        
        if(nextTok.token == Token.CLOSE_BRACE){
            nextToken();
            return true;
        }
        return false;
    }
    
    private boolean array(){
        if(nextTok.token == Token.OPEN_BRACKET){
            nextToken();
            
            if(nextTok.token == Token.CLOSE_BRACKET){
                nextToken();
                return true;
            }
            
            for(; ;){    
                if(value()){
                    if(nextTok.token == Token.COMMA){
                        nextToken(); 
                    } else break;
                } else return false;
            }
        } else return false;
        if(nextTok.token == Token.CLOSE_BRACKET){
            nextToken();
            return true;
        }
        return false;
    }
    
    
    
}

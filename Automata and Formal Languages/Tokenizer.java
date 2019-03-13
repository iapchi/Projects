
package JsonValidator;

import java.util.LinkedList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Tokenizer {
    
    private class TokenInfo {
        public final Pattern regex;
        public final int token;
        
        public TokenInfo(Pattern regex, int token){
            super();
            this.regex = regex;
            this.token = token;
        }
    }
   
  
    public Tokenizer(){
        tokenInfos = new LinkedList<TokenInfo>();
        tokens = new LinkedList<Token>();
    }
    
    
    private LinkedList<TokenInfo> tokenInfos;
    private LinkedList<Token> tokens;
    
    
    public void add(String regex, int token){
        tokenInfos.add(new TokenInfo(Pattern.compile("^("+regex+")"), token));
    }
    
    public void tokenize(String str){
        String s = str.trim();
        tokens.clear();
        
        while(!s.equals("")){
            boolean match = false;
            
            for(TokenInfo info : tokenInfos){
                Matcher m = info.regex.matcher(s);
                
                if(m.find()){
                    match = true;
                    
                    String tok = m.group().trim();
                    tokens.add(new Token(info.token, tok));
                    
                    s = m.replaceFirst("").trim();
                   
                    break;
                }
            }
            if (!match){
                //for(Token t : tokens){
                //    System.out.println(""+ t.token+  " " + t.sequence);
                //}
                throw new ParserException("JSON Rejected:Unexpected character(s) in input");
            }
        }
    }
    
    public LinkedList<Token> getTokens(){
        return tokens;
    }
}

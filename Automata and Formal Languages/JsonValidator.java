
package JsonValidator;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;


public class JsonValidator {
    
    public static void main(String[] args){
        System.out.println(args[0]);
        String path = args[0];
        String jsonText = null;
        
        try {
            jsonText = new String(Files.readAllBytes(Paths.get(path)));  
        } catch (IOException ex) {
            System.out.println(ex);
        }
        
        Tokenizer tokenizer = new Tokenizer();
       
        tokenizer.add("\\{", Token.OPEN_BRACE); // open brace
        tokenizer.add("\\}", Token.CLOSE_BRACE); // close brace
        tokenizer.add("\\[", Token.OPEN_BRACKET); // open bracket
        tokenizer.add("\\]", Token.CLOSE_BRACKET); // close bracket
        tokenizer.add("\\:", Token.COLON); // colon
        tokenizer.add("\\,", Token.COMMA); // comma
        
        //JSONstring
        tokenizer.add("\"(([^\\\\\\p{Cntrl}\"])|(\\\\([\"\\\\\\/bfnrt]|(u([0-9[a-fA-F]])+))))*\"", Token.JSONSTRING); 
        
        //tokenizer.add("\\-", 8); // - minus
        //tokenizer.add("[0]", 9); // zero
        //tokenizer.add("[1-9]", 10); // digit_1_9
        //tokenizer.add("[0-9]", 11); // digit
        //tokenizer.add("\\.", 12); // decimal point
        //tokenizer.add("[eE]", 13); // exp
        //tokenizer.add("\\+", 14); // plus
        
        
        tokenizer.add("true", Token.TRUE); // true 
        tokenizer.add("false", Token.FALSE); // false
        tokenizer.add("null", Token.NULL); // null
        
        //JSONnumber components
        tokenizer.add("([0]{1})|(\\-\\s*[0]{1})", Token.INTEGER_LEAD_ZERO); // zero
        tokenizer.add("([1-9][0-9]*)|(\\-\\s*[1-9][0-9]*)", Token.INTEGER_NO_LEAD_ZERO); //integer with no leading zero
        tokenizer.add("\\.[0-9]+", Token.FRAC); // frac
        tokenizer.add("([Ee][+-][0-9]+)|([Ee][0-9]+)", Token.EXP); // expression
        
        if(jsonText != null){
   
            try{
                tokenizer.tokenize(jsonText);
                Parser p = new Parser();
                
                p.parse(tokenizer.getTokens());
                
                //for(Token tok : tokenizer.getTokens()){
                //    System.out.println("" + tok.token + " " + tok.sequence);
                //}
            }
            catch(ParserException e){
                System.out.println(e.getMessage());
            }
        }
        
        else{
            System.out.println("JSON Rejected: NULL file");
        }
    }
}

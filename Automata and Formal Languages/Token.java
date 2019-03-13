
package JsonValidator;


public class Token {
    
    public static final int EOF = 0;
    public static final int OPEN_BRACE = 1;
    public static final int CLOSE_BRACE = 2;
    public static final int OPEN_BRACKET = 3;
    public static final int CLOSE_BRACKET = 4;
    public static final int COLON = 5;
    public static final int COMMA = 6;
    public static final int JSONSTRING = 7;
    public static final int INTEGER_NO_LEAD_ZERO = 8;
    
    //json
    
    public static final int FRAC = 9;
    public static final int EXP = 10;
    public static final int DIGIT = 11;
    public static final int DECIMALPOINT = 12;
    public static final int INTEGER_LEAD_ZERO = 13;
    public static final int TRUE = 15;
    public static final int FALSE = 16;
    public static final int NULL = 17;
    
    public final int token;
    public final String sequence;
    
    
    public Token(int token, String sequence){
        super();
        this.token = token;
        this.sequence = sequence;  
    }
    
}

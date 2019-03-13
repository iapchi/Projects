
/*
Jacky Li

http://52.10.187.66/Sorting
*/

// Import required java libraries
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.json.*;

// Extend HttpServlet class
public class Sorting extends HttpServlet {
  // Standard servlet method
  public void init() throws ServletException
  {
      // Do any required initialization here - likely none
  }
  // Standard servlet method - we will handle a POST operation
  public void doPost(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
  {
      doService(request, response);
  }
  // Standard servlet method - we will not respond to GET
  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
  {
      // Set response content type and return an error message
      response.setContentType("application/json");
      PrintWriter out = response.getWriter();
      out.println("{ 'message' : 'Use POST!'}");
  }
  // Our main worker method
  // Parses messages e.g. {"inList" : [5, 32, 3, 12]}
  // Returns the list sorted.
  private void doService(HttpServletRequest request,
                    HttpServletResponse response)
            throws ServletException, IOException
	{
				      // Get received JSON data from HTTP request
      BufferedReader br = new BufferedReader(new InputStreamReader(request.getInputStream()));
      String jsonStr = "";
      if(br != null){
				jsonStr = br.readLine();
			}
      // Create JsonReader object
      StringReader strReader = new StringReader(jsonStr);

      try { // Error Checking here
        JsonReader reader = Json.createReader(strReader);
        // Get the singular JSON object (name:value pair) in this message.
        JsonObject obj = reader.readObject();
        // From the object get the array named "inList"
        JsonArray inArray = obj.getJsonArray("inList");
        ArrayList<Integer> numberArray = new ArrayList<Integer>();
        if (inArray != null) {
           int len = inArray.size();
           for (int i=0;i<len;i++){
             numberArray.add(inArray.getInt(i));
           }
        }
// Doing the sorting and getting the response text here
        String result = sortingMain(numberArray); 
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(result); // Send the response to the client
      } catch (Exception e) {
        // Do this when an error is detected
        response.setContentType("application/json");
        String errorMessage = "{ \"Error\"	: \"Bad/Incorrect JSON\" } Example usage: {\"inList\" : [-3,-2,-1,0,1,2,3] }spaces in-between each number and only numbers allowed ";
        PrintWriter out = response.getWriter();
        out.println(errorMessage);
      }
	}

  // Standard Servlet method
  public void destroy()
  {
      // Do any required tear-down here, likely nothing.
  }

  public String sortingMain(ArrayList<Integer> int_list){
    //Calculation for time used (start time)
    long startTime = System.currentTimeMillis();
    int_list = quicksort(int_list);
    //Calculation for time used (end time)
    long endTime   = System.currentTimeMillis();
    long totalTime = endTime - startTime;
    String output = "{\"outList\" : "+int_list.toString()+",\n \"algorithm\" : \"quicksort\",\n"+
    "\"timeMS\" :" + totalTime;
    System.out.println(output);
    return output;
  }

  private static ArrayList<Integer> quicksort(ArrayList<Integer> input){
   if(input.size() <= 1){
    return input;
   }

   int middle = (int) Math.ceil((double)input.size() / 2);
   int pivot = input.get(middle);

   ArrayList<Integer> less = new ArrayList<Integer>();
   ArrayList<Integer> greater = new ArrayList<Integer>();

   for (int i = 0; i < input.size(); i++) {
    if(input.get(i) <= pivot){
     if(i == middle){
      continue;
     }
     less.add(input.get(i));
    }
    else{
     greater.add(input.get(i));
    }
   }
   return concatenate(quicksort(less), pivot, quicksort(greater));
  }
  private static ArrayList<Integer> concatenate(ArrayList<Integer> less, int pivot, ArrayList<Integer> greater){
    ArrayList<Integer> list = new ArrayList<Integer>();
    for (int i = 0; i < less.size(); i++) {
     list.add(less.get(i));
    }
    list.add(pivot);
    for (int i = 0; i < greater.size(); i++) {
     list.add(greater.get(i));
    }
    return list;
   }
}

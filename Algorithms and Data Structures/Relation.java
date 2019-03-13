

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.json.*;
import java.util.*;

// Extend HttpServlet class
public class relation extends HttpServlet {
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
	 String result = processInput(obj); // Main task heree
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(result);
		} catch (Exception e) {        // Do this when an error is detected
        response.setContentType("application/json");
        String errorMessage = "{ \"Message\"	: \"Malformed JSON\" }";
        PrintWriter out = response.getWriter();
        out.println(errorMessage);
      }
	}
  // Standard Servlet method
  public void destroy()
  {
      // Do any required tear-down here, likely nothing.
  }

  public String processInput(JsonObject obj) {
	JsonArray relList = obj.getJsonArray("inList");
	ArrayList<String> sortedList = new ArrayList<String>();
	for(int i =0; i<relList.size();i++) {
	      JsonObject obj2 = relList.getJsonObject(i); // Get the i'th relationship
	      JsonArray relation = obj2.getJsonArray("smarter");  // Get the relation 
	      addToList(sortedList, relation.getString(0), relation.getString(1));      
	}
	String str = String.join("\",\"",sortedList);
	return "{\"outList\":[\""+str+"\"]}";
  }
  
  public void addToList(ArrayList<String> arr, String smarter, String dumber) {
	  if (arr.indexOf(smarter) > -1) {
		 // Found smarter person in the list, just add dumber person to end
		  arr.add(dumber);
	  } else {
		  // Didn't find smarter, see if the dumber person is there
		  if (arr.indexOf(dumber) > -1) {
			  // Found dumber person in array, add smarter person just before the dumber person
			  arr.add(arr.indexOf(dumber), smarter); 
		  } else {
			  // didn't find dumber person in array, add them in order
			  arr.add(smarter);
			  arr.add(dumber);
		  }
	  }
  }
}


/*
Jacky Li

http://52.10.187.66/queue
*/
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.json.*;
import java.util.*;

// Extend HttpServlet class
public class queue extends HttpServlet {
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
	      JsonObject result = processQueue(obj); // See the implementation of this function below
        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        out.println(result.toString());
		} catch (Exception e) {        // Do this when an error is detected
        response.setContentType("application/json");
        String errorMessage = "{ \"Message\"	: \"Malformed JSON\" } Example usage: {\"inList\" : [ { “cmd” : “enqueue”, “name” : ”1”, “pri” : 1 }, ] }spaces in-between each number and only numbers allowed ";
        PrintWriter out = response.getWriter();
        out.println(errorMessage);
      }
	}
  // Standard Servlet method
  public void destroy()
  {
      // Do any required tear-down here, likely nothing.
  }

  public static Comparator<ElementWithPriority> priorityComparator = new Comparator<ElementWithPriority>(){
    @Override
    public int compare(ElementWithPriority c1, ElementWithPriority c2) {
            return (int) (c1.getPriority() - c2.getPriority());
        }
  };
  public JsonObject processQueue(JsonObject obj) {
    JsonArray queueList = obj.getJsonArray("inList");
    Queue<ElementWithPriority> jobPriorityQueue =  new PriorityQueue<ElementWithPriority>(7, priorityComparator); // Declaring a loval Queue since the footnote mentions the service is "Stateless"
    for(int i =0; i<queueList.size();i++) {
      JsonObject obj2 = queueList.getJsonObject(i); // Get the i'th member of the array
      String cmd = obj2.getString("cmd");  // Get the command
      if(cmd.compareTo("enqueue") == 0) { // If its an enqueue command, get the job name and priority
        String name = obj2.getString("name");
        int priority = obj2.getInt("pri");
        jobPriorityQueue.add(new ElementWithPriority(name, priority)); // add element to the queue
      } else if(cmd.compareTo("dequeue") == 0) { // if its the dequeue command, remove an element from the top of the queue
        jobPriorityQueue.poll();
      }
    } // finish processing the queue operations here

    // Now generate the output from the remaining queue
    JsonArrayBuilder resultArray = Json.createArrayBuilder();
    JsonObjectBuilder returnValue = Json.createObjectBuilder();
    while(true){
    ElementWithPriority elem = jobPriorityQueue.poll();
    if(elem == null) {
    break;
    } else {
    resultArray = resultArray.add(elem.getName());
}
}
return returnValue.add("outList",resultArray).build();
  }
}
class ElementWithPriority {
    String name;
    int priority;
    public ElementWithPriority(String name, int priority) {
        this.name = name;
        this.priority = priority;
    }
    public String getName() {
        return this.name;
    }

    public int getPriority() {
        return priority;
    }
}
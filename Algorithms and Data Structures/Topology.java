
import java.io.*;
import java.util.Collections;
import java.util.HashMap;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.json.*;

// Extend HttpServlet class
public class topology extends HttpServlet {
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
			String result = processData(obj);
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

	public String processData(JsonObject obj) {
		HashMap<String,Integer> nodeMap = new HashMap<String, Integer>();
		// Populating the Point Array
		JsonArray connections = obj.getJsonArray("inList");
		for(int i=0; i<connections.size();i++) {
			JsonArray connection = connections.getJsonObject(i).getJsonArray("connected");
			addConnection(nodeMap, connection.getString(0), connection.getString(1));
		}
		String result = analyzeMap(nodeMap);
		return "{\"type\":\"" + result+"\"}";
	}

	public void addConnection(HashMap<String, Integer> nodeMap, String node1, String node2) {
		int node1count = 0, node2count = 0;
		if(nodeMap.containsKey(node1)) {
			node1count = nodeMap.get(node1) + 1;
		}
		if(nodeMap.containsKey(node2)) {
			node2count = nodeMap.get(node2) + 1;
		}
		nodeMap.put(node1, node1count);
		nodeMap.put(node2, node2count);
	}
	public String analyzeMap(HashMap<String, Integer> nodeMap) {
		// IF all values are 2, return "ring"
		// If 2 values are 1 and rest are 2, return "bus"
		// If 1 value is N-1 and rest are 1 return "star"
		// Else return "irregular"
		int freq_of_2 = Collections.frequency(nodeMap.values(),2);
		if(freq_of_2 == nodeMap.size()) {
			return "ring";
		} else if(freq_of_2 == (nodeMap.size() - 2)){
			int freq_of_1 = Collections.frequency(nodeMap.values(),1);
			if(freq_of_1 == 2) {
				return "bus";
			} else {
				return "irregular";
			}
		} else {
			int freq_of_n_1 = Collections.frequency(nodeMap.values(), nodeMap.size() - 1);
			if(freq_of_n_1 == 1) {
				int freq_of_1 = Collections.frequency(nodeMap.values(),1);
				if(freq_of_1 == (nodeMap.size() - 1)) {
					return "star";
				} else {
					return "irregular";
				}
			} else {
				return "irregular";
			}
		} 


	}
}

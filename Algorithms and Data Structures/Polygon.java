
import java.io.*;
import java.util.ArrayList;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.json.*;

class Point {
	int x;
	int y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

// Extend HttpServlet class
public class polygon extends HttpServlet {
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
			String result = processPoints(obj);
			response.setContentType("application/json");
			PrintWriter out = response.getWriter();
			out.println(result);
		} catch (Exception e) {        // Do this when an error is detected
			response.setContentType("application/json");
			String errorMessage = "{ \"Message\": \"Malformed JSON\" }";
			PrintWriter out = response.getWriter();
			out.println(errorMessage);
		}
	}
	// Standard Servlet method
	public void destroy()
	{
		// Do any required tear-down here, likely nothing.
	}

	public String processPoints(JsonObject obj) {
		ArrayList<Point> pointArray = new ArrayList<Point>();
		// Populating the Point Array
		JsonArray pointList = obj.getJsonArray("inList");
		for(int i=0; i<pointList.size();i++) {
			JsonObject pnt = pointList.getJsonObject(i);
			pointArray.add(new Point(pnt.getInt("x"), pnt.getInt("y")));
		}
		int result = getNumberOfPointsInsidePolygon(pointArray);
		return "{\"count\":"+result+"}";
	}

	//utility function to find GCD of two numbers
	//GCD of a and b
	public int calcGCD(int a, int b)
	{
		if (b == 0)
			return a;
		return calcGCD(b, a % b);
	}

	public int getNumberOfPointsOnLine(Point p1, Point p2) {
		// Check if line parallel to axes
		if (p1.x == p2.x)
			return Math.abs(p1.y - p2.y) - 1;
		if (p1.y == p2.y)
			return Math.abs(p1.x - p2.x) - 1;

		return calcGCD(Math.abs(p1.x - p2.x), Math.abs(p1.y - p2.y)) - 1;
	}

	public double areaOfPolygon(ArrayList<Point> points) {
		// Using Shoelace formula for calculating area of polygon using vertices
		
		double area = 0.0;
		// Calculate value of shoelace formula
		int j = points.size() - 1;
		for (int i = 0; i < points.size(); i++)
		{	
			Point pi = points.get(i);
			Point pj = points.get(j);
			area += (pj.x + pi.x) * (pj.y - pi.y);
			j = i;  // j is previous vertex to i
		}

		// Return absolute value
		return Math.abs(area / 2.0);
	}

	public int getNumberOfPointsInsidePolygon(ArrayList<Point> points) {
		// 3 extra integer points for the vertices
		int boundaryPoints = 0;
		int j = points.size() - 1;
		for(int i = 0; i < points.size(); i++) {
			boundaryPoints+=getNumberOfPointsOnLine(points.get(i),points.get(j));
			j=i;
		}
		boundaryPoints+=points.size();

		// Calculate 2*A for the polygon
		int doubleArea = (int)(2*areaOfPolygon(points));

		// Use Pick's theorem to calculate the no. of Interior points
		return (doubleArea - boundaryPoints + 2)/2;
	}

}

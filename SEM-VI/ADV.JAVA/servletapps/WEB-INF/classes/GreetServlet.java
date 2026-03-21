import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class GreetServlet extends HttpServlet{
  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
    response.setContentType("text/html");
    PrintWriter out = response.getWriter();
    
    String name = request.getParameter("name");
    
    out.println("<html>");
    out.println("<body>");
    if (name != null && !name.isEmpty()){
    out.println("<h2> Hello, "+ name +"! </h2>");
    }else{
    out.println("<h2> Hello, Guest!</h2>");
    }
    out.println("</body>");
    out.println("</html>");
  }
}

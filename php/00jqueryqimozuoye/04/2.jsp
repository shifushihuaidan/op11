<%-- 
    Document   : 2
    Created on : 2014-12-28, 13:36:11
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    request.setCharacterEncoding("utf-8");
    String name1=request.getParameter("name1");
    String mima=request.getParameter("mima");
    if("海贼王".equals(name1)&&"123".equals(mima))
    {
        //session.setAttribute("aa",1);
        out.print("1");
    }
    else
    {
        //session.setAttribute("aa",0);
        out.print("0");
    }
%>

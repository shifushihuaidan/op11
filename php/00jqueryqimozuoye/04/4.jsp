<%-- 
    Document   : 4
    Created on : 2014-12-28, 13:58:37
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%
    int a=Integer.parseInt(request.getParameter("a"));
    int b=Integer.parseInt(request.getParameter("b"));
    int c=a+b;
    out.print(c);
%>

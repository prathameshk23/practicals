package com.example.pract5.app;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
  public static void main(String[] args) {
    ClassPathXmlApplicationContext context =
        new ClassPathXmlApplicationContext("beans.xml");
    MainApplication myApp = (MainApplication)context.getBean("myApp");
    myApp.processMessage("Hello World!!");
    context.close();
  }
}

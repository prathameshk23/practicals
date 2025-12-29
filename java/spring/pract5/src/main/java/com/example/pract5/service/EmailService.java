package com.example.pract5.service;

public class EmailService implements MessageService {
  @Override
  public void sendMessage(String message) {
    System.out.println("Email Sent: " + message);
  }
}

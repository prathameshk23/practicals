package com.example.pract5.app;

import com.example.pract5.service.MessageService;

public class MainApplication {
  private MessageService messageService;

  public void setMessageService(MessageService messageService) {
    this.messageService = messageService;
  }

  public void processMessage(String msg) { messageService.sendMessage(msg); }
}

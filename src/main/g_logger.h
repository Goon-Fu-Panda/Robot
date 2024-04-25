#ifndef g_logger_h
#define g_logger_h

class globale_logger {
  public:
    globale_logger();
    globale_logger(unsigned long UART_Speed);
    bool info(String invoer);
    bool warn(String invoer);
    bool error(String invoer);
    bool fatal(String invoer);

  private:
    bool logger(String level,String invoer);
};

#endif

/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: phát loa cảnh báo khi phát hiện có khí gas
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module còi buzzer
    - Module MQ-2 cảm biến khí gas như khí LPG có thành phần propane, khi Iso butan (C4H10), 
      khí Propan (C3H8), khí Metan (CH4), rượu (ROH), Hydrogen, Khói
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_11:_Analog%EF%BC%88MQ-2%EF%BC%89Sensor

   Hướng dẫn sử dụng công cụ Monitor trong Arduino IDE để xem số liệu qua cổng COM
   https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor      
**/


int MQ2 = A0; // Define MQ2 gas sensor pin at A0
int val = 0; // declare variable
int buzzer = 3; // Define the buzzer pin at D3


/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  pinMode (MQ2, INPUT); // MQ2 gas sensor as input
  Serial.begin (9600); // Set the serial port baud rate to 9600
  pinMode (buzzer, OUTPUT); // Set the digital IO pin mode for output
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  val = analogRead (MQ2); // Read the voltage value of A0 port and assign it to val
  Serial.println (val); // Serial port sends val value
  if (val> 450)  {
    tone (buzzer, 589);
    delay(300);
  }  else  {
    noTone (buzzer);
  }
}

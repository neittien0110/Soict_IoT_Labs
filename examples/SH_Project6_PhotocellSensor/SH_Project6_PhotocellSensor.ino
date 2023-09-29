/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: cảm biến ảnh sáng phát hiện có nguồn sáng mạnh chiếu vào thì đèn led sẽ sáng, và ngược lại
   Sử dụng ánh sáng từ đèn flash của điện thoại để chiếu vào module cảm biến ánh sáng
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module đèn led
    - Module cảm biến ánh sáng/photocell
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_6%EF%BC%9APhotocell_Sensor
**/


int LED = 5; // Set LED pin at D5
int val = 0; // Read the voltage value of the photodiode
             // and A1 pin connects to photocell module

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  pinMode (LED, OUTPUT); // LED is output
  Serial.begin (9600); // The serial port baud rate is set to 9600
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  val = analogRead (A1); // Read the voltage value of A1 Pin
  // Gửi kết quả về máy tính
  Serial.println(val);
  if (val <500)
  {// Less than 500, LED light is off
    digitalWrite (LED, LOW);
  }  else   {
    // Otherwise, the LED lights up
    digitalWrite (LED, HIGH);
  }
  delay (10); // Delay 10ms
}

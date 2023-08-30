/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: đo mức độ ẩm và gửi dữ liệu về máy tính qua cổng COM
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module cảm biến hơi nước / steam
    - Công cụ đọc dữ liệu cổng COM (xem link bên dưới)
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_9%EF%BC%9ASteam_Sensor
   Chú ý rằng ảnh chụp minh họa trong bài viết khi kết nối cổng COM là cổng COM3. Số hiệu này không
   cố định, có thể là COM5, COM6, COM11.. tùy theo từng máy tính

   Hướng dẫn sử dụng công cụ Monitor trong Arduino IDE để xem số liệu qua cổng COM
   https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor
**/

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  int val;
  val=analogRead(3); //plug vapor sensor into analog port 3
  Serial.print("Moisture is ");
  Serial.println(val,DEC); //read analog value through serial port printed
  delay(100); //delay 100ms
}

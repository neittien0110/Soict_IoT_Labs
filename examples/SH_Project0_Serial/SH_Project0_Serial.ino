/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: Đèn led sáng dần từ từ, tối dần từ từ.
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module led
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_2:_Breathing_Light
**/

/// Tên của người dùng, nhập qua serial
String name;

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
      // Thiết lập tốc độ truyền/nhận dữ liệu
      Serial.begin(9600);
      // Thiết bị IoT gửi một vài thông tin chào hỏi tới máy tính
      Serial.println("SOICT chào bạn");
      Serial.println("Bạn tên gì?");
      // Đợi cho tới khi người sử dụng gõ kí tự từ bàn phím
      while (Serial.available() == 0) {} 
      // Đọc tên người sử dụng qua cổng com
      name = Serial.readString();

      // Chào người dùng
      Serial.print("Chào ");
      Serial.println(name);

      Serial.println("Sau đây là liên tiêp 2 giá trị ngâu nhien. Hay mo cua so Tools/Serial Plotter de xem.");
      delay(1000);
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
* -----------------------------------------------------------------------------------------------
*/
void loop () {
   Serial.print(random(30,50));
   Serial.print(',');
   Serial.println(random(10,20));
}

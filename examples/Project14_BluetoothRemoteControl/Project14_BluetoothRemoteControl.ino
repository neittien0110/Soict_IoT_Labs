/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: đọc thông tin nhân được từ Bluetooth và trả về chính dòng thông tin đó
   cho thiết bị phát
   
   Lưu ý: Truyển dữ liệu không dây bằng Bluetooth và cổng COM là hoàn toàn giống nhau về khuôn dạng
   dữ liệu, chỉ khác biệt về phương thức truyền tin. Vì vậy có thể dễ dàng nhận ra rằng đoạn mã
   để trao đổi thông tin bằng cồng COM và Bluetooth là giống hệt nhau.
   
   Mở rộng: cổng COM là nói về cổng kết nối vật lý, còn giao thức truyển dữ liệu là UART. Như vậy có
   thể nói Bluetooth là chuẩn kết nối không dây cũng sử dụng giao thức truyền thông UART. Cùng sử 
   dụng giao thức truyền thông UART còn có phân biệt với khái niêm
   - TTL: 2 mức logic 0,1 tương ứng với 2 mức điện áp 0 - 5V hoặc 0-3.3V ==> phù hợp với điện áp của
     các bộ xử lý nên không cần mạch chuyển đổi phức tạp, nhưng nhược điểm là chỉ truyền cự li ngắn tầm 5 mét
   - RS232: 2 mức logic 0,1 tương ứng với 2 mức điện áp -12V và +12V hoặc -5V và 5V  ==> đòi hỏi bộ
     xử lý phải gắn thêm các module chuyển đổi điện áp như MAX232, nhưng ưu điểm là truyền xa tới 20 mét
   - RS485: 2 mức logic 0,1 tương ứng với hiệu điện thế giữa 2 dây vi sai ==> đòi hỏi phải bộ xử 
     lý phải gắn thêm module chuyển đổi như MAX485, nhưng ưu điểm là truyền xa tới 1000 mét
   
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module led
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   
**/

char val;

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  Serial.begin(9600);// Set the serial port baud rate to 9600
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  while (Serial.available()>0)  {
    val=Serial.read();// Read the value sent by Bluetooth
    Serial.print(val);// The serial port prints the read value
  }
}

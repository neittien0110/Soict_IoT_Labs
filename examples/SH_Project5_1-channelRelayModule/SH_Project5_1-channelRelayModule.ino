/**
   Trường Công nghệ Thông tin và Truyền thông, Đại học Bách Khoa Hà Nội
   Website: https://soict.hust.edu.vn
   
   Mô tả bài thực hành: tắt bật đèn led thông qua rơ-le/relay
   Gợi ý tìm hiểu: đèn led muốn sáng phải được cung cấp năng lượng. Ở bài lab trước,
   năng lượng cho bảng mạch Arduino cung cấp nên sẽ rất yếu. Trong trường hợp chúng ta muốn một dàn
   gồm nhiều đèn led, nhiều động cơ công suất lớn thì phải điều khiển gián tiếp chúng qua một thiết
   bị trung gian như là relay. Khi đó nguồn cấp cho đèn led hoặc các thiết bị khác sẽ là nguồn năng
   lượng ngoài, chứ không phải là do Arduino cung cấp nữa.
   Kit phát triển: 
    - Keyestudio smart home Kit for Arduino
    - Module nút bấm
    - Module đèn led
    - Module rơ le 1 kênh (1-channel relay)
   
   Nguồn tham khảo, hướng dẫn lắp đặt và giải thích chi tiết: 
   https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino#Project_4%EF%BC%9AControlling_LED_by_Button_Module
**/

int Relay = 12; // Define the relay pin at D12

/** 
 * -----------------------------------------------------------------------------------------------
 *     Khởi tạo các thiết lập ban đầu khi bo mạch khởi động
 * -----------------------------------------------------------------------------------------------
*/
void setup () {
  pinMode (13, OUTPUT); // Set Pin13 as output
  digitalWrite (13, HIGH); // Set Pin13 High
  pinMode (Relay, OUTPUT); // Set Pin12 as output
}

/** 
 * -----------------------------------------------------------------------------------------------
 *     Vòng lặp vô tận thực hiện chức năng chính
 * -----------------------------------------------------------------------------------------------
*/
void loop () {
  digitalWrite (Relay, HIGH); // Turn off relay
  delay (2000);
  digitalWrite (Relay, LOW); // Turn on relay
  delay (2000);
}

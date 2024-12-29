# Phần Mềm Xử Lý Ảnh C++

Phần mềm Xử Lý Ảnh C++ là một ứng dụng được xây dựng để thực hiện các thao tác cơ bản trên hình ảnh như đọc, chỉnh sửa, và lưu trữ hình ảnh với nhiều tính năng như chuyển đổi định dạng ảnh, thay đổi kích thước, điều chỉnh độ sáng, độ tương phản và áp dụng các bộ lọc cơ bản. Dự án sử dụng C++ và thư viện OpenCV để xử lý ảnh.

## Các Tính Năng Chính

### 1. Đọc và Hiển Thị Ảnh
- **Mở và đọc ảnh** từ các định dạng phổ biến như JPG, PNG, BMP, v.v.
- **Hiển thị ảnh** trên cửa sổ giao diện.

### 2. Chỉnh Sửa Ảnh
- **Thay đổi kích thước ảnh**: Cung cấp tùy chọn để thay đổi kích thước ảnh theo tỷ lệ hoặc độ phân giải mới.
- **Cắt ảnh**: Chọn và cắt một phần của ảnh theo hình chữ nhật.
- **Điều chỉnh độ sáng và độ tương phản**: Tăng hoặc giảm độ sáng và độ tương phản của ảnh.

### 3. Áp Dụng Bộ Lọc
- **Bộ lọc mờ**: Áp dụng bộ lọc mờ để làm mịn ảnh.
- **Bộ lọc cạnh**: Tăng cường các cạnh trong ảnh bằng bộ lọc Sobel hoặc Canny.


### 4. Chuyển Đổi Định Dạng
- **Chuyển đổi định dạng ảnh**: Lưu ảnh ở các định dạng khác nhau như JPG, PNG, BMP.

### 5. Lưu Ảnh
- **Lưu ảnh đã chỉnh sửa**: Lưu ảnh dưới các định dạng phổ biến sau khi chỉnh sửa.

## Yêu Cầu Hệ Thống

- **Ngôn ngữ lập trình**: C++
- **Hệ điều hành**: Windows

## Cài Đặt

### 1. Cài Đặt OpenCV
Trước khi biên dịch và chạy ứng dụng, bạn cần cài đặt OpenCV. Các bước cài đặt có thể khác nhau tùy vào hệ điều hành bạn đang sử dụng:

#### Trên Windows:
- Tải và cài đặt Qtcreater 


### 2. Clone Repository

Clone dự án từ GitHub về máy của bạn:
```bash
git clone https://github.com/ngokhaihuynh/ImageProcessing.git
cd image-processing-cpp

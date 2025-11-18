# BÁO CÁO BÀI TẬP LỚN: GAME FLAPPY BIRD

Đây là dự án game mô phỏng Flappy Bird được xây dựng bằng ngôn ngữ C++ và thư viện đồ họa SFML.

## 🎥 Demo Gameplay

Dưới đây là hình ảnh thực tế khi chạy game (Ảnh động):

![Demo Flappy Bird](Demo.gif)


## ℹ️ Thông tin chung
- **Môn học:** NGÔN NGỮ LẬP TRÌNH C++
- **Nhóm - Lớp:** 17-11

## 🛠️ Công nghệ sử dụng
- **Ngôn ngữ:** C++
- **Thư viện đồ họa:** SFML (Simple and Fast Multimedia Library)
- **IDE:** Code::Blocks

## 📂 Cấu trúc dự án
Mã nguồn được tổ chức theo cấu trúc tách biệt Header/Source để tối ưu quản lý:

```text
FlappyBird/
├── assets/          # Chứa tài nguyên hình ảnh (.png), âm thanh (.wav)
├── assetsmap/       # Chứa tài nguyên bản đồ (nếu có)
├── data/            # Chứa file cấu hình đường dẫn và lưu điểm cao (High Score)
├── include/         # Chứa các file tiêu đề (.h) - Định nghĩa Class
├── src/             # Chứa mã nguồn xử lý (.cpp) và file main.cpp
└── sfmll.cbp        # File quản lý dự án Code::Blocks (Project File)

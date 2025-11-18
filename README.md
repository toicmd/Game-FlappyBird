# BÁO CÁO BÀI TẬP LỚN: GAME FLAPPY BIRD

Đây là dự án game mô phỏng Flappy Bird được xây dựng bằng ngôn ngữ C++ và thư viện đồ họa SFML.

## 🏫 Thông tin chung
- **Môn học:** [TÊN_MÔN_HỌC_VÍ_DỤ_LẬP_TRÌNH_C++]
- **Giảng viên hướng dẫn:** [TÊN_THẦY_CÔ]
- **Nhóm-Lớp:** [TÊN_LỚP_HOẶC_SỐ_NHÓM]

## 👥 Thành viên nhóm thực hiện
| STT | Họ và tên | Mã sinh viên | Phân công công việc |
|:---:|:---:|:---:|:---|
| 1 | **[TÊN_BẠN]** | [MÃ_SV_CỦA_BẠN] | Code chính, Xử lý va chạm, Âm thanh |
| 2 | [TÊN_THÀNH_VIÊN_2] | [MÃ_SV] | Tìm hình ảnh, Làm slide báo cáo, Code menu |
| 3 | [TÊN_THÀNH_VIÊN_3] | [MÃ_SV] | Test game, Viết tài liệu |

*(Nếu làm một mình thì bạn xóa dòng thành viên 2, 3 đi và sửa cột Phân công thành "Thực hiện toàn bộ dự án")*

## 🛠️ Công nghệ sử dụng
- **Ngôn ngữ:** C++ (Standard 11+)
- **Thư viện đồ họa:** SFML (Simple and Fast Multimedia Library)
- **IDE phát triển:** Code::Blocks
- **Công cụ quản lý mã nguồn:** Git & GitHub

## 📂 Cấu trúc dự án
Mã nguồn được tổ chức theo cấu trúc tách biệt Header/Source để dễ quản lý:
```text
FlappyBird/
├── assets/          # Chứa tài nguyên game (Hình ảnh .png, Âm thanh .wav)
├── data/            # Chứa dữ liệu cấu hình và file lưu điểm cao (High Score)
├── include/         # Chứa các file tiêu đề (.h) - Định nghĩa Class
├── src/             # Chứa mã nguồn (.cpp) - Xử lý Logic
├── main.cpp         # Hàm main chính
└── sfmll.cbp        # File project Code::Blocks

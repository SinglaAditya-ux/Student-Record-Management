# 📚 Student Record Management

## Intern Details
| Field | Details |
|-------|---------|
| **Intern ID** | CITS3437 |
| **Full Name** | Aditya Singla |
| **No. of Weeks** | 4 Weeks (3rd June - 1st July) |
| **Project Name** | Student Record Management |
| **Company** | CodTech IT Solutions |

---

## 📌 Project Scope
A console-based Student Record Management System built in C language. It allows adding, viewing, searching, updating and deleting student records. Automatically calculates total marks, percentage and grade. All data is saved to a file for permanent storage.

---

## ✅ Features
- Add New Student Record
- View Student Details by Roll Number
- View All Students in Table Format
- Search Student by Name
- Update Student Record
- Delete Student Record
- Auto Calculate Percentage & Grade
- Data saved using File Handling

---

## 📊 Grading System
| Percentage | Grade |
|-----------|-------|
| 90% and above | A |
| 75% - 89% | B |
| 60% - 74% | C |
| 45% - 59% | D |
| Below 45% | F |

---

## 🛠️ Technologies Used
- Language: C
- Concepts: Structs, File Handling, Arrays, Functions, String Operations

---

## ▶️ How to Run

### Compile
```bash
gcc student_record.c -o student_record
```

### Run
```bash
./student_record
```
On Windows:
```bash
student_record.exe
```

---

## 📋 Sample Output
```
==============================================
   WELCOME TO STUDENT RECORD MANAGEMENT     
   Aditya Singla | CITS3437                 
==============================================

========== MAIN MENU ==========
1. Add New Student
2. View Student Record
3. View All Students
4. Search Student
5. Update Student Record
6. Delete Student Record
7. Exit
================================
```

---

## 📁 Project Structure
```
Student-Record-Management/
├── student_record.c      # Main source code
├── students.dat          # Data file (auto-created)
├── screenshots/          # Output screenshots
└── README.md             # Project documentation
```

---

## 📝 Notes
- Roll numbers start from 101
- Marks are out of 100 for each subject
- Total marks calculated out of 300
- Data auto-saves after every operation

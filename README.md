# E-Gradebook

**E-Gradebook** is a C++ console application that simulates an electronic gradebook system. It allows for the management of students, subjects, and grades via a command-line interface. All data is saved in binary files and loaded automatically on startup.

## Features

- Specialized collection classes for:
  - **Students**
  - **Subjects**
  - **Grades**
- Students and subjects are automatically **sorted alphabetically** by name.
- Support for:
  - Adding, editing, and deleting students and subjects
  - Assigning and managing grades
  - Viewing all data through custom commands
- All user input is handled through a centralized **Command Pattern** architecture.
- **Binary file persistence** for:
  - `studentsData.bin`
  - `subjectsData.bin`
  - `gradesData.bin`

## Architecture

- `StudentCollection`, `SubjectCollection`, and `GradeCollection` manage dynamic arrays of entities.
- Sorting is done after each modification for easy lookup and consistent order.
- The **Command Pattern** is used to decouple command parsing from execution.
- Data is persisted across sessions using **binary files**.

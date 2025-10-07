#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    for(int i = idx; i < num_of_students; i++) {
        students[i] = students[i + 1];
    }
    num_of_students--;
    
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());

    if(idx >= 0) {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int i = 0; i < num_of_students; i++) {
        if(students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int BestMidtermIdx = 0;

    for(int i = 1; i < num_of_students; i++) {
        int BestMidterm = students[BestMidtermIdx].getRecord().getMidterm();
        int currentMideterm = students[i].getRecord().getMidterm();
        if(currentMideterm > BestMidterm) {
            BestMidtermIdx = i;
        }
    }
    return students[BestMidtermIdx].getID();
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int BestFinalIdx = 0;

    for(int i = 1; i < num_of_students; i++) {
        int BestFinal = students[BestFinalIdx].getRecord().getFinal();
        int currentFinal = students[i].getRecord().getFinal();
        if(currentFinal > BestFinal) {
            BestFinalIdx = i;
        }
    }
    return students[BestFinalIdx].getID();
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int BestTotalIdx = 0;

    for(int i = 1; i < num_of_students; i++) {
        int BestTotal = students[BestTotalIdx].getRecord().getTotal();
        int currentTotal = students[i].getRecord().getTotal();
        if(currentTotal > BestTotal) {
            BestTotalIdx = i;
        }
    }
    return students[BestTotalIdx].getID();
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum_of_midterm = 0;
    for(int i = 0; i < num_of_students; i++) {
        sum_of_midterm += students[i].getRecord().getMidterm();
    }
    return sum_of_midterm / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum_of_final = 0;
    for(int i = 0; i < num_of_students; i++) {
        sum_of_final += students[i].getRecord().getFinal();
    }
    return sum_of_final / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum_of_total = 0;
    for(int i = 0; i < num_of_students; i++) {
        sum_of_total += students[i].getRecord().getTotal();
    }
    return sum_of_total / num_of_students;
}


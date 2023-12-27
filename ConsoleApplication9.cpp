#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>

// Функция для инициализации векторов
void initializeVectors(std::vector<std::string>& names, std::vector<int>& grades) {
    int choice;
    std::cout << "Выберите способ инициализации векторов:" << std::endl;
    std::cout << "1. Демонстрационные значения" << std::endl;
    std::cout << "2. Случайные значения" << std::endl;
    std::cout << "3. Ввод значений от пользователя" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        // Демонстрационные значения
        names = { "Иван", "Мария", "Александр", "Екатерина", "Дмитрий", "Анна", "Алексей", "София", "Михаил", "Анастасия" };
        grades = { 80, 70, 90, 85, 95, 75, 85, 80, 90, 85 };
        break;
    }
    case 2: {
        // Случайные значения
        int size;
        std::cout << "Введите желаемый размер выборки: ";
        std::cin >> size;

        // Генерация случайных имен
        std::vector<std::string> allNames = { "Иван", "Мария", "Александр", "Екатерина", "Дмитрий", "Анна", "Алексей", "София", "Михаил", "Анастасия" };
        std::random_shuffle(allNames.begin(), allNames.end());
        names = std::vector<std::string>(allNames.begin(), allNames.begin() + size);

        // Генерация случайных оценок
        std::vector<int> allGrades = { 60, 65, 70, 75, 80, 85, 90, 95, 100 };
        std::random_shuffle(allGrades.begin(), allGrades.end());
        grades = std::vector<int>(allGrades.begin(), allGrades.begin() + size);

        break;
    }
    case 3: {
        // Ввод значений от пользователя
        int size;
        std::cout << "Введите желаемый размер выборки: ";
        std::cin >> size;

        std::cout << "Введите имена студентов: " << std::endl;
        for (int i = 0; i < size; i++) {
            std::string name;
            std::cin >> name;
            names.push_back(name);
        }

        std::cout << "Введите оценки студентов: " << std::endl;
        for (int i = 0; i < size; i++) {
            int grade;
            std::cin >> grade;
            grades.push_back(grade);
        }

        break;
    }
    default:
        std::cout << "Неверный выбор!" << std::endl;
        break;
    }
}

// Функция вывода содержимого векторов с использованием range-based for-loop
void printVectorsRangeBased(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Имена: ";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    std::cout << "Оценки: ";
    for (const auto& grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

// Функция вывода содержимого векторов с использованием итератора
void printVectorsIterator(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Имена: ";
    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Оценки: ";
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
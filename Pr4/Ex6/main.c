#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];  // Рядок для імені мережі
    struct utsname uts;  // Структура для інформації про комп'ютер

    // Отримуємо ім'я мережі комп'ютера
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Ім'я мережі комп'ютера: %s\n", hostname);
    } else {
        perror("Помилка отримання імені мережі");
        return 1;
    }

    // Отримуємо докладну інформацію про комп'ютер за допомогою uname
    if (uname(&uts) == 0) {
        printf("Докладна інформація про комп'ютер:\n");
        printf("Система: %s\n", uts.sysname);
        printf("Версія: %s\n", uts.release);
        printf("Видання: %s\n", uts.version);
        printf("Машина: %s\n", uts.machine);
    } else {
        perror("Помилка отримання інформації про комп'ютер");
        return 1;
    }

    return 0;
}
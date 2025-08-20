# CTF Challenge - Buffer Overflow 1

## 📌 Informasi Challenge
- **Judul** : Buffer Overflow Level 1 (bof1)
- **Kategori** : Pwn / Binary Exploitation
- **Level** : Dasar (Beginner)
- **File** : `bof1.c`
- **Arsitektur** : 32-bit
- **Proteksi Binary** :
  - `-fno-stack-protector` → Stack protector dimatikan
  - `-z execstack` → Stack dapat dieksekusi
  - `-no-pie` → Alamat fungsi tetap (tidak random)
  - **ASLR** : Tergantung sistem (bisa dinonaktifkan untuk latihan)

---

## 📂 Source Code
```c
// bof1.c - Basic Buffer Overflow Level 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win() {
    printf("You called win()! But this isn't the flag ;)\n");
    exit(0);
}

void vuln() {
    char buf[32];

    printf("Input: ");
    gets(buf);  // vulnerable function
    printf("You entered: %s\n", buf);
}

int main() {
    vuln();
    printf("Done.\n");
    return 0;
}

```
---

⚙️ Cara Compile

Kamu bisa compile dengan GCC (32-bit mode) menggunakan perintah:

gcc -m32 -fno-stack-protector -z execstack -no-pie bof1.c -o bof1

Atau gunakan target install dari Makefile:

make install


---

🎯 Tujuan Challenge

Challenge ini melatih buffer overflow dasar dengan tujuan:

1. Memahami fungsi rentan seperti gets().


2. Mengeksploitasi buffer overflow untuk mengubah alur eksekusi program.


3. Menjalankan fungsi tersembunyi win() melalui teknik overwrite return address.


4. Sebagai pengantar sebelum ke level buffer overflow yang lebih kompleks.

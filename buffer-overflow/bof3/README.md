# CTF Challenge - Buffer Overflow 3

## 📌 Informasi Challenge
- **Judul** : Buffer Overflow Level 3 (bof3)
- **Kategori** : Pwn / Binary Exploitation
- **Level** : Menengah → Lanjutan
- **File** : `bof3.c`
- **Arsitektur** : 32-bit
- **Proteksi Binary** :
  - `-fno-stack-protector` → Stack protector dimatikan
  - `-z execstack` → Stack dapat dieksekusi
  - `-no-pie` → Alamat fungsi tetap (tidak random)
  - **ASLR** : Bisa diaktifkan/dinonaktifkan sesuai kebutuhan latihan

---

## 📂 Source Code
```c
// bof3.c - Buffer Overflow Level 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void win(int x) {
    if (x == 0xdeadbeef) {
        printf("Congrats! You triggered win() with the right argument.\n");
        system("/bin/sh");
    } else {
        printf("win() called, but wrong argument: 0x%x\n", x);
    }
}

void vuln() {
    char buf[32];

    puts("Level 3: Let's see if you can pass the right value.");
    printf("Input: ");
    fgets(buf, 128, stdin);
    printf("You said: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Exiting normally...");
    return 0;
}

```
---

⚙️ Cara Compile

Kompilasi binary 32-bit:

gcc -m32 -fno-stack-protector -z execstack -no-pie bof3.c -o bof3

Atau gunakan target install dari Makefile:

make install


---

🎯 Tujuan Challenge

Level ini lebih tricky dibanding bof1 dan bof2, karena:

1. Eksploitasi buffer overflow tetap digunakan untuk overwrite return address.


2. Kali ini, fungsi win() membutuhkan argumen khusus (0xdeadbeef).


3. Peserta harus membuat payload yang:

Mengarahkan eksekusi ke fungsi win().

Mengatur nilai argumen pada stack sesuai dengan yang diharapkan (0xdeadbeef).



4. Jika berhasil, win() akan menjalankan shell /bin/sh.




---

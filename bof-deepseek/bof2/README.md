# CTF Challenge - Buffer Overflow 2

## 📌 Informasi Challenge
- **Judul** : Buffer Overflow Level 2 (bof2)
- **Kategori** : Pwn / Binary Exploitation
- **Level** : Menengah (Intermediate)
- **File** : `bof2.c`
- **Arsitektur** : 32-bit
- **Proteksi Binary** :
  - `-fno-stack-protector` → Stack protector dimatikan
  - `-z execstack` → Stack dapat dieksekusi
  - `-no-pie` → Alamat fungsi tetap (tidak random)
  - **ASLR** : Tergantung sistem (disarankan nonaktif untuk latihan)

---

## 📂 Source Code
```c
// bof2.c - Buffer Overflow Level 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    system("/bin/sh");
}

void vuln() {
    char buf[40];

    puts("Let's see if you're ready for round 2.");
    printf("Input: ");
    fgets(buf, 200, stdin);  // fgets used instead of gets
    printf("You typed: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Bye.");
    return 0;
}

```
---

⚙️ Cara Compile

Kompilasi dengan GCC (32-bit mode):

gcc -m32 -fno-stack-protector -z execstack -no-pie bof2.c -o bof2

Atau gunakan make install jika Makefile tersedia:

make install


---

🎯 Tujuan Challenge

Level ini melanjutkan dari bof1 dengan sedikit peningkatan kesulitan:

1. Fungsi rentan sekarang menggunakan fgets(), tetapi tetap rawan karena input buffer lebih besar (200) dibandingkan ukuran buffer (40).


2. Peserta harus menemukan cara untuk menimpa return address meskipun tidak menggunakan gets().


3. Mengeksploitasi overflow agar eksekusi dialihkan ke fungsi win().


4. Fungsi win() memberikan akses shell (/bin/sh) sebagai reward.



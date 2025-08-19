# CTF Challenge - Buffer Overflow 4

## 📌 Informasi Challenge
- **Judul** : Buffer Overflow Level 4 (bof4)
- **Kategori** : Pwn / Binary Exploitation
- **Level** : Lanjutan (Advanced)
- **File** : `bof4.c`
- **Arsitektur** : 32-bit
- **Proteksi Binary** :
  - `-fstack-protector` → **Stack Canary diaktifkan**
  - `-no-pie` → Alamat fungsi tetap
  - **NX / DEP** : Tidak dimatikan, stack tetap non-eksekusi
  - **ASLR** : Bergantung sistem (bisa dinonaktifkan untuk debugging)

---

## 📂 Source Code
```c
// bof4.c - Buffer Overflow Level 4 (32-bit, Stack Canary)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    printf("Congrats, you bypassed the canary!\n");
    system("/bin/sh");
}

void vuln() {
    char buf[64];
    puts("Level 4: Canary is enabled. Can you bypass it?");
    printf("Input: ");
    fgets(buf, 256, stdin);
    printf("You said: %s\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    puts("Exiting...");
    return 0;
}

```
---

⚙️ Cara Compile

Kompilasi dengan GCC (32-bit, stack protector aktif):

gcc -m32 bof4.c -o bof4 -fstack-protector -no-pie

Atau gunakan make install:

make install


---

🎯 Tujuan Challenge

Level ini memperkenalkan Stack Canary, mekanisme proteksi tambahan terhadap buffer overflow.
Tujuan peserta:

1. Memahami bagaimana stack canary bekerja untuk mendeteksi buffer overflow.


2. Menemukan cara membaca atau melewati canary agar tetap bisa overwrite return address.


3. Mengeksploitasi overflow untuk memanggil fungsi win().


4. Jika berhasil, program memberikan akses shell /bin/sh.




---

🚀 Langkah Lanjut

Jalankan binary dengan gdb/pwndbg.

Cari tahu letak stack canary di stack.

Lakukan leak canary value (misalnya lewat format string, buffer leak, atau teknik lain jika challenge menyediakan jalannya).

Buat payload dengan format:

[padding sampai canary]
[canary asli]
[padding setelah canary]
[alamat fungsi win()]

Jika payload benar, win() akan dipanggil tanpa trigger stack smashing detection.



---

📖 Hint

Stack Canary biasanya berupa nilai acak yang ditempatkan sebelum saved EBP dan return address.

Jika canary berubah (tidak cocok dengan nilai aslinya), program akan crash dengan error *** stack smashing detected ***.

Cari cara untuk leak nilai canary sebelum menimpa return address.

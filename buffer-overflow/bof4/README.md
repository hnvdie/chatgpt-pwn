🎯 Tujuan CTF bof4

Level ini ngenalin proteksi stack canary di buffer overflow.
Bedanya sama level sebelumnya:

Sebelum return address, ada nilai rahasia (canary).

Kalau lo overwrite buffer sampai ke return address TANPA nulis canary yg benar → program detect → segfault/terminate.

Tujuan lo:

Leak nilai stack canary (biasanya lewat format string bug / info leak yang sengaja disediain).

Setelah tau nilai canary, bikin payload:

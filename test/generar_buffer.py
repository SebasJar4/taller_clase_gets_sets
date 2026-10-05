import random
import sys

def generar_bytes(n):
    if n < 2:
        raise ValueError("n debe ser como mínimo 2")

    caracteres = [i for i in range(1, 256) if i != 0x0A]

    datos = bytes(random.choice(caracteres) for _ in range(n - 2))
    return datos + b'\n\x00'

n = 100
generado = generar_bytes(n)

with open("output_py.bin", "wb") as file:
    file.write( generado )


sys.stdout.buffer.write( generado )

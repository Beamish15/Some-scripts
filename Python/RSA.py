import math
#RSA Decrypt with only d

# Put your numbers below
n = 340282366920938460843936948965011886881
e = 65537
p = 18446744073709551533 # Prime num p
q = 18446744073709551557  # Prime num d
    
# 2. Calculate phi(n)
phi = (p - 1) * (q - 1)

# 3. Calculate the private exponent (d) using inverse modular
# pow(e, -1, phi) calc (e^-1) mod phi
d = pow(e, -1, phi)

print(f"p = {p}")
print(f"q = {q}")
print(f"phi(n) = {phi}")
print(f"Private exponent (d) = {d}")

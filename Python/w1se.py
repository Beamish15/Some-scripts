hex_cipher = "CYPHER_TEXT_HERE"
c = bytes.fromhex(hex_cipher)

# 'THM{' has 4 bytes, we need to find the 5th byte of the key
known_prefix = b'THM{'

# Derive the first 4 bytes of the key by XORing the known prefix with the ciphertext
key_4bytes = [c[i] ^ known_prefix[i] for i in range(4)]

# 256 possible values for the last byte of the key
for last_byte in range(256):
    full_key = bytes(key_4bytes + [last_byte])
    
    # Decrypt the ciphertext using the full key
    p = bytes([c[i] ^ full_key[i % len(full_key)] for i in range(len(c))])
    
    # Check if the decrypted plaintext starts with 'THM{' and ends with '}'
    # ASCII values only
    if p.startswith(b'THM{') and p.endswith(b'}'):
        print(f"[+] Clave encontrada: {full_key.decode(errors='ignore')}")
        print(f"[+] Flag 1: {p.decode(errors='ignore')}")
        break
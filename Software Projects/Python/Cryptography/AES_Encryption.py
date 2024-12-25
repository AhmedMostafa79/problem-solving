from Crypto.Cipher import AES
import binascii
class AES_Cipher:
    def __init__(self, key_hex):
        if len(key_hex) != 32:
            raise ValueError("Key must be 32 hexadecimal characters (128 bits)")
        self.key = binascii.unhexlify(key_hex)
        self.cipher = None

    def encrypt(self, message_hex):
        # Initialize cipher
        self._initialize_cipher()
        # Convert message from hexadecimal to bytes
        message = binascii.unhexlify(message_hex)
        # Ensure the message length is a multiple of the block size
        if len(message) % AES.block_size != 0:
            raise ValueError("Message length must be a multiple of AES block size (16 bytes)")
        # Encrypt the message
        cipher_text = self.cipher.encrypt(message)
        # Convert ciphertext to hexadecimal
        cipher_text_hex = binascii.hexlify(cipher_text).decode()
        return cipher_text_hex
    
    def decrypt(self, cipher_text_hex):
        # Initialize cipher
        self._initialize_cipher()
        # Convert ciphertext from hexadecimal to bytes
        cipher_text = binascii.unhexlify(cipher_text_hex)
        # Decrypt the ciphertext
        decrypted_message = self.cipher.decrypt(cipher_text)
        # Return decrypted message as hexadecimal
        return binascii.hexlify(decrypted_message).decode()

    def _initialize_cipher(self):
        if not self.cipher:
            self.cipher = AES.new(self.key, AES.MODE_ECB)  # ECB mode doesn't require an IV

#lab's test 
#key= 5468617473206D79204B756E67204675
#text=54776F204F6E65204E696E652054776F
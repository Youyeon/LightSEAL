#include <seal/seal.h>
#include <iostream>

#include "../examples/examples.h"

using namespace std;
using namespace seal;

int main(void) {
    EncryptionParameters parms(scheme_type::ckks);

    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, { 60, 40, 40, 60 }));

    double scale = pow(2.0, 40);

    SEALContext context(parms);
    print_parameters(context);
    cout << endl;

    KeyGenerator keygen(context);
    auto secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);
    RelinKeys relin_keys;
    keygen.create_relin_keys(relin_keys);
    Encryptor encryptor(context, public_key);
    Decryptor decryptor(context, secret_key);

    CKKSEncoder encoder(context);
    size_t slot_count = encoder.slot_count();
    cout << "Number of slots: " << slot_count << endl;

    cout << "Encryption Start" << endl;
    Plaintext plain;
    encoder.encode(5, scale, plain);
    Ciphertext cipher;
    encryptor.encrypt(plain, cipher);
    cout << "Encryption End" << endl;

    cout << "Decryption Start" << endl;
    Plaintext plain_result;
    decryptor.decrypt(cipher, plain_result);
    vector<double> result;
    encoder.decode(plain_result, result);
    cout << "Decryption result:" << endl;
    print_vector(result, 3, 7);

    SecretKey* keypointer;
    keypointer = &secret_key;
    cout << keypointer << endl;
}
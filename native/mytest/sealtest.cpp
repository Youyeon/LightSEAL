#include <seal/seal.h>
#include <iostream>

#include "../examples/examples.h"
#include <chrono>

using namespace std;
using namespace seal;
using namespace std::chrono;

int main(void) {
    system_clock::time_point begin, end;
    EncryptionParameters parms(scheme_type::ckks);
    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, { 60, 40, 40, 60 }));

    double scale = pow(2.0, 40);
    SEALContext context(parms);
    print_parameters(context);
    cout << endl;

    begin = system_clock::now();
    KeyGenerator keygen(context);
    auto secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);
    end = system_clock::now();
    duration<double> time = end - begin;
    cout << ">>> pk sk Generation Time: " << time.count() << " sec" << endl;

    Encryptor encryptor(context, public_key);
    Decryptor decryptor(context, secret_key);
    CKKSEncoder encoder(context);

    cout << "Encryption Start" << endl;
    Plaintext plain;
    Ciphertext cipher;
    begin = system_clock::now();
    encoder.encode(5, scale, plain);
    encryptor.encrypt(plain, cipher);
    end = system_clock::now();
    time = end - begin;
    cout << ">>> Encode + Encrypt Time: " << time.count() << " sec" << endl;
    cout << "Encryption End" << endl;

    cout << "Size of Ciphertext: " << cipher.size() << endl;

    cout << "Decryption Start" << endl;
    Plaintext plain_result;
    vector<double> result;
    begin = system_clock::now();
    decryptor.decrypt(cipher, plain_result);
    encoder.decode(plain_result, result);
    end = system_clock::now();
    time = end - begin;
    cout << ">>> Decrypt + Decode Time: " << time.count() << " sec" << endl;
    cout << "Decryption End" << endl;

    cout << "Decryption result:" << endl;
    print_vector(result, 3, 7);

}